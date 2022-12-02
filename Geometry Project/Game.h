#pragma once
#include "SFML/Graphics.hpp"
#include "EnemyManager.h"
#include "InputManager.h"
#include "ParticleSystem.h"
#include "Player.h"
#include "UserInterface.h"

class Game
{
public:
	Game();
	~Game();
	void Display(sf::RenderWindow& window);

private:
	UserInterface ui;
};

