#pragma once
#include "SFML/Graphics.hpp"
#include "EnemyManager.h"
#include "InputManager.h"
#include "ParticleSystem.h"
#include "Player.h"
#include "Enemy.h"
#include "UserInterface.h"

enum GAMESTATE
{
	MENUOPEN,
	PLAYING,
	PAUSE,
	UPGRADING,
};

class Game
{
public:
	UserInterface* ui = nullptr;
	Game();
	~Game();
	void Display(sf::RenderWindow& window);
	void Update(float& deltaTime);
	void LaunchGame();
	GAMESTATE* gameState;

private:
};

