#pragma once

#include "Player.h"
#include <SFML/Graphics.hpp>

class InputManager {
public:
	InputManager(Player* pPlayer);
	void Input(sf::Event& event);

private:
	Player* pPlayer;
};
