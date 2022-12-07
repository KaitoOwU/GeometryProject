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

	std::vector < sf::Vector2f> spawnPoints = {{0,0}, {1000,1000}, {1000,0}, {0,1000}, {500,0}, {0,500}, {1000,500}, {500,1000}};
	std::vector < sf::Color> enemyColor = { sf::Color::Blue,sf::Color::Magenta,sf::Color::Cyan,sf::Color::Yellow, sf::Color::White };
	sf::RenderWindow* activeWindow = nullptr;
	ExpManager* pExpManager = nullptr;

	bool canSpawn = true;

	void OnPlayerDeath(Player *player);
	void TrackPlayer(Player *player, float &deltaTime);
	void SpawnEnemy(int amount);
	void DrawEnemy();

private:

};