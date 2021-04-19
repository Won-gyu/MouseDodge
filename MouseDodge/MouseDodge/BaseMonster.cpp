#include "BaseMonster.h"

BaseMonster::~BaseMonster()
{
}

MonsterTypes BaseMonster::getType() const
{
	return this->type;
}

void BaseMonster::Init(float speedX, float speedY, float radius, MonsterTypes type)
{
	this->speedX = speedX;
	this->speedY = speedY;
	this->radius = radius;
	this->type = type;

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
	id = index;

	if (!checkInBounds(window.getSize().x, window.getSize().y))
	{
		Die();
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

void BaseMonster::Die()
{
	Global::OnMonsterDied(id);
}