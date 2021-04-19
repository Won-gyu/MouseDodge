#include "BaseMonster.h"

BaseMonster::~BaseMonster()
{
}

void BaseMonster::Init(float speedX, float speedY, float radius)
{
	this->speedX = speedX;
	this->speedY = speedY;
	this->radius = radius;

	circleShape.setRadius(radius);
}

void BaseMonster::OnUpdate()
{
	posX += speedX;
	posY += speedY;
	circleShape.setPosition(posX - radius, posY - radius);
}

void BaseMonster::Update(sf::RenderWindow& window, int index)
{
	OnUpdate();

	if (!checkInBounds(800, 600))
	{
		Global::OnMonsterDied(index);
	}
}

void BaseMonster::Render(sf::RenderWindow& window)
{
	window.draw(circleShape);
}

bool BaseMonster::checkInBounds(int windowSizeX, int windowSizeY)
{
	if (posX - radius > windowSizeX || posX + radius < 0 ||
		posY - radius > windowSizeY || posY + radius < 0)
	{
		return false;
	}
	return true;
}