#include "Projectiles.h"

PlayerCircleProjectile::PlayerCircleProjectile(sf::Vector2f& direction, float* deltaTime, EnemyManager* pEnemyManager)
{
	sf::CircleShape shape;
	this->shape = shape;
	this->direction = direction;
	this->deltaTime = deltaTime;
	this->pEnemyManager = pEnemyManager;
}

PlayerCircleProjectile::~PlayerCircleProjectile()
{
}

PlayerTriangleProjectile::PlayerTriangleProjectile(float* deltaTime, EnemyManager* pEnemyManager)
{
	sf::CircleShape shape;
	this->shape = shape;
	this->deltaTime = deltaTime;
	this->pEnemyManager = pEnemyManager;
}
 

