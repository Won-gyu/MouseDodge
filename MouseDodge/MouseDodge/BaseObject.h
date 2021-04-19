#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class BaseObject
{
public:
	BaseObject(float radius = 0, float posX = 0, float posY = 0);
	virtual ~BaseObject();

	virtual void Update(sf::RenderWindow& window) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;

	float GetRadius();
	float GetPosX();
	float GetPosY();

protected:
	float posX;
	float posY;
	float radius;
};