#pragma once
#include "AllData.h"
#include <SFML/Graphics.hpp>

class Projectile {
public:
	Projectile(sf::CircleShape& shape, sf::Vector2f& direction);
	~Projectile();
	void StartMoving();

	sf::CircleShape shape;

private:
	sf::Vector2f direction;
};
