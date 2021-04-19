#pragma once

#include "BaseObject.h"

class BaseMonster : public BaseObject
{
public:
	BaseMonster(float speedX = 1, float speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseObject(radius, posX, posY)
	{
		Init(speedX, speedY, radius);
	}
	~BaseMonster();

	void Init(float speedX, float speedY, float radius);
	virtual void Update(sf::RenderWindow& window);
	virtual void Render(sf::RenderWindow& window);
	bool checkInBounds(int windowSizeX, int windowSizeY);

protected:
	sf::CircleShape circleShape;

	float speedX;
	float speedY;
};