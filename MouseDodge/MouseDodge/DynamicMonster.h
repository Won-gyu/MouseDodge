#pragma once

#include "BaseMonster.h"

class BaseMonster;
class DynamicMonster : public BaseMonster
{
public:
	DynamicMonster(int id, float sizeSpeed = 1, float speedX = 1, float speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseMonster(id, speedX, speedY, radius, posX, posY)
	{
		Init(sizeSpeed);
	}
	~DynamicMonster();

	void Init(float sizeSpeed);
	//void initSound();
	void OnUpdate();

private:
	float sizeSpeed;
	int count;
	bool increasing;
};