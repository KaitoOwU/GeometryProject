#pragma once
#include "AllData.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <list>

class Player
{
public:
	sf::CircleShape shape;
	float movementSpeed;
	sf::Window* activeWindow = nullptr;

	enum MovementDirection {
		None = -1,
		Up = sf::Keyboard::Z,
		Down = sf::Keyboard::S,
		Left = sf::Keyboard::Q,
		Right = sf::Keyboard::D
	};

	Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, float* deltaTime);
	~Player();

	void SetActiveWindow(sf::Window& window);
	void Move(std::map<MovementDirection, bool>& inputs);

private:
	float* deltaTime;
	float shootCooldown = 1.0f;
};