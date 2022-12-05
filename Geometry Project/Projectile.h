#pragma once
#include "AllData.h"
#include <SFML/Graphics.hpp>

class Projectile {
public:
	Projectile(sf::Vector2f& direction, float* deltaTime);
	~Projectile();
	void StartMoving();

	sf::CircleShape shape;

private:
	sf::Vector2f direction;
	float lifeDuration = 5.0f;
	float* deltaTime;
};
