#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
#include "AllData.h"

class EnemyManager
{
public:
	EnemyManager(sf::RenderWindow* window);
	~EnemyManager();

	std::list<Enemy> enemyList;
	std::vector < sf::Vector2f> spawnPoints = {{0,0}, {1000,1000}, {1000,0}, {0,1000}, {500,0}, {0,500}, {1000,500}, {500,1000}};
	std::list<Enemy> enemyPrefab;
	sf::RenderWindow* activeWindow = nullptr;

	bool canSpawn = true;

	void SpawnEnemy(int amount);
	void TrackPlayer(Player *player, float &deltaTime);
	void OnPlayerDeath(Player *player);
	void DrawEnemy();

private:

};