#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	gameState = new GAMESTATE;
	(*gameState) = GAMESTATE::MENUOPEN;
	ui = new UserInterface(this);
	renderWindow = window;
	pPlayer = new Player(25, 200, { 400, 300 }, sf::Color::Red, window);
	pEnemyManager = new EnemyManager(window);
	pInputManager = new InputManager(pPlayer);
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

		break;
	}
	case GAMESTATE::PLAYING:
	{
		pEnemyManager->DrawEnemy();
		pPlayer->Display(window);
		pPlayer->DisplayProjectile(window);

		break;
	}
	case GAMESTATE::UPGRADING:
	{

		break;
	}
	case GAMESTATE::PAUSE:
	{

		break;
	}
	default:
	{
		break;
	}
	}
	ui->DisplayUI(window);
	
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
	std::cout << "Jeu lance" << std::endl;
}