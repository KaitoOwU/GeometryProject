#include "Game.h"

Game::Game()
{
	(*gameState) = GAMESTATE::MENUOPEN;
	ui = new UserInterface();
}

Game::~Game()
{
}

void Game::Display(sf::RenderWindow& window)
{
	//Display all object before the UI to make them appear beneath it

	ui->DisplayUI(window);
}

void Game::Update(float& deltaTime)
{
	//Ajouter ICI toutes les fonctions de rafraichissement du jeu
	switch (*gameState)
	{
	case PLAYING:
		return;
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
	*ui->_isMainMenuDisplayed = false;
	*gameState = GAMESTATE::PLAYING;
	std::cout << "CA MARCHE" << std::endl;
}
