#include "Projectile.h"

Projectile::Projectile(sf::Vector2f& direction, float* deltaTime)
{
	sf::CircleShape shape;
	this->shape = shape;
	this->direction = direction;
	this->deltaTime = deltaTime;
}

Projectile::~Projectile()
{
}
