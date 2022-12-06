#pragma once
#include <SFML/Graphics.hpp>
#include "AllData.h"
#include "Projectile.h"
#include <map>
#include <list>

class Player
{
public:
	sf::CircleShape shape;
	float movementSpeed;
	sf::RenderWindow* activeWindow = nullptr;
	float shootCooldown = 1.0f;
	std::list<Projectile*> projectileList;

	bool canMove = true;

	enum MovementDirection {
		None = -1,
		Up = sf::Keyboard::Z,
		Down = sf::Keyboard::S,
		Left = sf::Keyboard::Q,
		Right = sf::Keyboard::D
	};

	Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, sf::RenderWindow* window);
	~Player();

	void Move(std::map<sf::Keyboard::Key, bool>& inputs, float& deltaTime);
	void Shoot(std::map<sf::Keyboard::Key, bool>& inputs, float& deltaTime);
	void Display(sf::RenderWindow& window);

	void UpdateProjectile(float& deltaTime);
	void DisplayProjectile(sf::RenderWindow& window);
};