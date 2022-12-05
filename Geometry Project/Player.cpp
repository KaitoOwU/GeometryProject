#include "Player.h"
#include <iostream>
#include <cmath>

Player::Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, sf::RenderWindow* window)
{
	sf::CircleShape shape;
	shape.setRadius(size);
	this->shape.setOrigin(this->shape.getRadius() / 2, this->shape.getRadius() / 2);
	shape.setPosition(initialPosition);
	shape.setFillColor(color);

	this->shape = shape;
	this->movementSpeed = movementSpeed;
	this->activeWindow = window;
}

Player::~Player()
{
}

void Player::Move(std::map<sf::Keyboard::Key, bool>& inputs, float& deltaTime)
{
	float px = shape.getPosition().x;
	float py = shape.getPosition().y;

	auto it = inputs.begin();
	while (it != inputs.end()) {
		if (it->second) {
			switch ((Player::MovementDirection) it->first) {
			case Player::Up:
				py -= (this->movementSpeed *deltaTime);
				break;
			case Player::Down:
				py += (this->movementSpeed * deltaTime);
				break;
			case Player::Right:
				px += (this->movementSpeed * deltaTime);
				break;
			case Player::Left:
				px -= (this->movementSpeed * deltaTime);
				break;
			}
		}
		it++;
	}

	this->shape.setPosition(
		Clamp(px, 20, WINDOW_SIZE.x - 20),
		Clamp(py, 20, WINDOW_SIZE.y - 20)
	);
}

void Player::Shoot() {
	if (shootCooldown <= 0) {
		sf::Vector2f mousePos = activeWindow->mapPixelToCoords(sf::Mouse::getPosition());
		sf::Vector2f projectileDir = Normalize({ mousePos.x - shape.getPosition().x, mousePos.y - shape.getPosition().y });

		Projectile* proj = new Projectile(projectileDir, deltaTime);
		proj->shape.setFillColor(sf::Color::Yellow);
		proj->shape.setRadius(5.0f);
		proj->shape.setPosition(shape.getPosition());
		this->projectileList.push_back(proj);
	}
}

void Player::Display(sf::RenderWindow& window)
{
	window.draw(shape);
}