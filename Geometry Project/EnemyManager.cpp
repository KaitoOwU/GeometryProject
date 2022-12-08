#include "EnemyManager.h"

EnemyManager::EnemyManager(sf::RenderWindow* window, ExpManager* pExpManager)
{
	this->activeWindow = window;
	this->pExpManager = pExpManager;

	
	enemyPrefab.clear();
	enemyPrefab.push_back(Enemy(20, {0,0}, 4, 10.0f, 80.0f, 1.0f, 10.0f, pExpManager)); // square enemy
	enemyPrefab.push_back(Enemy(25, {0,0}, 6, 15.0f, 100.0f, 1.0f, 10.0f, pExpManager)); // hexagone enemy
	enemyPrefab.push_back(Enemy(30, {0,0}, 8, 20.0f, 120.0f, 1.0f, 10.0f, pExpManager)); // hoctogone enemy


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
		int colorIndex = rand() % this->enemyColor.size();
		int enemyIndex = rand() % this->enemyPrefab.size();

		Enemy newEnemy = enemyPrefab[enemyIndex];
		newEnemy.shape.setFillColor(enemyColor[colorIndex]);
		sf::Vector2f position;
		if (rand()%2 == 0)
		{
			position.x = rand() % ((int)WINDOW_SIZE.x + 1);
			position.y = rand() % 2 == 0 ? 0 : WINDOW_SIZE.y;
		}
		else
		{
			position.y = rand() % ((int)WINDOW_SIZE.x + 1);
			position.x = rand() % 2 == 0 ? 0 : WINDOW_SIZE.y;
		}
		newEnemy.shape.setPosition(position);
		
		enemyList.push_back(newEnemy);
	}

}

void EnemyManager::WaveManager(float &deltaTime)
{
	if (init)
	{
		init = false;
		SpawnEnemy(initEnemyWave);
		currentWaveTime = maxTime;
	}

	currentWaveTime -= deltaTime;

	if (currentWaveTime <= 0 || enemyList.size() <= 0)
	{
		currentWaveTime = maxTime;
		float value = initEnemyWave * enemyMultiplicator;

		value = Clamp(value, 0, maxEnemyPerWave);
		SpawnEnemy((int)value);
	}

	

}

void EnemyManager::EnemyManagerUpdate(Player *pPlayer, float &deltaTime)
{
	WaveManager(deltaTime);

	if (this->enemyList.size() <= 0) {
		return;
	}

	std::list<Enemy>::iterator it = this->enemyList.begin();
	while (it != this->enemyList.end())
	{
		sf::Vector2f target = { pPlayer->shape.getPosition() + pPlayer->shape.getOrigin() - (*it).shape.getPosition() - (*it).shape.getOrigin()};
		target = Normalize(target);

		(*it).enemyDamageCoolDown -= deltaTime;

		(*it).shape.setPosition(sf::Vector2f{ (*it).shape.getPosition().x + target.x * deltaTime * (*it).pEnemyStats.moveSpeed, (*it).shape.getPosition().y + target.y * deltaTime * (*it).pEnemyStats.moveSpeed });
		if (IsOverlappingCircleOnCircle((*it).shape.getPosition(), (*it).shape.getRadius(), pPlayer->shape.getPosition(), pPlayer->shape.getRadius()))
		{
			//blabla
			it++;
		}
		else if ((*it).pEnemyHealth.currentLife <= 0)
		{
			(*it).EnemyDeath();
			it = enemyList.erase(it);
		}
		else
		{
			it++;
		}
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

