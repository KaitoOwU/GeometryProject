#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
#include "AllData.h"

class EnemyManager
{
public:
	EnemyManager(sf::RenderWindow &window);
	~EnemyManager();

	std::list<Enemy> enemyList;
	sf::RenderWindow* activeWindow = nullptr;

	void SpawnEnemy(int amount);
	void TrackPlayer(Player *player, float &deltaTime);
	void DrawEnemy();

private:

};