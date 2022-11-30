#pragma once

class Player
{
public:
	sf::Vector2f position;

	Player(sf::Vector2f& initialPosition, float& size, sf::Color color = sf::Color::Red);
	~Player();

private:
	float size;
	sf::Color color;

};