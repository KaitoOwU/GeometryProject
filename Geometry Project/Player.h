#pragma once
#include <SFML/Graphics.hpp>
#include "AllData.h"
#include "Projectiles.h"
#include <map>
#include <list>

class Player
{
public:

	enum MovementDirection {
		None = -1,
		Up = sf::Keyboard::Z,
		Down = sf::Keyboard::S,
		Left = sf::Keyboard::Q,
		Right = sf::Keyboard::D
	};

	enum ActiveProjectileType {
		Circle,
		Triangle
	};

	enum Mutation {
		MonoShot = 0,
		DoubleShot = 1,
		QuadraShot = 2,
		TriangleMaster = 3
	};

	sf::CircleShape shape;
	float movementSpeed;
	sf::RenderWindow* activeWindow = nullptr;
	float shootCooldown = 1.0f;
	std::list<PlayerCircleProjectile*> circleProjList;
	std::list<PlayerTriangleProjectile*> triangleProjList;
	ActiveProjectileType projectileType = ActiveProjectileType::Circle;

	float maxHealth = 100.f;
	float health = maxHealth;
	float baseDamage = 3.f;
	float damageMultiplier = 1.f;
	float speedMultiplier = 1.f;
	Mutation currentMutation = Mutation::MonoShot;

	int currentLvl = 1;
	float currentXP = 0.f;
	std::map<int, float> xpRequired{
		{1, 2.0f},
		{2, 3.0f},
		{3, 5.0f},
		{4, 7.0f},
		{5, 11.0f},
		{6, 13.0f},
		{7, 17.0f},
		{8, 19.0f},
		{9, 23.0f},
		{10, 29.0f},
		{11, 31.0f},
		{12, 37.0f},
		{13, 41.0f},
		{14, 43.0f},
		{15, 47.0f},
		{16, 53.0f},
		{17, 59.0f},
		{18, 61.0f},
		{19, 67.0f},
		{20, 71.0f},
		{21, 73.0f},
		{22, 79.0f},
		{23, 83.0f},
		{24, 97.0f},
		{25, 101.0f}
	};

	bool canMove = true;

	Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, sf::RenderWindow* window);
	~Player();

	void Move(std::map<sf::Keyboard::Key, bool>& inputs, float& deltaTime);
	void Shoot(std::map<sf::Keyboard::Key, bool>& inputs, float& deltaTime);
	void MutateToNextState();

	void SetProjectileMode(ActiveProjectileType type);
	void Display(sf::RenderWindow& window);

	void UpdateProjectile(float& deltaTime);
	void DisplayProjectile(sf::RenderWindow& window);

private:
	int numberOfBalls = 1;
};