#include "DynamicMonster.h"

DynamicMonster::~DynamicMonster()
{
}

void DynamicMonster::Init(double sizeSpeed)
{
	this->sizeSpeed = sizeSpeed;
}

void DynamicMonster::Update(sf::RenderWindow& window)
{
	// Do default update tasks
	BaseMonster::Update(window);

	radius += sizeSpeed;
	circleShape.setRadius(radius);
}