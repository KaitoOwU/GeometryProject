#include "Enemy.h"

Enemy::Enemy(float size = 0, sf::Vector2f spawnPoint = {0,0}, int numberOfSides = 4, float maxHealth = 100.f, float moveSpeed = 100.f, float attackSpeed = 1.f, float damage = 1.f, int exp = 1, ExpManager* pExpManager = nullptr)
{
	sf::CircleShape shape(0.f, numberOfSides);
	this->shape = shape;
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setOrigin(sf::Vector2f({ this->shape.getRadius() / 2.f, this->shape.getRadius() / 2.f }));
	this->shape.setPosition(spawnPoint);
	this->shape.setRadius(size);
	this->pExpManager = pExpManager;
	this->exp = exp;

	
	this->pEnemyHealth = Health(maxHealth);
	this->pEnemyStats = CharacterStats(moveSpeed, attackSpeed, damage);

	this->consAttackSpeed = this->pEnemyStats.attackSpeed;
}

void Enemy::EnemyDeath()
{
	pExpManager->experienceOrbList.push_back(Exp(shape.getPosition(), this->exp));
}

Enemy::~Enemy()
{
}