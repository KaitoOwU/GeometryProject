#pragma once
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
		None,
		Up,
		Down,
		Left,
		Right
	};

	Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, float* deltaTime);
	~Player();

	void SetActiveWindow(sf::Window& window);
	void Move(Player::MovementDirection* direction, int amount_of_value);
	void UpdateInputs(std::map<sf::Keyboard::Key, bool>& inputs);

private:
	float* deltaTime;
};