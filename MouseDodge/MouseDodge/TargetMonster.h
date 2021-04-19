#pragma once

#include "BaseMonster.h"

class TargetMonster : public BaseMonster
{
public:
	TargetMonster(double targetDuration = 3, double speedX = 1, double speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseMonster(speedX, speedY, radius, posX, posY)
	{
		Init(targetDuration);
	}
	~TargetMonster();

	void Init(double targetDuration);
	void Update(sf::RenderWindow& window);

private:
	double targetDuration;
};