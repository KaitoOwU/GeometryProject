#pragma once

class Health
{
public:
	Health(float maxLife);
	~Health();

	void TakeDamage(float value);
	void Heal(float value);

	float maxLife = 0;
	float currentLife = 0;

private:

};

