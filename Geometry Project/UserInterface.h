#pragma once
#include "SFML/Graphics.hpp"
#include "AllData.h"
#include <list>
#include <iostream>
#include <cmath>

class Game;

typedef void(*ButtonMenuBehaviour)(Game* game);


struct Button {
	sf::RectangleShape shape;
	ButtonMenuBehaviour pButtonFunction;
	Button(sf::RectangleShape rect, ButtonMenuBehaviour buttonFunction) {
		shape = rect;
		pButtonFunction = buttonFunction;
	}
};

void ButtonPlay(Game* game);
void ButtonReset(Game* game);
void ButtonExit(Game* game);
void UpgadeSpeed(Game* game);
void UpgadeDamage(Game* game);
void UpgadeHealth(Game* game);
void Mutate(Game* game);

class UserInterface
{
public:
	UserInterface(Game* game);
	~UserInterface();
	void DisplayMainMenu(sf::RenderWindow& window);
	void DisplayGUI(sf::RenderWindow& window);
	void DisplayUpgradeMenu(sf::RenderWindow& window);
	void DisplayPauseMenu(sf::RenderWindow& window);
	void DisplayDeathMenu(sf::RenderWindow& window);
	void CheckClick(sf::Vector2i mousePosition, sf::RenderWindow& window, Game* game);
	void UpdateGUI(float& currentHealth, float& maxHealth, float& currentXP, float& xpForNextLevel, int& level, float* score);
	void UpdateScore(float* newScore);
	sf::Font* gameFont;
	Game* game;

private:
	void InitRectShapesMainMenu();
	void InitTextMainMenu();
	void InitRectShapesGUI();
	void InitTextGUI();
	void InitRectShapesPauseMenu();
	void InitTextPauseMenu();
	void InitRectShapesUpgradeMenu();
	void InitTextUpgradeMenu();
	void InitRectShapesDeathMenu();
	void InitTextDeathMenu();
	sf::Vector2f* rectMainMenuSize;
	std::list<Button> rectShapesMainMenu;
	std::list<sf::Text> textMainMenu;
	std::list<sf::RectangleShape> rectShapesGUI;
	std::list<sf::Text> textGUI;
	std::list<Button> rectShapesPauseMenu;
	std::list<sf::Text> textPauseMenu;
	std::list<Button> rectShapesUpgradeMenu;
	std::list<sf::Text> textUpgradeMenu;
	std::list<Button> rectShapesDeathMenu;
	std::list<sf::Text> textDeathMenu;
};

void SetBothColor(sf::RectangleShape& rect, sf::Color fillColor, sf::Color outLinecolor);

