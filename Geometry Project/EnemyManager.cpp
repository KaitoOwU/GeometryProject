#include "EnemyManager.h"

EnemyManager::EnemyManager(sf::RenderWindow &window)
{
	this->activeWindow = &window;
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::SpawnEnemy(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		float y = i * 100;
		this->enemyList.push_back(Enemy(12, { y, 100 }, sf::Color::Yellow, 100.0f, 100.0f, 1.0f, 10.0f));
	}
}

void EnemyManager::TrackPlayer(Player *pPlayer, float &deltaTime)
{
	if (this->enemyList.size() <= 0) {
		return;
	}

	std::list<Enemy>::iterator it = this->enemyList.begin();
	while (it != this->enemyList.end())
	{
		sf::Vector2f target = { pPlayer->shape.getPosition().x - (*it).shape.getPosition().x + pPlayer->shape.getOrigin().x * 1.25f, pPlayer->shape.getPosition().y - (*it).shape.getPosition().y + pPlayer->shape.getOrigin().y * 1.25f };
		target = Normalize(target);

		(*it).shape.setPosition(sf::Vector2f{ (*it).shape.getPosition().x + target.x * deltaTime * (*it).pEnemyStats->moveSpeed, (*it).shape.getPosition().y + target.y * deltaTime * (*it).pEnemyStats->moveSpeed });
		it++;
	}
}

void EnemyManager::DrawEnemy()
{
	if (this->enemyList.size() <= 0) {
		return;
	}

	std::list<Enemy>::iterator it = this->enemyList.begin();
	while (it != this->enemyList.end())
	{
		this->activeWindow->draw((*it).shape);
		it++;
	}
}
