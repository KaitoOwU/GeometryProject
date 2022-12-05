#pragma once
#include "SFML/Graphics.hpp"
#include "AllData.h"
#include <list>
#include <iostream>
#include <cmath>

class Game;
typedef void(*ButtonFunction)(Game*);

struct Button {
	sf::RectangleShape shape;
	ButtonFunction pButtonFunction;
	Button(sf::RectangleShape rect, ButtonFunction buttonFunction) {
		shape = rect;
		pButtonFunction = buttonFunction;
	}
};

void ButtonExit(Game* game);

void ButtonPlay(Game* game);

class UserInterface
{
public:
	UserInterface(Game* game);
	~UserInterface();
	void DisplayMainMenu(sf::RenderWindow& window);
	void DisplayGUI(sf::RenderWindow& window);
	void DisplayUpgradeMenu(sf::RenderWindow& window);
	void DisplayPauseMenu(sf::RenderWindow& window);
	sf::Font* gameFont;
	void CheckClick(sf::Vector2i mousePosition, sf::RenderWindow& window, Game* game);
	Game* game;

private:
	void InitRectShapesMainMenu();
	void InitTextMainMenu();
	void InitRectShapesGUI();
	sf::Vector2f* rectMainMenuSize;
	std::list<Button> rectShapesMainMenu;
	std::list<sf::Text> textMainMenu;
	std::list<sf::RectangleShape> rectShapesGUI;
};

void SetBothColor(sf::RectangleShape& rect, sf::Color fillColor, sf::Color outLinecolor);

