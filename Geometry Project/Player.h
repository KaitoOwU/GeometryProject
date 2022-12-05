#pragma once
#include "AllData.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
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
	void Shoot();
	void Display(sf::RenderWindow& window);

private:
	float* deltaTime;
};