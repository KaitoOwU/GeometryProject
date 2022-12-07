#include "EnemyManager.h"
#include "Player.h"
#include "ExpManager.h"

EnemyManager::EnemyManager(sf::RenderWindow* window, ExpManager* pExpManager)
{
	this->activeWindow = window;
	this->pExpManager = pExpManager;

	
	enemyPrefab.clear();
	enemyPrefab.push_back(Enemy(20, {0,0}, 4, 100.0f, 80.0f, 1.0f, 10.0f, pExpManager, this)); // square enemy
	enemyPrefab.push_back(Enemy(25, {0,0}, 6, 100.0f, 100.0f, 1.0f, 10.0f, pExpManager, this)); // hexagone enemy
	enemyPrefab.push_back(Enemy(30, {0,0}, 8, 100.0f, 120.0f, 1.0f, 10.0f, pExpManager, this)); // hoctogone enemy

	enemyList.clear();
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
		int spawnIndex = rand() % this->spawnPoints.size();
		int colorIndex = rand() % this->enemyColor.size();
		int enemyIndex = rand() % this->enemyPrefab.size();

		Enemy newEnemy = enemyPrefab[enemyIndex];
		newEnemy.shape.setFillColor(enemyColor[colorIndex]);
		newEnemy.shape.setPosition(spawnPoints[spawnIndex]);
		
		enemyList.push_back(newEnemy);
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

		(*it).shape.setPosition(sf::Vector2f{ (*it).shape.getPosition().x + target.x * deltaTime * (*it).pEnemyStats.moveSpeed, (*it).shape.getPosition().y + target.y * deltaTime * (*it).pEnemyStats.moveSpeed });
		it++;
		/*if (IsOverlappingCircleOnCircle((*it).shape.getPosition(), (*it).shape.getRadius(), pPlayer->shape.getPosition(), pPlayer->shape.getRadius()))
		{
			(*it).EnemyDeath();
			it = enemyList.erase(it);
		}
		else
		{
			it++;
		}*/
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

	enemyList.clear();

}
