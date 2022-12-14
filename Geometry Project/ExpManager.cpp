#include "ExpManager.h"
#include "Game.h"


ExpManager::ExpManager(sf::RenderWindow* window, Game* game)
{
	this->activeWindow = window;
	this->pGame = game;
}

ExpManager::~ExpManager()
{
}

void ExpManager::DrawExperience()
{
	std::list<Exp>::iterator it = experienceOrbList.begin();
	while (it != experienceOrbList.end())
	{
		activeWindow->draw((*it).shape);
		it++;
	}
}

void ExpManager::ExpTrackPlayer(Player* pPlayer, float& deltaTime)
{
	if (this->experienceOrbList.size() <= 0) {
		return;
	}

	std::list<Exp>::iterator it = this->experienceOrbList.begin();
	while (it != this->experienceOrbList.end())
	{
		if (IsOverlappingCircleOnCircle((*it).shape.getPosition(), (*it).shape.getRadius() * 15, pPlayer->shape.getPosition(), pPlayer->shape.getRadius()))
		{
			sf::Vector2f target = { pPlayer->shape.getPosition() + pPlayer->shape.getOrigin() - (*it).shape.getPosition() - (*it).shape.getOrigin() };
			target = Normalize(target);
			(*it).shape.setPosition(sf::Vector2f{ (*it).shape.getPosition().x + target.x * deltaTime * 30.0f, (*it).shape.getPosition().y + target.y * deltaTime * 30.0f });
		}

		if (IsOverlappingCircleOnCircle((*it).shape.getPosition(), (*it).shape.getRadius(), pPlayer->shape.getPosition(), pPlayer->shape.getRadius()))
		{
			pGame->IncreaseXP(it->expValue);
			it = experienceOrbList.erase(it);
		}
		else
		{
			it++;
		}
	}
}
