#include "InputManager.h"

InputManager::InputManager(Player* pPlayer)
{
	this->pPlayer = pPlayer;
}

void InputManager::Input(sf::Event& event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Z:
		pPlayer->Move(Player::MovementDirection::Up);
		return;
	case sf::Keyboard::Q:
		pPlayer->Move(Player::MovementDirection::Left);
		return;
	case sf::Keyboard::S:
		pPlayer->Move(Player::MovementDirection::Down);
		return;
	case sf::Keyboard::D:
		pPlayer->Move(Player::MovementDirection::Right);
		return;
	case sf::Keyboard::Space:
		//SHOOT
		return;
	}
}
