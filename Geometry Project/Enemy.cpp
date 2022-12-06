#include "Enemy.h"

Enemy::Enemy(float size = 0, sf::Vector2f spawnPoint = {0,0}, int numberOfSides = 4, float maxHealth = 100.0f, float moveSpeed = 1.0f, float attackSpeed = 1.0f, float damage = 10.0f)
{
	sf::CircleShape shape(0.f, numberOfSides);
	this->shape = shape;
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setOrigin(sf::Vector2f({ this->shape.getRadius() / 2.f, this->shape.getRadius() / 2.f }));
	this->shape.setPosition(spawnPoint);
	this->shape.setRadius(size);

	

	this->pEnemyHealth = Health(maxHealth);
	this->pEnemyStats = CharacterStats(moveSpeed, attackSpeed, damage);
}

Enemy::~Enemy()
{
}
