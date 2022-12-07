#pragma once
#include "Player.h"
#include <list>
#include <SFML/Graphics.hpp>
#include <map>

class Game;

class InputManager {
public:
	InputManager(Game* game);
	void PressKey(sf::Event& event, float& deltaTime);
	void ReleaseKey(sf::Event& event, float& deltaTime);
	std::map<sf::Keyboard::Key, bool> inputs;

private:
	Player* pPlayer;
	Game* pGame;
};