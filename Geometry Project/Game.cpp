#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	gameState = new GAMESTATE;
	(*gameState) = GAMESTATE::MENUOPEN;
	ui = new UserInterface(this);
	renderWindow = window;
	score = new float(0.f);
	pPlayer = new Player(25, 200, { 400, 300 }, sf::Color::Red, window);
	pEnemyManager = new EnemyManager(window);
	pInputManager = new InputManager(this);
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
		pEnemyManager->DrawEnemy();
		pPlayer->Display(window);
		pPlayer->DisplayProjectile(window);
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

		pPlayer->Move(pInputManager->inputs, deltaTime);
		pPlayer->shootCooldown -= deltaTime;
		pPlayer->Shoot(pInputManager->inputs, deltaTime);
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
	//ui->UpdateGUI(pPlayer->health, pPlayer->maxHealth, 
	//pPlayer->currentXP, pPlayer->xpforNextLevel, pPlayer->currentLevel, score);
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
	pEnemyManager = new EnemyManager(renderWindow);
	*gameState = MENUOPEN;
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
	//Insert upgrade function here (KEVIN)
	switch (upgrade)
	{
	case SPEED:
		std::cout << "Speed upgraded" << std::endl;
		break;
	case DAMAGE:
		std::cout << "Damage upgraded" << std::endl;
		break;
	case HEALTH:
		std::cout << "Health upgraded" << std::endl;
		break;
	case MUTATION:
		std::cout << "Mutation" << std::endl;
		break;
	default:
		break;
	}
}

void Game::Death()
{
	*gameState = DEATH;
	ui->UpdateScore(score);
}
