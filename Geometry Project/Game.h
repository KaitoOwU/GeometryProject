#pragma once
#include "SFML/Graphics.hpp"
#include "EnemyManager.h"
#include "InputManager.h"
#include "ParticleSystem.h"
#include "Player.h"
#include "Enemy.h"
#include "UserInterface.h"
#include <list>

enum GAMESTATE
{
	MENUOPEN,
	PLAYING,
	PAUSE,
	UPGRADING,
	DEATH,
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
	UserInterface* ui;
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
	void Death();
	void OpenUpgradeMenu();
	void ApplyGUIChanges();
	void EnemyTakingDamage(sf::Vector2f enemyPosition);
	void HeroTakingDamage();
	void UpdateAllParticleSystems(float& deltaTime);
	void DisplayAllParticleSystems(sf::RenderWindow& window);
	float* score;
	GAMESTATE* gameState;
	Player* pPlayer;
	EnemyManager* pEnemyManager;
	InputManager* pInputManager;
	ExpManager* pExpManager;
	sf::RenderWindow* renderWindow;
	std::list<ParticleSystem> allParticlesSystems;

private:
};

