#pragma once
#include "SFML/Graphics.hpp"
#include "AllData.h"

enum PARTICLE_SYSTEM_TYPE
{
	UPGRADE,
	PLAYER_DAMAGE,
	ENEMY_DAMAGE,
};

class Particle
{
public:
	Particle(sf::Vector2f position, float speed, float lifeDuration,
		sf::Vector2f direction, PARTICLE_SYSTEM_TYPE psType, float timeBeforeStart);
	~Particle();
	void UpdateParticle(float& deltaTime);
	void DisplayParticle(sf::RenderWindow& window);
	bool IsParticleDead();

private:
	float timeToLive;
	float speed;
	float timeBeforeStart;
	float lifeDuration;
	PARTICLE_SYSTEM_TYPE particleType;
	sf::Vector2f direction;
	sf::CircleShape circleShape;
	sf::RectangleShape rectShape;

};

