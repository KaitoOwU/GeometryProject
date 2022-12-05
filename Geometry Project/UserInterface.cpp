#include "UserInterface.h"
#include "Game.h"

void ButtonPlay(Game* game)
{
	game->LaunchGame();
}

void ButtonReset(Game* game)
{
	game->ResetGame();
}

void ButtonExit(Game* game)
{
	game->CloseGame();
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
	InitRectShapesPauseMenu();
	InitTextPauseMenu();
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
	std::list<Button>::iterator itButton = rectShapesPauseMenu.begin();
	while (itButton != rectShapesPauseMenu.end())
	{
		window.draw(itButton->shape);
		itButton++;
	}
	std::list<sf::Text>::iterator itText = textPauseMenu.begin();
	while (itText != textPauseMenu.end())
	{
		window.draw(*itText);
		itText++;
	}
	return;
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
		std::list<Button>::iterator itButton = rectShapesPauseMenu.begin();
		while (itButton != rectShapesPauseMenu.end())
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
	default:
	{
		return;
	}
	}
}

void UserInterface::UpdateGUI(float& currentHealth, float& maxHealth, float& currentXP, float& xpNextLevel)
{
	std::list<sf::RectangleShape>::iterator it = rectShapesGUI.begin();
	it->setSize({ it->getOutlineThickness()* 2.f 
		+ 300.f * currentHealth/maxHealth , 50.f});
	it++;
	it->setSize({ it->getOutlineThickness() * 2.f
	+ 500.f * currentXP/ xpNextLevel , 50.f });
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
	text.setFillColor(sf::Color::Magenta);
	text.setCharacterSize(100);
	text.setPosition(180,150);
	text.setString("XENOPHOBIA");
	textMainMenu.push_back(text);
}

void UserInterface::InitRectShapesGUI()
{
	rectShapesGUI.clear();
	sf::RectangleShape rect;
	SetBothColor(rect, sf::Color::Red, sf::Color::White);
	rect.setSize({ rect.getOutlineThickness() * 2.f + 300.f , 50.f });
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setPosition(rect.getOrigin() + sf::Vector2f{50.f, 35.f});
	rectShapesGUI.push_back(rect);
	SetBothColor(rect, sf::Color::Yellow, sf::Color::White);
	rect.setSize({ rect.getOutlineThickness() * 2.f + 500.f , 50.f });
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setPosition(WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y - 60.f);
	rectShapesGUI.push_back(rect);
}

void UserInterface::InitRectShapesPauseMenu() 
{
	rectShapesPauseMenu.clear();
	sf::RectangleShape rect;
	rect.setSize(*rectMainMenuSize);
	SetBothColor(rect, sf::Color::Black, sf::Color::White);
	rect.setOrigin({ rect.getSize().x / 2.f ,rect.getSize().y / 2.f });
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (1.f / 4.f) });
	rectShapesPauseMenu.push_back(Button(rect, &ButtonPlay));
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (2.f / 4.f) });
	rectShapesPauseMenu.push_back(Button(rect, &ButtonReset));
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) });
	rectShapesPauseMenu.push_back(Button(rect, &ButtonExit));
}

void UserInterface::InitTextPauseMenu() 
{
	textPauseMenu.clear();
	sf::Text text;
	text.setFont(*gameFont);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(sf::Vector2f{ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (1.f / 4.f) } + sf::Vector2f{ -55.f, -15.f });
	text.setString("Resume");
	textPauseMenu.push_back(text);
	text.setPosition(WINDOW_SIZE / 2.f + sf::Vector2f{ -45.f, -15.f });
	text.setString("Menu");
	textPauseMenu.push_back(text);
	text.setPosition(sf::Vector2f{ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) } + sf::Vector2f{ -45.f, -15.f });
	text.setString("Quit");
	textPauseMenu.push_back(text);
}


void SetBothColor(sf::RectangleShape& rect, sf::Color fillColor, sf::Color outLinecolor)
{
	rect.setFillColor(fillColor);
	rect.setOutlineColor(outLinecolor);
	rect.setOutlineThickness(2.f);
}

//ButtonUpgrade::ButtonUpgrade(sf::RectangleShape& rect, ButtonUpgradeBehaviour& buttonUpgrade)
//{
//		shape = rect;
//		pButtonUpgrade = buttonUpgrade;
//}

