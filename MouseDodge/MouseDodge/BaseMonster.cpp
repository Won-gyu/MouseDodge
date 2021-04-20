#include "BaseMonster.h"

BaseMonster::~BaseMonster()
{
}

void BaseMonster::Init(int id, float speedX, float speedY, float radius)
{
	this->id = id;
	this->speedX = speedX;
	this->speedY = speedY;
	this->radius = radius;

	circleShape.setRadius(radius);

	initSound();
}

void BaseMonster::initSound()
{
	if (soundBuffer.loadFromFile("FastMonster_die.wav"))
	{
		sound.setBuffer(soundBuffer);
	}
}

void BaseMonster::OnUpdate()
{
	posX += speedX;
	posY += speedY;
	circleShape.setPosition(posX - radius, posY - radius);
}

void BaseMonster::Update(sf::RenderWindow& window)
{
	OnUpdate();

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
	// Play death sound
	sound.play();

	Global::OnMonsterDied(id);
}