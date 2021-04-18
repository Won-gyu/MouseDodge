#pragma once

#include "BaseObject.h"

class Hero : public BaseObject
{
public:
	Hero(int hp = 100, float radius = 20);
	~Hero();

	void Init(int hp, float radius);
	void Update();
	void Render(sf::RenderWindow& window);

private:
	sf::CircleShape circleShape;

	int hp;
	int radius;
};