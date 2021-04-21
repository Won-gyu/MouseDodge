#include "BaseMonster.h"

BaseMonster::~BaseMonster()
{
}

void BaseMonster::Init(int id, float speedX, float speedY, float radius)
{
	this->id = id;
	this->speedX = speedX * 1000.0f;
	this->speedY = speedY * 1000.0f;
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
	posX += speedX * Global::deltaTime;
	posY += speedY * Global::deltaTime;
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