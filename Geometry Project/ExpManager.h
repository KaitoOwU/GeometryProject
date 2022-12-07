#pragma once
#include "AllData.h"
#include <list>
#include "Exp.h"
#include "Player.h"

class ExpManager
{
public:
	ExpManager(sf::RenderWindow* window);
	~ExpManager();

	sf::RenderWindow* activeWindow = nullptr;
	std::list<Exp> experienceOrbList;

	void DrawExperience();
	void ExpTrackPlayer(Player* pPlayer, float& deltaTime);

private:

};
