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

enum UPGRADES {
	SPEED,
	DAMAGE,
	HEALTH,
	MUTATION,
};

class Game
{
public:
	UserInterface* ui = nullptr;
	Game(sf::RenderWindow* window);
	~Game();
	void Display(sf::RenderWindow& window);
	void Update(float& deltaTime);
	void LaunchGame();
	void CloseGame();
	void PauseGame();
	void ResetGame();
	void UpgadeSpeed();
	void UpgadeDamage();
	void UpgadeHealth();
	void Mutate();
	void UpgradePlayer(UPGRADES upgrade);
	GAMESTATE* gameState;
	Player* pPlayer;
	EnemyManager* pEnemyManager;
	InputManager* pInputManager;
	sf::RenderWindow* renderWindow;

private:
};

