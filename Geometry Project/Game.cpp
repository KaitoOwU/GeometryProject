#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	gameState = new GAMESTATE;
	(*gameState) = GAMESTATE::MENUOPEN;
	ui = new UserInterface(this);
	renderWindow = window;
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

		auto it = pPlayer->projectileList.begin();
		while (it != pPlayer->projectileList.end()) {
			window.draw((*it)->shape);
			it++;
		}
		ui->DisplayGUI(window);
		return;
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

		auto it = pPlayer->projectileList.begin();
		while (it != pPlayer->projectileList.end()) {
			(*it)->shape.move(((*it)->direction) / 4.f);
			(*it)->lifeDuration -= deltaTime;
			if ((*it)->lifeDuration <= 0) {
				it = pPlayer->projectileList.erase(it);
				continue;
			}
			it++;
		}
		return;
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
	std::cout << "Jeu lance" << std::endl;
}

void Game::CloseGame()
{
	renderWindow->close();
}

void Game::PauseGame()
{
	//pInputManager->inputs[sf::Keyboard::Key::Escape] = false;
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
	//A FAIRE
	*gameState = MENUOPEN;
}

void Game::UpgradePlayer(UPGRADES upgrade)
{
	switch (upgrade)
	{
	case SPEED:
		break;
	case DAMAGE:
		break;
	case HEALTH:
		break;
	case MUTATION:
		break;
	default:
		break;
	}
}
