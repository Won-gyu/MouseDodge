#pragma once

#include "BaseMonster.h"

class DynamicMonster : public BaseMonster
{
public:
	DynamicMonster(double sizeSpeed = 1, double speedX = 1, double speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseMonster(speedX, speedY, radius, posX, posY)
	{
		Init(sizeSpeed);
	}
	~DynamicMonster();

	void Init(double sizeSpeed);
	void Update(sf::RenderWindow& window);

private:
	double sizeSpeed;
	int count;
	bool increasing;
};