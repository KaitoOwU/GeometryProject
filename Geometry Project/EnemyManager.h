#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
#include "AllData.h"

class EnemyManager
{
public:
	EnemyManager(sf::RenderWindow* window, ExpManager* pExpManager);
	~EnemyManager();

	std::list<Enemy> enemyList;
	std::vector<Enemy> enemyPrefab;

	std::vector < sf::Color> enemyColor = { sf::Color::Blue,sf::Color::Magenta,sf::Color::Cyan,sf::Color::Yellow, sf::Color::White };
	sf::RenderWindow* activeWindow = nullptr;
	ExpManager* pExpManager = nullptr;

	bool canSpawn = true;

	float currentWaveTime = 0.f;
	int initEnemyWave = 2;
	float enemyMultiplicator = 1.5f;
	int maxEnemyPerWave = 20;
	float maxTime = 30;
	bool init = true;

	void OnPlayerDeath(Player *player);
	void EnemyManagerUpdate(Player *player, float &deltaTime);
	void SpawnEnemy(int amount);
	void DrawEnemy();
	void WaveManager(float& deltaTime);

private:

};