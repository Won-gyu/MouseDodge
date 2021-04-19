#include "DynamicMonster.h"

DynamicMonster::~DynamicMonster()
{
}

void DynamicMonster::Init(float sizeSpeed)
{
	this->sizeSpeed = sizeSpeed;
	this->increasing = true;
	this->count = 0;

	circleShape.setFillColor(sf::Color::Cyan);
}

void DynamicMonster::OnUpdate()
{
	// Do default update tasks
	BaseMonster::OnUpdate();

	// Dynamic update tasks
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