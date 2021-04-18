#pragma once

#include <SFML/Graphics.hpp>

class BaseObject
{
public:
	BaseObject(float posX = 0, float posY = 0);
	virtual ~BaseObject();

	virtual void Update() = 0;
	virtual void Render(sf::RenderWindow& window) = 0;

protected:
	float posX;
	float posY;
};