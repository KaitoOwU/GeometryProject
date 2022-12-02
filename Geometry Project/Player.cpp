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
	std::cout << "Yes\n";

	sf::Vector2f temp = this->shape.getPosition();
	int x = temp.x + 20;
	int nx = temp.x - 20;
	int y = temp.y + 20;
	int ny = temp.y - 20;

	if (x > 800 || nx < 0) {
		this->shape.setPosition(clamp)
		return;
	}
	if (y > 600 || ny < 0) {
		return;
	}

	std::cout << "Yes 2\n";

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