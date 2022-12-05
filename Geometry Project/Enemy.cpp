#include "Enemy.h"

Enemy::Enemy(float size, sf::Vector2f spawnPoint, sf::Color color, float maxHealth, float moveSpeed, float attackSpeed, float damage)
{
	sf::CircleShape shape;
	this->shape = shape;
	this->shape.setFillColor(color);
	this->shape.setOrigin(sf::Vector2f({ this->shape.getRadius() / 2.f, this->shape.getRadius() / 2.f }));
	this->shape.setPosition(spawnPoint);
	this->shape.setRadius(size);

	

	this->pEnemyHealth = new Health(maxHealth);
	this->pEnemyStats = new CharacterStats(moveSpeed, attackSpeed, damage);
}

Enemy::~Enemy()
{
	//delete pEnemyHealth;
	//delete pEnemyStats;
}
