#pragma once

#include "BaseMonster.h"

class FastMonster : public BaseMonster
{
public:
	FastMonster(int id, float speedMultiplier, float speedX = 1, float speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseMonster(id, speedX, speedY, radius, posX, posY)
	{
		Init(speedMultiplier);
	}
	~FastMonster();

	void Init(float speedMultiplier);
	void OnUpdate();

private:
	void playDieSound();
};