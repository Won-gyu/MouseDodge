#include "DynamicMonster.h"

DynamicMonster::~DynamicMonster()
{
}

void DynamicMonster::Init(float sizeSpeed)
{
	this->sizeSpeed = sizeSpeed * 1000.0f;
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
		radius += sizeSpeed * Global::deltaTime;
		if (count > 1000)
		{
			increasing = false;
		}
	}
	else
	{
		count--;
		radius -= sizeSpeed * Global::deltaTime;
		if (count < 0)
		{
			increasing = true;
		}
	}
	circleShape.setRadius(radius);
}

void DynamicMonster::playDieSound()
{
	Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_DYNAMIC_MONSTER_DIE);
}