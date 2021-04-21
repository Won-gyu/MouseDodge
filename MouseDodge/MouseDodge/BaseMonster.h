#pragma once

#include "Global.h"
#include "BaseObject.h"
#include "SFML/Audio.hpp"

class BaseMonster : public BaseObject
{
public:
	BaseMonster(int id = -1, float speedX = 1, float speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseObject(radius, posX, posY)
	{
		Init(id, speedX, speedY, radius);
	}
	~BaseMonster();

	void Init(int id, float speedX, float speedY, float radius);
	void Update(sf::RenderWindow& window);

	virtual void OnUpdate();
	virtual void Render(sf::RenderWindow& window);

	void Die(bool suicide = false);

protected:
	bool checkInBounds(int windowSizeX, int windowSizeY);
	virtual void playDieSound();

	sf::CircleShape circleShape;

	sf::Sound sound;
	sf::SoundBuffer soundBuffer;

	float speedX;
	float speedY;
	int id;
};