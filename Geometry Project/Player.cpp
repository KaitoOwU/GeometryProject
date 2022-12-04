#include "Player.h"
#include <iostream>
#include <cmath>

Player::Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, float* deltaTime)
{
	sf::CircleShape shape;
	shape.setRadius(size);
	shape.setPosition(initialPosition);
	shape.setFillColor(color);

	this->shape = shape;
	this->movementSpeed = movementSpeed;
	this->deltaTime = deltaTime;
}

Player::~Player()
{
}

void Player::SetActiveWindow(sf::Window& window) {
	this->activeWindow = &window;
	this->shape.setOrigin(window.getSize().x / 2, window.getSize().y / 2);
}

void Player::Move(std::map<Player::MovementDirection, bool>& inputs)
{
	int x1 = 20;
	int x2 = WINDOW_SIZE.x - 20;
	int y1 = 20;
	int y2 = WINDOW_SIZE.y - 20;

	float px = shape.getPosition().x;
	float py = shape.getPosition().y;

	auto it = inputs.begin();
	while (it != inputs.end()) {
		if (it->second) {
			switch (it->first) {
			case Player::Up:
				py -= (this->movementSpeed * *(this->deltaTime));
				break;
			case Player::Down:
				py += (this->movementSpeed * *(this->deltaTime));
				break;
			case Player::Right:
				px += (this->movementSpeed * *(this->deltaTime));
				break;
			case Player::Left:
				px -= (this->movementSpeed * *(this->deltaTime));
				break;
			}
		}
		it++;
	}

	this->shape.setPosition(
		Clamp(px, x1, x2),
		Clamp(py, y1, y2)
	);
}