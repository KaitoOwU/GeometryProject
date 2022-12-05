#pragma once
#include "AllData.h"
#include <SFML/Graphics.hpp>

class Projectile {
public:
	Projectile(sf::Vector2f& direction, float* deltaTime);
	~Projectile();

	sf::CircleShape shape;
	sf::Vector2f direction;
	float lifeDuration = 5.0f;

private:
	float* deltaTime;
};
