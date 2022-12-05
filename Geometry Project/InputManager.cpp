#include "InputManager.h"

InputManager::InputManager(Player* pPlayer)
{
	this->pPlayer = pPlayer;
}

void InputManager::PressKey(sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Z ||
		event.key.code == sf::Keyboard::Q ||
		event.key.code == sf::Keyboard::S ||
		event.key.code == sf::Keyboard::D ||
		event.key.code == sf::Keyboard::Space) {
		this->inputs[event.key.code] = true;

	}
	if (inputs[sf::Keyboard::Space]) {
		pPlayer->Shoot();
	}
	pPlayer->Move(this->inputs);
}

void InputManager::ReleaseKey(sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Z ||
		event.key.code == sf::Keyboard::Q ||
		event.key.code == sf::Keyboard::S ||
		event.key.code == sf::Keyboard::D ||
		event.key.code == sf::Keyboard::Space) {
		this->inputs[event.key.code] = false;
	}
	pPlayer->Move(this->inputs);
}