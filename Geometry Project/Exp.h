#pragma once
#include "AllData.h"

class Exp
{
public:
	Exp(sf::Vector2f pos, float expValue);
	~Exp();

	sf::CircleShape shape;
	float expValue = 0.0f;

private:

};

