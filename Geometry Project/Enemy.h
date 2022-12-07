#pragma once
#include "Health.h"
#include "CharacterStats.h"
#include "ExpManager.h"
#include <SFML/Graphics.hpp>

class ExpManager;
class EnemyManager;

class Enemy
{
public:
	Enemy(float size, sf::Vector2f spawnPoint,int numberOfSides, float maxHealth, float moveSpeed, float attackSpeed, float damage, ExpManager* pExpManager, EnemyManager* pEnemyManager);
	~Enemy();

	void EnemyDeath();

	Health pEnemyHealth;
	CharacterStats pEnemyStats;
	ExpManager* pExpManager = nullptr;
	EnemyManager* pEnemyManager = nullptr;
	sf::CircleShape shape;
private:

};