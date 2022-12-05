#include "EnemyManager.h"

EnemyManager::EnemyManager(sf::RenderWindow* window)
{
	this->activeWindow = window;
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::SpawnEnemy(int amount)
{
	if (!canSpawn)
		return;

	for (int i = 0; i < amount; i++)
	{
		int index = rand() % this->spawnPoints.size();
		this->enemyList.push_back(Enemy(12, this->spawnPoints[index], sf::Color::Yellow, 100.0f, 100.0f, 1.0f, 10.0f));
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
		sf::Vector2f target = { pPlayer->shape.getPosition() + pPlayer->shape.getOrigin() - (*it).shape.getPosition() - (*it).shape.getOrigin()};
		target = Normalize(target);

		(*it).shape.setPosition(sf::Vector2f{ (*it).shape.getPosition().x + target.x * deltaTime * (*it).pEnemyStats->moveSpeed, (*it).shape.getPosition().y + target.y * deltaTime * (*it).pEnemyStats->moveSpeed });
		if (IsOverlappingCircleOnCircle((*it).shape.getPosition(), (*it).shape.getRadius(), pPlayer->shape.getPosition(), pPlayer->shape.getRadius()))
		{
			OnPlayerDeath(pPlayer);
		}
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

void EnemyManager::OnPlayerDeath(Player* player)
{
	this->canSpawn = false;
	player->canMove = false;

	std::list<Enemy>::iterator it = this->enemyList.begin();
	while (it != this->enemyList.end())
	{
		it = enemyList.erase(it);
	}
}
