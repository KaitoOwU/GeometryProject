#pragma once

#include "Player.h"
#include <list>
#include <SFML/Graphics.hpp>
#include <map>

class InputManager {
public:
	InputManager(Player* pPlayer);
	
	void PressKey(sf::Event& event);
	void ReleaseKey(sf::Event& event);
	void UpdatePlayer();
	std::map<sf::Keyboard::Key, bool> inputs;

private:
	Player* pPlayer;
};
