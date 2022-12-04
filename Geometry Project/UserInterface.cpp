#include "UserInterface.h"

void ButtonExit(sf::RenderWindow& window, Game* game)
{
	window.close();
}

void ButtonPlay(sf::RenderWindow& window, Game* game)
{
	//Encore à faire 
}

UserInterface::UserInterface()
{
	*_isMainMenuDisplayed = true;
	*_isGUIDisplayed = false;
	gameFont->loadFromFile(GetAssetsPath("arial.ttf"));
	
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
	if (*_isMainMenuDisplayed)
	{
		std::list<Button>::iterator itButton = rectShapesMainMenu.begin();
		while (itButton != rectShapesMainMenu.end())
		{
			window.draw(itButton->shape);
			itButton++;
		}
		std::list<sf::Text>::iterator itText = textMainMenu.begin();
		while (itText != textMainMenu.end())
		{
			window.draw(*itText);
			itText++;
		}
	}
	if (*_isGUIDisplayed)
	{
		std::list<sf::RectangleShape>::iterator it = rectShapesGUI.begin();
		while (it != rectShapesGUI.end())
		{
			window.draw(*it);
			it++;
		}
	}
}

void UserInterface::CheckClick(sf::Vector2i mousePosition, sf::RenderWindow& window, Game* game)
{
	std::list<Button>::iterator itButton = rectShapesMainMenu.begin();
	while (itButton != rectShapesMainMenu.end())
	{
		if (IsOverlappingCircleOnBox((sf::Vector2f)mousePosition, 0.1f,
			itButton->shape.getPosition(), itButton->shape.getSize()))
		{
			(*itButton->pButtonFunction)(window, game);
		}
		itButton++;
	}
}

void UserInterface::InitRectShapesMainMenu()
{
	rectShapesMainMenu.clear();
	sf::RectangleShape rect;
	rect.setSize(*rectMainMenuSize);
	SetBothColor(rect, sf::Color::Black, sf::Color::White);
	rect.setOrigin({ rect.getSize().x / 2.f ,rect.getSize().y / 2.f });
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (2.f / 4.f) });
	Button button = Button(rect, &ButtonExit);
	rectShapesMainMenu.push_back(button);
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) });
	button.shape = rect;
	rectShapesMainMenu.push_back(button);
}

void UserInterface::InitTextMainMenu()
{
	textMainMenu.clear();
	sf::Text text;
	text.setFont(*gameFont);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(WINDOW_SIZE / 2.f + sf::Vector2f{-45.f, -15.f});
	text.setString("Play");
	textMainMenu.push_back(text);
	text.setPosition(sf::Vector2f{ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) } + sf::Vector2f{ -45.f, -15.f });
	text.setString("Quit");
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
