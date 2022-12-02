#include "Player.h"

Player::Player(float size = 1, float movementSpeed = 5, sf::Vector2f initialPosition = {0, 0}, sf::Color color = sf::Color::Red)
{
	sf::CircleShape shape;
	shape.setRadius(size);
	shape.setPosition(initialPosition);
	shape.setFillColor(color);

	this->shape = shape;
	this->movementSpeed = movementSpeed;
}

Player::~Player()
{
	delete this;
}

void Player::SetActiveWindow(sf::Window& window) {
	this->activeWindow = &window;
}

void Player::Move(Player::MovementDirection direction)
{
	switch (direction) {
	case Up:
		this->shape.setPosition(this->shape.getPosition().x, this->shape.getPosition().y - this->movementSpeed);
		return;
	case Down:
		this->shape.setPosition(this->shape.getPosition().x, this->shape.getPosition().y + this->movementSpeed);
		return;
	case Left:
		this->shape.setPosition(this->shape.getPosition().x - this->movementSpeed, this->shape.getPosition().y);
		return;
	case Right:
		this->shape.setPosition(this->shape.getPosition().x + this->movementSpeed, this->shape.getPosition().y);
		return;
	}
}
