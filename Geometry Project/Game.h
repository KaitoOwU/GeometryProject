#pragma once
#include "SFML/Graphics.hpp"
#include "EnemyManager.h"
#include "InputManager.h"
#include "ParticleSystem.h"
#include "Player.h"
#include "UserInterface.h"

enum GAMESTATE
{
	PLAYING,
	MENUOPEN,
	PAUSE,
};

class Game
{
public:
	Game();
	~Game();
	void Display(sf::RenderWindow& window);
	void Update(float& deltaTime);
	UserInterface ui;

private:
	GAMESTATE gameState;
};

