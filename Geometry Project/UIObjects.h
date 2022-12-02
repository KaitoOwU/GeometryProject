#pragma once
#include "SFML/Graphics.hpp"
#include "AllData.h"

enum ShapeType
{
	Rectangle,
	Circle,
	Text,
	Texture,
};

class UIObjects
{
public:
	sf::RectangleShape rectShape;
	sf::CircleShape circleShape;
	sf::Text textShape;
	sf::Texture textureShape;


	UIObjects(ShapeType type);
	~UIObjects();

private:

};
