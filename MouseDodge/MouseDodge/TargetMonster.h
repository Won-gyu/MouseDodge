#pragma once

#include "BaseMonster.h"

class TargetMonster : public BaseMonster
{
public:
	TargetMonster(float targetDuration = 3, float speedX = 1, float speedY = 1,
		MonsterTypes type = MonsterTypes::TARGET, float radius = 10, float posX = 0, float posY = 0) :
		BaseMonster(speedX, speedY, type, radius, posX, posY)
	{
		Init(targetDuration);
	}
	~TargetMonster();

	void Init(float targetDuration);
	void OnUpdate();
	void updateHeroPosition(float x, float y);

private:
	sf::Clock clock;

	float targetDuration;
	float heroX;
	float heroY;
};