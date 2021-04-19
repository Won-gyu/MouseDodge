#include "BaseMonster.h"

BaseMonster::~BaseMonster()
{
}

void BaseMonster::Init(double speedX, double speedY, float radius)
{
	this->speedX = speedX;
	this->speedY = speedY;
	this->radius = radius;

	circleShape.setRadius(radius);
	circleShape.setFillColor(sf::Color::White);
}

void BaseMonster::Update(sf::RenderWindow& window)
{
	posX += speedX;
	posY += speedY;
	printf("%lf %lf\n", posX, posY);
	circleShape.setPosition(posX - radius, posY - radius);
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