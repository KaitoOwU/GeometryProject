#include <SFML/Graphics.hpp>
#include "Player.h"

Player::Player(sf::Vector2f& initialPosition, float& size, sf::Color color = sf::Color::Red)
{
	this->position = initialPosition;
	this->size = size;
	this->color = color;

	sf::CircleShape shape;
	shape.setRadius(size);
	shape.setPosition(initialPosition);
	shape.setFillColor(color);
}

Player::~Player()
{
}
