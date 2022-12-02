#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Display(sf::RenderWindow& window)
{
	//Display all object before the UI to make them appear beneath it

	ui.DisplayUI(window);
}
