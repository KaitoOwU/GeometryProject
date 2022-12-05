#include "CharacterStats.h"


CharacterStats::CharacterStats(float moveSpeed, float attackSpeed, float damage)
{
	this->moveSpeed = moveSpeed;
	this->attackSpeed = attackSpeed;
	this->damage = damage;
}

CharacterStats::~CharacterStats()
{
}

void CharacterStats::CharacterBuff(float &statToBuff, float buffValue, bool isTempBuff, float buffDuration = 1.0f)
{
	if (buffValue > 0)
	{
		statToBuff += buffValue;
	}
}
