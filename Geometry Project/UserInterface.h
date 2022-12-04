#pragma once
#include "SFML/Graphics.hpp"
#include "AllData.h"
#include <list>
#include <iostream>
#include <cmath>

class Game;
typedef void(*ButtonFunction)(sf::RenderWindow&, Game*);

struct Button {
	sf::RectangleShape shape;
	ButtonFunction pButtonFunction;
	Button(sf::RectangleShape rect, ButtonFunction buttonFunction) {
		shape = rect;
		pButtonFunction = buttonFunction;
	}
};

void ButtonExit(sf::RenderWindow& window, Game* game);

void ButtonPlay(sf::RenderWindow& window, Game* game);

class UserInterface
{
public:
	UserInterface();
	~UserInterface();
	void DisplayUI(sf::RenderWindow& window);
	sf::Font* gameFont = new sf::Font;
	void CheckClick(sf::Vector2i mousePosition, sf::RenderWindow& window, Game* game);

private:
	bool* _isMainMenuDisplayed = new bool;
	sf::Vector2f* rectMainMenuSize = new sf::Vector2f{500.f, 100.f};
	std::list<Button> rectShapesMainMenu;
	void InitRectShapesMainMenu();
	std::list<sf::Text> textMainMenu;
	void InitTextMainMenu();
	bool* _isGUIDisplayed = new bool;
	std::list<sf::RectangleShape> rectShapesGUI;
	void InitRectShapesGUI();
};

void SetBothColor(sf::RectangleShape& rect, sf::Color fillColor, sf::Color outLinecolor);
