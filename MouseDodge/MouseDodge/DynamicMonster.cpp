#include "DynamicMonster.h"

DynamicMonster::~DynamicMonster()
{
}

void DynamicMonster::Init(double sizeSpeed)
{
	this->sizeSpeed = sizeSpeed;
	this->increasing = true;
	this->count = 0;

	circleShape.setFillColor(sf::Color::Cyan);
}

void DynamicMonster::Update(sf::RenderWindow& window)
{
	// Do default update tasks
	BaseMonster::Update(window);

	if (increasing)
	{
		count++;
		radius += sizeSpeed;
		if (count > 1000)
		{
			increasing = false;
		}
	}
	else
	{
		count--;
		radius -= sizeSpeed;
		if (count < 0)
		{
			increasing = true;
		}
	}
	circleShape.setRadius(radius);
}