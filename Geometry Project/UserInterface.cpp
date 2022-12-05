#include "UserInterface.h"
#include "Game.h"

void ButtonExit(Game* game)
{
	game->CloseGame();
}

void ButtonPlay(Game* game)
{
	game->LaunchGame();
}

UserInterface::UserInterface(Game* game)
{
	gameFont = new sf::Font;
	gameFont->loadFromFile(GetAssetsPath("arial.ttf"));
	this->game = game;
	rectMainMenuSize = new sf::Vector2f;
	*rectMainMenuSize = sf::Vector2f{ 500.f, 100.f };
	//Init shapes containers
	InitRectShapesMainMenu();
	InitTextMainMenu();
	InitRectShapesGUI();
}

UserInterface::~UserInterface()
{
	delete gameFont;
	delete rectMainMenuSize;
}

void UserInterface::DisplayMainMenu(sf::RenderWindow& window)
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
	return;
}

void UserInterface::DisplayGUI(sf::RenderWindow& window)
{
	std::list<sf::RectangleShape>::iterator it = rectShapesGUI.begin();
	while (it != rectShapesGUI.end())
	{
		window.draw(*it);
		it++;
	}
	return;
}

void UserInterface::DisplayUpgradeMenu(sf::RenderWindow& window)
{

}

void UserInterface::DisplayPauseMenu(sf::RenderWindow& window)
{

}

void UserInterface::CheckClick(sf::Vector2i mousePosition, sf::RenderWindow& window, Game* game)
{
	switch (*(game->gameState))
	{
	case GAMESTATE::MENUOPEN:
	{
		std::list<Button>::iterator itButton = rectShapesMainMenu.begin();
		while (itButton != rectShapesMainMenu.end())
		{
			if (IsOverlappingCircleOnBox((sf::Vector2f)mousePosition, 0.1f,
				itButton->shape.getPosition(), itButton->shape.getSize()))
			{
				(*itButton->pButtonFunction)(game);
			}
			itButton++;
		}
		return;
	}
	case GAMESTATE::UPGRADING:
	{

		return;
	}
	case GAMESTATE::PAUSE:
	{

		return;
	}
	default:
	{
		return;
	}
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
	rectShapesMainMenu.push_back(Button(rect, &ButtonPlay));
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) });
	rectShapesMainMenu.push_back(Button(rect, &ButtonExit));
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
