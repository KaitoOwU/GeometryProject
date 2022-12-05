#pragma once
#include "Health.h"
#include "CharacterStats.h"
#include <SFML/Graphics.hpp>



class Enemy
{
public:
	Enemy();
	Enemy(float size, sf::Vector2f spawnPoint, sf::Color color,int numberOfSides, float maxHealth, float moveSpeed, float attackSpeed, float damage);
	~Enemy();

	Health pEnemyHealth;
	CharacterStats pEnemyStats;
	sf::CircleShape shape;
private:

};