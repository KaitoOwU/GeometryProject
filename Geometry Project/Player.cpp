#include "Player.h"
#include <iostream>

Player::Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, float* deltaTime)
{
	sf::CircleShape shape;
	shape.setRadius(size);
	this->shape.setOrigin(this->shape.getRadius() / 2, this->shape.getRadius() / 2);
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
}

void Player::Move(std::map<Player::MovementDirection, bool>& inputs)
{
	auto it = inputs.begin();
	while (it != inputs.end()) {
		if (it->second) {
			switch (it->first) {
			case Player::Up:
				this->shape.move(0, -(this->movementSpeed * *(this->deltaTime)));
				break;
			case Player::Down:
				this->shape.move(0, (this->movementSpeed * *(this->deltaTime)));
				break;
			case Player::Right:
				this->shape.move((this->movementSpeed * *(this->deltaTime)), 0);
				break;
			case Player::Left:
				this->shape.move(-(this->movementSpeed * *(this->deltaTime)), 0);
				break;
			}
		}
		it++;
	}
}