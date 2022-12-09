#pragma once
#include "Health.h"
#include "CharacterStats.h"
#include "ExpManager.h"
#include <SFML/Graphics.hpp>



class Enemy
{
public:
	Enemy();
	Enemy(float size, sf::Vector2f spawnPoint,int numberOfSides, float maxHealth, float moveSpeed, float attackSpeed, float damage,float spinSpeed, ExpManager* pExpManager);
	~Enemy();

	void EnemyDeath();

	Health pEnemyHealth;
	CharacterStats pEnemyStats;
	ExpManager* pExpManager = nullptr;
	sf::CircleShape shape;
	sf::Color initColor = sf::Color::White;

	float enemyDamageCoolDown = 0.5f;
	float spinSpeed = 0.f;
	float consAttackSpeed = 0.f;

	float damageHit = 0.15f;
	float contDamageHit = 0.15f;
private:

};