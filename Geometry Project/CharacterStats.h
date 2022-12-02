#pragma once
class CharacterStats
{
public:
	CharacterStats(float moveSpeed, float attackSpeed, float damage);
	~CharacterStats();

	void CharacterBuff(float& statToBuff, float buffValue, bool isTempBuff, float buffDuration);

	float moveSpeed = 0;
	float attackSpeed = 0;
	float damage = 0;

private:

};

