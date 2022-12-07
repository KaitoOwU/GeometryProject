#pragma once
#include "AllData.h"
#include <SFML/Graphics.hpp>

class PlayerCircleProjectile {
public:
	PlayerCircleProjectile(sf::Vector2f& direction, float* deltaTime);
	~PlayerCircleProjectile();

	sf::CircleShape shape;
	sf::Vector2f direction;
	float lifeDuration = 5.0f;

private:
	float* deltaTime;
};

class PlayerTriangleProjectile {
public:
	PlayerTriangleProjectile(float* deltaTime);
	~PlayerTriangleProjectile();

	sf::CircleShape shape;
	sf::Vector2f direction = { 0, 0 };
	float health = 20.f;

private:
	float* deltaTime;
};
