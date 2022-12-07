#include "Exp.h"

Exp::Exp(sf::Vector2f pos, float expValue)
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setOrigin(sf::Vector2f({ this->shape.getRadius() / 2.f, this->shape.getRadius() / 2.f }));
	this->shape.setRadius(10);
	this->shape.setPosition(pos);
	this->expValue = expValue;


}

Exp::~Exp()
{
}