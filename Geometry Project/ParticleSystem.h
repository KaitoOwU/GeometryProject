#pragma once
#include "Particle.h"
#include "SFML/Graphics.hpp"
#include <list>

class ParticleSystem
{
public:
	ParticleSystem(PARTICLE_SYSTEM_TYPE type, sf::Vector2f position,
		sf::Vector2f direction = {0.f,-1.f}, sf::Color color = sf::Color::Transparent);
	~ParticleSystem();
	void UpdateParticleSystem(float& deltaTime);
	void DisplayParticleSystem(sf::RenderWindow& window);
	bool IsAllParticlesEmpty();

private:
	std::list<Particle> allParticles;
	PARTICLE_SYSTEM_TYPE psType;
	sf::Vector2f psPosition;
	sf::Vector2f psDirection;
	sf::Color color;
};
