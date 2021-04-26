#pragma once

#include "BaseMonster.h"

class TeleportMonster : public BaseMonster
{
public:
	TeleportMonster(int id, float speedX = 1, float speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseMonster(id, speedX, speedY, radius, posX, posY)
	{
		Init();
	}
	~TeleportMonster();

	void Init();
	void OnUpdate();
	void Render(sf::RenderWindow& window);
	bool AllowCollision();

private:
	void playDieSound();
	void updateTeleporting();

	sf::Clock clock;
	sf::Clock tpClock;
	sf::CircleShape tpCircleShape1;
	sf::CircleShape tpCircleShape2;
	
	bool teleporting;
	float tpX;
	float tpY;
	bool inTransport;
};