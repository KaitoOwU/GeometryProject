#include "UIObjects.h"

UIObjects::UIObjects(ShapeType type)
{
	switch (type)
	{
	case Rectangle:
		rectShape = sf::RectangleShape();
		break;
	case Circle:
		break;
	case Text:
		break;
	case Texture:
		break;
	default:
		break;
	}
}

UIObjects::~UIObjects()
{
}
