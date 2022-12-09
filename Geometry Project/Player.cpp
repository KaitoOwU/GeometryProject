#include "Player.h"
#include "Game.h";
#include <iostream>
#include <cmath>

Player::Player(float size, float movementSpeed, sf::Vector2f initialPosition, sf::Color color, sf::RenderWindow* window, Game* game)
{
	sf::CircleShape shape;
	shape.setRadius(size);
	this->shape.setOrigin(this->shape.getRadius() / 2, this->shape.getRadius() / 2);
	shape.setPosition(initialPosition);
	shape.setFillColor(color);

	this->shape = shape;
	this->movementSpeed = movementSpeed;
	this->activeWindow = window;
	this->game = game;
}

Player::~Player()
{
}

void Player::ComputeIfNextLevel()
{
	if (xpRequired.find(currentLvl + 1) == xpRequired.end())
		return;

	if (currentXP >= xpRequired[currentLvl + 1]) {
		currentLvl++;
		currentXP -= xpRequired[currentLvl];
		game->OpenUpgradeMenu();
	}
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
				py -= (this->movementSpeed * deltaTime * speedMultiplier);
				break;
			case Player::Down:
				py += (this->movementSpeed * deltaTime * speedMultiplier);
				break;
			case Player::Right:
				px += (this->movementSpeed * deltaTime * speedMultiplier);
				break;
			case Player::Left:
				px -= (this->movementSpeed * deltaTime * speedMultiplier);
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

			for (int i = 0; i < numberOfBalls; i++) {
				PlayerCircleProjectile* proj = new PlayerCircleProjectile(projectileDir, &deltaTime);
				proj->shape.setFillColor(sf::Color::Magenta);
				proj->shape.setRadius(10.f);
				sf::Vector2f spawnPos;
				if (abs(target.x) > abs(target.y)) {
					spawnPos = { shape.getPosition().x, shape.getPosition().y + 25 * i };
				}
				else {
					spawnPos = { shape.getPosition().x + 25 * i , shape.getPosition().y };
				}
				proj->shape.setPosition(spawnPos);
				this->circleProjList.push_back(proj);
			}
			break;
		}
		case Triangle: {
			if (triangleProjList.size() >= 5) {
				return;
			}

			shootCooldown = 3.f;

			PlayerTriangleProjectile* proj = new PlayerTriangleProjectile(&deltaTime);
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

void Player::MutateToNextState()
{
	float currentMutationInt = (float)currentMutation + 1;
	currentMutation = (Mutation)Clamp(currentMutationInt, 0, 4);

	switch (currentMutation) {
	case MonoShot: {
		numberOfBalls = 1;
		break;
	}
	case DoubleShot: {
		numberOfBalls = 2;
		break;
	}
	case QuadraShot: {
		numberOfBalls = 4;
		break;
	}
	case TriangleMaster: {
		projectileType = ActiveProjectileType::Triangle;
		numberOfBalls = 1;
		break;
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