#include "InputManager.h"

void Input(sf::Event& event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Z:
		//MOVE TOP
		return;
	case sf::Keyboard::Q:
		//MOVE LEFT
		return;
	case sf::Keyboard::S:
		//MOVE BACK
		return;
	case sf::Keyboard::D:
		//MOVE RIGHT
		return;
	case sf::Keyboard::Space:
		//SHOOT
		return;
	}
}
