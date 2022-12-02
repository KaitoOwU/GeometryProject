#pragma once
#include "SFML/Graphics.hpp"
#include "AllData.h"
#include <vector>

class UserInterface
{
public:
	UserInterface();
	~UserInterface();
	void DisplayUI(sf::RenderWindow& window);

private:
	bool _isMainMenuDisplayed;
	sf::Vector2f rectMainMenuSize = {500.f, 100.f};
	std::vector<sf::RectangleShape> rectShapesMainMenu;
	void InitRectShapesMainMenu();
	std::vector<sf::Text> textMainMenu;
	void InitTextMainMenu();
	bool _isGUIDisplayed;
	std::vector<sf::RectangleShape> rectShapesGUI;
	void InitRectShapesGUI();
};

void SetBothColor(sf::RectangleShape& rect, sf::Color fillColor, sf::Color outLinecolor);