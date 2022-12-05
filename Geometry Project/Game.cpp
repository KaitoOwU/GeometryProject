#include "Game.h"

Game::Game()
{
	gameState = new GAMESTATE;
	(*gameState) = GAMESTATE::MENUOPEN;
	ui = new UserInterface(this);
}

Game::~Game()
{
	delete ui;
	delete gameState;
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
	*gameState = GAMESTATE::PLAYING;
	std::cout << "Jeu lance" << std::endl;
}
