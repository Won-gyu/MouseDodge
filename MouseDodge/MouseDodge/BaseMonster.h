#pragma once

#include "Global.h"
#include "BaseObject.h"
#include "SFML/Audio.hpp"

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
	virtual void initSound();
	void Update(sf::RenderWindow& window, int index);
	virtual void OnUpdate();
	virtual void Render(sf::RenderWindow& window);

	void Die();

protected:
	bool checkInBounds(int windowSizeX, int windowSizeY);

	sf::CircleShape circleShape;
	sf::Sound sound;

	float speedX;
	float speedY;
	int id;
};