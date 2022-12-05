#pragma once
#include "Health.h"
#include "CharacterStats.h"
#include <SFML/Graphics.hpp>



class Enemy
{
public:
	Enemy(float size, sf::Vector2f spawnPoint, sf::Color color, float maxHealth, float moveSpeed, float attackSpeed, float damage);
	~Enemy();

	Health* pEnemyHealth = nullptr;
	CharacterStats* pEnemyStats = nullptr;
	sf::CircleShape shape;
private:

};