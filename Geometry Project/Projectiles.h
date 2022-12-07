#pragma once
#include "AllData.h"
#include <SFML/Graphics.hpp>
#include "EnemyManager.h"

class EnemyManager;

class PlayerCircleProjectile {
public:
	PlayerCircleProjectile(sf::Vector2f& direction, float* deltaTime, EnemyManager* pEnemyManager);
	~PlayerCircleProjectile();

	void DetectHit(EnemyManager* pEnemyManager);

	sf::CircleShape shape;
	sf::Vector2f direction;
	float lifeDuration = 5.0f;
	EnemyManager* pEnemyManager = nullptr;

private:
	float* deltaTime;
};

class PlayerTriangleProjectile {
public:
	PlayerTriangleProjectile(float* deltaTime, EnemyManager* pEnemyManager);
	~PlayerTriangleProjectile();

	void DetectHit(EnemyManager* pEnemyManager);

	sf::CircleShape shape;
	sf::Vector2f direction = { 0, 0 };
	float health = 20.f;
	EnemyManager* pEnemyManager = nullptr;

private:
	float* deltaTime;
};
