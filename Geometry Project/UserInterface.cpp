#include "UserInterface.h"


UserInterface::UserInterface()
{
	_isMainMenuDisplayed = true;
	_isGUIDisplayed = false;
	gameFont.loadFromFile(GetAssetsPath("arial.ttf"));
	
	//Init shapes containers

	InitRectShapesMainMenu();
	InitTextMainMenu();
	InitRectShapesGUI();
}

UserInterface::~UserInterface()
{
}

void UserInterface::DisplayUI(sf::RenderWindow& window)
{
	if (_isMainMenuDisplayed)
	{
		for (int i = 0; i < rectShapesMainMenu.size(); i++)
		{
			window.draw(rectShapesMainMenu[i]);
		}
		for (int i = 0; i < textMainMenu.size(); i++)
		{
			window.draw(textMainMenu[i]);
		}
	}
	if (_isGUIDisplayed)
	{
		for (int i = 0; i < rectShapesGUI.size(); i++)
		{
			window.draw(rectShapesGUI[i]);
		}
	}
}

void UserInterface::InitRectShapesMainMenu()
{
	rectShapesMainMenu.clear();
	sf::RectangleShape rect;
	rect.setSize(rectMainMenuSize);
	rect.setOrigin({ rect.getSize().x / 2.f ,rect.getSize().y / 2.f });
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (1.f / 4.f) });
	SetBothColor(rect, sf::Color::Black, sf::Color::White);
	rectShapesMainMenu.push_back(rect);
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (2.f / 4.f) });
	rectShapesMainMenu.push_back(rect);
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) });
	rectShapesMainMenu.push_back(rect);
}

void UserInterface::InitTextMainMenu()
{
	textMainMenu.clear();
	sf::Text text;
	text.setFont(gameFont);
	text.setString("Project");
	text.setFillColor(sf::Color::Red);
	text.setOrigin(WINDOW_SIZE.x, WINDOW_SIZE.y);
	text.setCharacterSize(24);
	text.setPosition(WINDOW_SIZE.x, WINDOW_SIZE.y);
	textMainMenu.push_back(text);
}

void UserInterface::InitRectShapesGUI()
{
	rectShapesGUI.clear();
}

void SetBothColor(sf::RectangleShape& rect, sf::Color fillColor, sf::Color outLinecolor)
{
	rect.setFillColor(fillColor);
	rect.setOutlineColor(outLinecolor);
	rect.setOutlineThickness(2.f);
}
