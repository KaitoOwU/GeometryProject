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

void UpgadeSpeed(Game* game) 
{
	game->UpgadeSpeed();
}

void UpgadeDamage(Game* game) 
{
	game->UpgadeDamage();
}

void UpgadeHealth(Game* game) 
{
	game->UpgadeHealth();
}

void Mutate(Game* game) 
{
	if ((int)game->pPlayer->currentMutation + 1 <= game->pPlayer->currentLvl / 5.f)
	{
		game->Mutate();
	}
}

UserInterface::UserInterface(Game* game)
{
	gameFont = new sf::Font;
	gameFont->loadFromFile(GetAssetsPath("arial.ttf"));
	this->game = game;
	rectMainMenuSize = new sf::Vector2f;
	*rectMainMenuSize = sf::Vector2f{ 500.f, 100.f };
	
	InitRectShapesMainMenu();
	InitTextMainMenu();
	InitRectShapesGUI();
	InitTextGUI();
	InitRectShapesPauseMenu();
	InitTextPauseMenu();
	InitRectShapesUpgradeMenu();
	InitTextUpgradeMenu();
	InitRectShapesDeathMenu();
	InitTextDeathMenu();
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
	std::list<sf::RectangleShape>::iterator itShape = rectShapesGUI.begin();
	while (itShape != rectShapesGUI.end())
	{
		window.draw(*itShape);
		itShape++;
	}
	std::list<sf::Text>::iterator itText = textGUI.begin();
	while (itText != textGUI.end())
	{
		window.draw(*itText);
		itText++;
	}
	return;
}

void UserInterface::DisplayUpgradeMenu(sf::RenderWindow& window)
{
	std::list<Button>::iterator itButton = rectShapesUpgradeMenu.begin();
	while (itButton != rectShapesUpgradeMenu.end())
	{
		window.draw(itButton->shape);
		itButton++;
	}
	std::list<sf::Text>::iterator itText = textUpgradeMenu.begin();
	while (itText != textUpgradeMenu.end())
	{
		window.draw(*itText);
		itText++;
	}
	return;
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

void UserInterface::DisplayDeathMenu(sf::RenderWindow& window) 
{
	std::list<Button>::iterator itButton = rectShapesDeathMenu.begin();
	while (itButton != rectShapesDeathMenu.end())
	{
		window.draw(itButton->shape);
		itButton++;
	}
	std::list<sf::Text>::iterator itText = textDeathMenu.begin();
	while (itText != textDeathMenu.end())
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
		std::list<Button>::iterator itButton = rectShapesUpgradeMenu.begin();
		while (itButton != rectShapesUpgradeMenu.end())
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
	case GAMESTATE::DEATH:
	{
		std::list<Button>::iterator itButton = rectShapesDeathMenu.begin();
		while (itButton != rectShapesDeathMenu.end())
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

void UserInterface::UpdateGUI(float& currentHealth, float& maxHealth, float& currentXP,
	float& xpForNextLevel, int& level, float* score){

	if (maxHealth <= 0 || xpForNextLevel <= 0) return;
	std::list<sf::RectangleShape>::iterator it = rectShapesGUI.begin();
	it++;
	it->setSize({ it->getOutlineThickness()* 2.f 
		+ 300.f * currentHealth/maxHealth , 50.f});
	it++;
	it++;
	it->setSize({ it->getOutlineThickness() * 2.f
	+ 500.f * currentXP/ xpForNextLevel , 50.f });
	(--textGUI.end())->setString("LVL: " + std::to_string(level));
}

void UserInterface::UpdateScore(float* newScore)
{
	std::list<sf::Text>::iterator it = textDeathMenu.begin();
	it++;
	it++;
	it->setFillColor(sf::Color::Red);
	it->setCharacterSize(100);
	it->setPosition(180, 150);
	it->setString("Score : " + std::to_string((int)*newScore));
}

void UserInterface::UpdateUpgradeMenu() 
{
	std::list<sf::Text>::iterator it = textUpgradeMenu.end();
	it--;
	if ((int)game->pPlayer->currentMutation + 1 <= game->pPlayer->currentLvl / 5.f)
	{
		it->setPosition({ WINDOW_SIZE.x / 2.f - 70.f,850.f });
		it->setString("Mutate");
	}
	else
	{
		it->setPosition({ WINDOW_SIZE.x / 2.f - 180.f,850.f });
		it->setString("Mutation Impossible");
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
	text.setFillColor(sf::Color::Magenta);
	text.setCharacterSize(85);
	text.setPosition(140,150);
	text.setString("GEIMEROPHOBIA");
	textMainMenu.push_back(text);
}

void UserInterface::InitRectShapesGUI()
{
	rectShapesGUI.clear();
	sf::RectangleShape rect;
	SetBothColor(rect, sf::Color::Transparent, sf::Color::White);
	rect.setSize({ rect.getOutlineThickness() * 2.f + 300.f ,
		rect.getOutlineThickness() * 2.f + 50.f });
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setPosition(rect.getOrigin() + sf::Vector2f{50.f, 35.f});
	rectShapesGUI.push_back(rect);
	rect.setSize({ 300.f , 50.f });
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setFillColor(sf::Color::Red);
	rect.setOutlineThickness(0.f);
	rectShapesGUI.push_back(rect);
	SetBothColor(rect, sf::Color::Transparent, sf::Color::White);
	rect.setSize({ rect.getOutlineThickness() * 2.f + 500.f ,
		rect.getOutlineThickness() * 2.f + 50.f });
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setPosition(WINDOW_SIZE.x / 2.f, WINDOW_SIZE.y - 60.f);
	rectShapesGUI.push_back(rect);
	rect.setSize({ 500.f , 50.f });
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setFillColor(sf::Color::Green);
	rect.setOutlineThickness(0.f);
	rectShapesGUI.push_back(rect);
}

void UserInterface::InitTextGUI() 
{
	textGUI.clear();
	sf::Text text;
	text.setFont(*gameFont);
	text.setString("LVL:");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Green);
	text.setPosition(WINDOW_SIZE.x / 2.f + 270.f, WINDOW_SIZE.y - 77.f);
	textGUI.push_back(text);
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

void UserInterface::InitRectShapesUpgradeMenu() {
	rectShapesUpgradeMenu.clear();
	sf::RectangleShape rect;
	SetBothColor(rect, sf::Color::Black, sf::Color::White);
	rect.setSize({WINDOW_SIZE.x - 40.f , WINDOW_SIZE.y / 4.f - 25.f });
	rect.setOrigin({ rect.getSize().x / 2.f ,rect.getSize().y / 2.f });
	rect.setPosition({ WINDOW_SIZE.x / 2.f,
		WINDOW_SIZE.y * (1.f / 4.f) - rect.getSize().y /2.f - 10.f });
	rectShapesUpgradeMenu.push_back(Button(rect, &UpgadeSpeed));
	rect.setPosition({ WINDOW_SIZE.x / 2.f,
		WINDOW_SIZE.y * (2.f / 4.f) - rect.getSize().y / 2.f - 10.f });
	rectShapesUpgradeMenu.push_back(Button(rect, &UpgadeDamage));
	rect.setPosition({ WINDOW_SIZE.x / 2.f,
		WINDOW_SIZE.y * (3.f / 4.f) - rect.getSize().y / 2.f - 10.f });
	rectShapesUpgradeMenu.push_back(Button(rect, &UpgadeHealth));
	rect.setPosition({ WINDOW_SIZE.x / 2.f,
		WINDOW_SIZE.y * (4.f / 4.f) - rect.getSize().y / 2.f - 10.f });
	rectShapesUpgradeMenu.push_back(Button(rect, &Mutate));
}

void UserInterface::InitTextUpgradeMenu() {
	textUpgradeMenu.clear();
	sf::Text text;
	text.setFont(*gameFont);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setPosition({ 40.f, 100.f });
	text.setString("Speed Upgrade");
	textUpgradeMenu.push_back(text);
	text.setPosition({ 40.f, 350.f });
	text.setString("Damage Upgrade");
	textUpgradeMenu.push_back(text);
	text.setPosition({ 40.f, 600.f });
	text.setString("Health Upgrade");
	textUpgradeMenu.push_back(text);
	if ((int)game->pPlayer->currentMutation + 1 <= game->pPlayer->currentLvl / 5.f)
	{
		text.setPosition({ WINDOW_SIZE.x / 2.f - 70.f,850.f });
		text.setString("Mutate");
	}
	else
	{
		text.setPosition({ WINDOW_SIZE.x / 2.f - 180.f,850.f });
		text.setString("Mutation Impossible");
	}
	textUpgradeMenu.push_back(text);
}

void UserInterface::InitRectShapesDeathMenu()
{
	rectShapesDeathMenu.clear();
	sf::RectangleShape rect;
	rect.setSize(*rectMainMenuSize);
	SetBothColor(rect, sf::Color::Black, sf::Color::White);
	rect.setOrigin({ rect.getSize().x / 2.f ,rect.getSize().y / 2.f });
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (2.f / 4.f) });
	rectShapesDeathMenu.push_back(Button(rect, &ButtonReset));
	rect.setPosition({ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) });
	rectShapesDeathMenu.push_back(Button(rect, &ButtonExit));
}

void UserInterface::InitTextDeathMenu()
{
	textDeathMenu.clear();
	sf::Text text;
	text.setFont(*gameFont);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(WINDOW_SIZE / 2.f + sf::Vector2f{ -45.f, -15.f });
	text.setString("Menu");
	textDeathMenu.push_back(text);
	text.setPosition(sf::Vector2f{ WINDOW_SIZE.x / 2.f,WINDOW_SIZE.y * (3.f / 4.f) } + sf::Vector2f{ -45.f, -15.f });
	text.setString("Quit");
	textDeathMenu.push_back(text);
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(100);
	text.setPosition(180, 150);
	text.setString("Score : ");
	textDeathMenu.push_back(text);
}

void SetBothColor(sf::RectangleShape& rect, sf::Color fillColor, sf::Color outLinecolor)
{
	rect.setFillColor(fillColor);
	rect.setOutlineColor(outLinecolor);
	rect.setOutlineThickness(2.f);
}
