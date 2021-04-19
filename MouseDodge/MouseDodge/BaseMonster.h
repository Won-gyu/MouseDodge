#pragma once

#include "BaseObject.h"

class BaseMonster : public BaseObject
{
public:
	BaseMonster(double speedX = 1, double speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseObject(posX, posY)
	{
		Init(speedX, speedY, radius);
	}
	~BaseMonster();

	void Init(double speedX, double speedY, float radius);
	virtual void Update(sf::RenderWindow& window);
	virtual void Render(sf::RenderWindow& window);
	bool checkInBounds(int windowSizeX, int windowSizeY);

protected:
	sf::CircleShape circleShape;

	double speedX;
	double speedY;
	float radius;
};