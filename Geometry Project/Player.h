#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	sf::CircleShape shape;
	float movementSpeed;
	sf::Window* activeWindow = nullptr;

	enum MovementDirection {
		None,
		Up,
		Down,
		Left,
		Right
	};

	Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color);
	~Player();

	void SetActiveWindow(sf::Window& window);
	void Move(Player::MovementDirection direction);
};