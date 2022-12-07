#include "Player.h"
#include <iostream>
#include <cmath>

Player::Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, sf::RenderWindow* window, EnemyManager* pEnemyManager)
{
	sf::CircleShape shape;
	shape.setRadius(size);
	this->shape.setOrigin(this->shape.getRadius() / 2, this->shape.getRadius() / 2);
	shape.setPosition(initialPosition);
	shape.setFillColor(color);

	this->shape = shape;
	this->movementSpeed = movementSpeed;
	this->activeWindow = window;
	this->pEnemyManager = pEnemyManager;
}

Player::~Player()
{
}

void Player::Move(std::map<sf::Keyboard::Key, bool>& inputs, float& deltaTime)
{
	if (!this->canMove)
		return;

	float px = shape.getPosition().x;
	float py = shape.getPosition().y;

	auto it = inputs.begin();
	while (it != inputs.end()) {
		if (it->second) {
			switch ((Player::MovementDirection) it->first) {
			case Player::Up:
				py -= (this->movementSpeed *deltaTime);
				break;
			case Player::Down:
				py += (this->movementSpeed * deltaTime);
				break;
			case Player::Right:
				px += (this->movementSpeed * deltaTime);
				break;
			case Player::Left:
				px -= (this->movementSpeed * deltaTime);
				break;
			}
		}
		it++;
	}

	this->shape.setPosition(
		Clamp(px, 20, WINDOW_SIZE.x - 20),
		Clamp(py, 20, WINDOW_SIZE.y - 20)
	);
}

void Player::Shoot(std::map<sf::Keyboard::Key, bool>& inputs, float& deltaTime) {
	if (shootCooldown <= 0 && inputs[sf::Keyboard::Key::Space]) {
		switch (projectileType) {
		case Circle: {
			shootCooldown = 1.f;
			sf::Vector2f target = (sf::Vector2f) sf::Mouse::getPosition(*activeWindow);
			sf::Vector2f playerPos = shape.getPosition();
			target = target - playerPos;
			sf::Vector2f projectileDir = Normalize(target);

			PlayerCircleProjectile* proj = new PlayerCircleProjectile(projectileDir, &deltaTime, pEnemyManager);
			proj->shape.setFillColor(sf::Color::Magenta);
			proj->shape.setRadius(10.f);
			proj->shape.setPosition(shape.getPosition());
			this->circleProjList.push_back(proj);
			break;
		}
		case Triangle: {
			if (triangleProjList.size() >= 5) {
				return;
			}

			shootCooldown = 3.f;

			PlayerTriangleProjectile* proj = new PlayerTriangleProjectile(&deltaTime, pEnemyManager);
			proj->shape.setFillColor(sf::Color::Magenta);
			proj->shape.setPosition(shape.getPosition());
			proj->shape.setPointCount(3);
			proj->shape.setRadius(15.f);

			triangleProjList.push_back(proj);
			std::cout << triangleProjList.size();
		}
		}
	}
}

void Player::SetProjectileMode(ActiveProjectileType type)
{
	this->projectileType = type;
	circleProjList.clear();
}

void Player::UpdateProjectile(float& deltaTime) {
	switch (projectileType) {
	case Circle: {
		auto it = circleProjList.begin();
		while (it != circleProjList.end()) {
			(*it)->shape.move(((*it)->direction) / 4.f);
			(*it)->lifeDuration -= deltaTime;
			if ((*it)->lifeDuration <= 0) {
				it = circleProjList.erase(it);
				continue;
			}
			it++;
		}
		return;
	}
	case Triangle: {
		auto it = triangleProjList.begin();
		while (it != triangleProjList.end()) {
			sf::Vector2f target = (sf::Vector2f) sf::Mouse::getPosition(*activeWindow);
			sf::Vector2f trianglePos = (*it)->shape.getPosition();
			target = target - trianglePos;
			sf::Vector2f projectileDir = Normalize(target);
			
			(*it)->shape.move(projectileDir / 10.f);
			it++;
		}
		return;
	}
	}
}

void Player::DisplayProjectile(sf::RenderWindow& window)
{
	auto it = circleProjList.begin();
	while (it != circleProjList.end()) {
		window.draw((*it)->shape);
		it++;
	}

	auto it2 = triangleProjList.begin();
	while (it2 != triangleProjList.end()) {
		window.draw((*it2)->shape);
		it2++;
	}
}

void Player::Display(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Player::DetectProjectilCollision()
{
	if (circleProjList.size() <= 0 || pEnemyManager->enemyList.size() <= 0)
		return;


	std::list<PlayerCircleProjectile*>::iterator it = circleProjList.begin();
	while (it != circleProjList.end())
	{
		std::list<Enemy>::iterator eit = pEnemyManager->enemyList.begin();
		while (eit != pEnemyManager->enemyList.end())
		{
			if (IsOverlappingCircleOnCircle((*it)->shape.getPosition(), (*it)->shape.getRadius(), (*eit).shape.getPosition(), (*eit).shape.getRadius()))
			{
				//it = circleProjList.erase(it);
				(*eit).pEnemyHealth.TakeDamage(1);
				std::cout << "oui oui baguette" << std::endl;
				break;
			}
			else
			{
				eit++;
			}
		}
		it++;
	}
}