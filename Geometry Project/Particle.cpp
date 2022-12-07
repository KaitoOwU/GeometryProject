#include "Particle.h"



Particle::Particle(sf::Vector2f position, float speed, float lifeDuration,
	sf::Vector2f direction, PARTICLE_SYSTEM_TYPE psType, float timeBeforeStart = 0.f)
{
	this->speed = speed;
	this->lifeDuration = lifeDuration;
	this->timeToLive = lifeDuration;
	this->direction = direction;
	this->timeBeforeStart = timeBeforeStart;
	particleType = psType;
	switch (particleType)
	{
	case UPGRADE:
		break;
	case PLAYER_DAMAGE:
		rectShape = sf::RectangleShape({10.f, 2.f});
		rectShape.setPosition(position);
		rectShape.setOrigin(rectShape.getSize() / 2.f);
		rectShape.setRotation(RadianToDegree(atan2(direction.y, direction.x)));
		rectShape.setFillColor(sf::Color::Red);
		break;
	case ENEMY_DAMAGE:
		break;
	default:
		break;
	}
}

Particle::~Particle()
{
}

void Particle::UpdateParticle(float& deltaTime)
{
	if (timeBeforeStart > 0) 
	{
		timeBeforeStart -= deltaTime;
		return;
	}
	timeToLive -= deltaTime;
	switch (particleType)
	{
	case UPGRADE:
		break;
	case PLAYER_DAMAGE:
		rectShape.setPosition(rectShape.getPosition() + direction  * speed * deltaTime);
		break;
	case ENEMY_DAMAGE:
		break;
	default:
		break;
	}
}

void Particle::DisplayParticle(sf::RenderWindow& window)
{
	if (timeBeforeStart > 0) return;
	switch (particleType)
	{
	case UPGRADE:
		window.draw(circleShape);
		break;
	case PLAYER_DAMAGE:
	case ENEMY_DAMAGE:
		window.draw(rectShape);
		break;
	default:
		break;
	}
}

bool Particle::IsParticleDead()
{
	return timeToLive <= 0;
}
