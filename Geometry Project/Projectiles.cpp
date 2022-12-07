#include "Projectiles.h"

PlayerCircleProjectile::PlayerCircleProjectile(sf::Vector2f& direction, float* deltaTime)
{
	sf::CircleShape shape;
	this->shape = shape;
	this->direction = direction;
	this->deltaTime = deltaTime;
}

PlayerCircleProjectile::~PlayerCircleProjectile()
{
}

PlayerTriangleProjectile::PlayerTriangleProjectile(float* deltaTime)
{
	sf::CircleShape shape;
	this->shape = shape;
	this->deltaTime = deltaTime;
}

PlayerTriangleProjectile::~PlayerTriangleProjectile()
{
}
