#include "ParticleSystem.h"

const int nbParticlesUpgrade = 20;


const int nbParticlesPlayerDamage = 30;

const int nbParticlesEnemyDamage = 5;


ParticleSystem::ParticleSystem(PARTICLE_SYSTEM_TYPE type, sf::Vector2f position, sf::Vector2f direction)
{
	psType = type;
	psPosition = position;
	psDirection = direction;
	switch (type)
	{
	case UPGRADE:
		for (int i = 0; i < nbParticlesUpgrade; i++)
		{
			
		}
		break;
	case PLAYER_DAMAGE:
		for (int i = 0; i < nbParticlesPlayerDamage; i++)
		{
			allParticles.push_back(Particle(position, 100, .5f, 
				ConvertAngleToDirection(i * 360.f / nbParticlesPlayerDamage, true, true),
				type, 0.f));
			allParticles.push_back(Particle(position, 100, .5f,
				ConvertAngleToDirection(i * 360.f / nbParticlesPlayerDamage, true, true),
				type, 0.25f));
			allParticles.push_back(Particle(position, 100, .5f,
				ConvertAngleToDirection(i * 360.f / nbParticlesPlayerDamage, true, true),
				type, 0.5f));
		}
		break;
	case ENEMY_DAMAGE:
		for (int i = 0; i < nbParticlesEnemyDamage; i++)
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
