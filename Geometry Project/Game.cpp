#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	gameState = new GAMESTATE;
	(*gameState) = GAMESTATE::MENUOPEN;
	renderWindow = window;
	score = new float(0.f);
	pPlayer = new Player(25, 200, { 400, 300 }, sf::Color::Red, window);
	pExpManager = new ExpManager(window);
	pEnemyManager = new EnemyManager(window, pExpManager);
	pInputManager = new InputManager(this);
	ui = new UserInterface(this);
	allParticlesSystems.clear();
}

Game::~Game()
{
	delete ui;
	delete gameState;
	delete pPlayer;
	delete pEnemyManager;
	delete pInputManager;
	delete score;
}

void Game::Display(sf::RenderWindow& window)
{
	//Display all object before the UI to make them appear beneath it
	switch (*gameState)
	{
	case GAMESTATE::MENUOPEN:
	{
		ui->DisplayMainMenu(window);
		break;
	}
	case GAMESTATE::PLAYING:
	{
		//ORDER IN LAYER depending of the order of these functions
		pExpManager->DrawExperience();
		pEnemyManager->DrawEnemy();
		pPlayer->Display(window);
		pPlayer->DisplayProjectile(window);
		DisplayAllParticleSystems(window);
		ui->DisplayGUI(window);
		break;
	}
	case GAMESTATE::UPGRADING:
	{
		ui->DisplayUpgradeMenu(window);
		break;
	}
	case GAMESTATE::PAUSE:
	{
		ui->DisplayPauseMenu(window);
		break;
	}
	case GAMESTATE::DEATH:
	{
		ui->DisplayDeathMenu(window);
		break;
	}
	default:
	{
		break;
	}
	}
}

void Game::Update(float& deltaTime)
{
	//Ajouter ICI toutes les fonctions de rafraichissement du jeu
	switch (*gameState)
	{
	case PLAYING: {
		pEnemyManager->TrackPlayer(pPlayer, deltaTime);
		pExpManager->ExpTrackPlayer(pPlayer, deltaTime);

		pPlayer->Move(pInputManager->inputs, deltaTime);
		pPlayer->shootCooldown -= deltaTime;
		pPlayer->Shoot(pInputManager->inputs, deltaTime);
		UpdateAllParticleSystems(deltaTime);
		pPlayer->UpdateProjectile(deltaTime);
	}
	case MENUOPEN:
		return;
	case PAUSE:
		return;
	default:
		return;
	}
}

void Game::LaunchGame()
{
	*gameState = GAMESTATE::PLAYING;
	ApplyGUIChanges();
}

void Game::CloseGame()
{
	renderWindow->close();
}

void Game::PauseGame()
{
	switch (*gameState)
	{
	case PLAYING:
		*gameState = PAUSE;
		return;
	case PAUSE:
		*gameState = PLAYING;
		ApplyGUIChanges();
		return;
	default:
		return;
	}
}

void Game::ResetGame()
{
	delete pPlayer;
	delete pEnemyManager;
	*score = 0;
	pPlayer = new Player(25, 200, { 400, 300 }, sf::Color::Red, renderWindow);
	pEnemyManager = new EnemyManager(renderWindow, pExpManager);
	*gameState = MENUOPEN;
	allParticlesSystems.clear();
}

void Game::UpgadeSpeed()
{
	UpgradePlayer(UPGRADES::SPEED);
}

void Game::UpgadeDamage()
{
	UpgradePlayer(UPGRADES::DAMAGE);
}

void Game::UpgadeHealth()
{
	UpgradePlayer(UPGRADES::HEALTH);
}

void Game::Mutate()
{
	UpgradePlayer(UPGRADES::MUTATION);
}

void Game::UpgradePlayer(UPGRADES upgrade)
{
	*gameState = GAMESTATE::PLAYING;
	sf::Color color;
	//Insert upgrade function here (KEVIN)
	switch (upgrade)
	{
	case SPEED:
		std::cout << "Speed upgraded" << std::endl;
		pPlayer->speedMultiplier *= 1.05f;
		color = sf::Color::Yellow;
		break;
	case DAMAGE:
		std::cout << "Damage upgraded" << std::endl;
		pPlayer->damageMultiplier *= 1.05f;
		color = sf::Color::Blue;
		break;
	case HEALTH:
		std::cout << "Health upgraded" << std::endl;
		pPlayer->maxHealth += 25;
		pPlayer->health += 25;
		color = sf::Color::Green;
		break;
	case MUTATION:
		std::cout << "Mutation" << std::endl;
		pPlayer->MutateToNextState();
		color = sf::Color::Magenta;
		break;
	default:
		break;
	}
	allParticlesSystems.push_back(ParticleSystem(UPGRADE, pPlayer->shape.getPosition()
		+ sf::Vector2f{ pPlayer->shape.getRadius(), pPlayer->shape.getRadius() },
		sf::Vector2f{ 0.f, -1.f }, color));
	ApplyGUIChanges();
}

void Game::Death()
{
	*gameState = DEATH;
	ui->UpdateScore(score);
}

void Game::OpenUpgradeMenu()
{
	*gameState = GAMESTATE::UPGRADING;
	ui->UpdateUpgradeMenu();
}

void Game::ApplyGUIChanges()
{
	ui->UpdateGUI(pPlayer->health, pPlayer->maxHealth, pPlayer->currentXP,
		pPlayer->xpRequired[pPlayer->currentLvl], pPlayer->currentLvl, score);
	if (true)
	{
		
	}
}

void Game::TakeDamage()
{
	allParticlesSystems.push_back(ParticleSystem(PLAYER_DAMAGE, pPlayer->shape.getPosition() 
		+ sf::Vector2f{pPlayer->shape.getRadius(), pPlayer->shape.getRadius()}));
}

void Game::UpdateAllParticleSystems(float& deltaTime)
{
	std::list<ParticleSystem>::iterator it = allParticlesSystems.begin();
	while (it != allParticlesSystems.end())
	{
		if (it->IsAllParticlesEmpty())
		{
			it = allParticlesSystems.erase(it);
		}
		else
		{
			it->UpdateParticleSystem(deltaTime);
			it++;
		}
	}
}

void Game::DisplayAllParticleSystems(sf::RenderWindow& window)
{
	std::list<ParticleSystem>::iterator it = allParticlesSystems.begin();
	while (it != allParticlesSystems.end())
	{
		it->DisplayParticleSystem(window); 
		it++;
	}
}
