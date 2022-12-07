#include "Health.h"

Health::Health()
{

}

Health::Health(float maxLife)
{
	this->maxLife = maxLife;
	this->currentLife = maxLife;
}

Health::~Health()
{
}

void Health::TakeDamage(float value)
{

	if (value > 0)
	{
		this->currentLife -= value;
		if (this->currentLife < 0)
		{
			this->currentLife = 0;
			delete this;
		}
	}
}

void Health::Heal(float value)
{
	if (value > 0)
	{
		this->currentLife += value;
		if (this->currentLife > this->maxLife)
		{
			this->currentLife = this->maxLife;
		}
	}
}
