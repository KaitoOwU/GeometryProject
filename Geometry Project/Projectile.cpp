#include "Projectile.h"

Projectile::Projectile(sf::CircleShape& shape, sf::Vector2f& direction)
{
	this->shape = shape;
	this->direction = direction;
}

Projectile::~Projectile()
{
}

void Projectile::StartMoving()
{
	while (this != nullptr) {
		this->shape.move(Normalize(this->direction));
	}
}

