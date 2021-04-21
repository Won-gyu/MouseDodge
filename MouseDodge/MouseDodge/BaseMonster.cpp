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
		Die(true);
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


void BaseMonster::playDieSound()
{
	Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_MONSTER_DIE);
}

void BaseMonster::Die(bool suicide)
{
	// Play death sound
	if (!suicide)
	{
		playDieSound();
	}

	Global::OnMonsterDied(id);
}