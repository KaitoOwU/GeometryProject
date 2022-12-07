#include "ParticleSystem.h"

const int nbParticlesUpgrade = 40;

const int nbParticlesPlayerDamage = 30;

const int nbParticlesEnemyDamage = 5;


ParticleSystem::ParticleSystem(PARTICLE_SYSTEM_TYPE type,
	sf::Vector2f position, sf::Vector2f direction, sf::Color color)
{
	psType = type;
	psPosition = position;
	psDirection = direction;
	this->color = color;
	switch (type)
	{
	case UPGRADE:
		for (int i = 0; i < nbParticlesEnemyDamage; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				allParticles.push_back(Particle(position,.01f, .5f,
					direction, type, y * 0.25f, color));
			}
		}
		break;
	case PLAYER_DAMAGE:
		for (int i = 0; i < nbParticlesPlayerDamage; i++)
		{
			for (int y = 0; y < 3; y++)
			{
				allParticles.push_back(Particle(position, 100, .5f,
					ConvertAngleToDirection(i * 360.f / nbParticlesPlayerDamage, true, true),
					type, y * 0.25f));
			}
		}
		break;
	case ENEMY_DAMAGE:
		for (int i = 0; i < nbParticlesUpgrade; i++)
		{
			
		}
		break;
	default:
		break;
	}
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::UpdateParticleSystem(float& deltaTime)
{
	std::list<Particle>::iterator it = allParticles.begin();
	while (it != allParticles.end())
	{
		if (it->IsParticleDead())
		{
			it = allParticles.erase(it);
		}
		else
		{
			it->UpdateParticle(deltaTime);
			it++;
		}
	}
}

void ParticleSystem::DisplayParticleSystem(sf::RenderWindow& window)
{
	std::list<Particle>::iterator it = allParticles.begin();
	while (it != allParticles.end())
	{
		it->DisplayParticle(window);
		it++;
	}
}

bool ParticleSystem::IsAllParticlesEmpty()
{
	return allParticles.size() == 0;
}
