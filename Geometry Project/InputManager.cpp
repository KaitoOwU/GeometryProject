#include "InputManager.h"
#include "Game.h"

InputManager::InputManager(Game* game)
{
	pPlayer = game->pPlayer;
	pGame = game;
}

void InputManager::PressKey(sf::Event& event, float& deltaTime)
{
	if (event.key.code == sf::Keyboard::Z ||
		event.key.code == sf::Keyboard::Q ||
		event.key.code == sf::Keyboard::S ||
		event.key.code == sf::Keyboard::D ||
		event.key.code == sf::Keyboard::Space) {
		this->inputs[event.key.code] = true;
	}
}

void InputManager::ReleaseKey(sf::Event& event, float& deltaTime)
{
	if (event.key.code == sf::Keyboard::Z ||
		event.key.code == sf::Keyboard::Q ||
		event.key.code == sf::Keyboard::S ||
		event.key.code == sf::Keyboard::D ||
		event.key.code == sf::Keyboard::Space) {
		this->inputs[event.key.code] = false;
	}
	if (event.key.code == sf::Keyboard::Escape)
	{
		pGame->PauseGame();
	}
}