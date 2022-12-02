#include "Player.h"

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
}

void Player::Move(Player::MovementDirection* direction, int amount_of_value)
{
	sf::Vector2f vector = { 0, 0 };
	for (int i = 0; i < amount_of_value; i++) {
		switch (direction[i]) {
		case Up:
			vector.y += this->movementSpeed * *this->deltaTime;
			break;
		case Down:
			vector.y -= this->movementSpeed * *this->deltaTime;
			break;
		case Left:
			vector.x -= this->movementSpeed * *this->deltaTime;
			break;
		case Right:
			vector.x += this->movementSpeed * *this->deltaTime;
			break;
		}
	}
	this->shape.setPosition(shape.getPosition() + vector);
}

void Player::UpdateInputs(std::map<sf::Keyboard::Key, bool>& inputs) {
	auto it = inputs.begin();
	std::list<MovementDirection> listKeys;

	for (auto it = inputs.begin();
		it != inputs.end(); ++it) {
		if (it->second) {
			switch (it->first) {
			case sf::Keyboard::Z:
				listKeys.push_back(MovementDirection::Up);
				break;
			case sf::Keyboard::Q:
				listKeys.push_back(MovementDirection::Left);
				break;
			case sf::Keyboard::S:
				listKeys.push_back(MovementDirection::Down);
				break;
			case sf::Keyboard::D:
				listKeys.push_back(MovementDirection::Right);
				break;
			case sf::Keyboard::Space:
				//this->Shoot();
				break;
			}
		}
	}

	MovementDirection* dir = new MovementDirection[listKeys.size()];
	int i = 0;
	for (auto it = listKeys.begin();
		it != listKeys.end(); ++it) {
		dir[i] = (*it);
	}
	this->Move(dir, i);
}