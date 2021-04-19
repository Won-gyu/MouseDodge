#include "TargetMonster.h"

TargetMonster::~TargetMonster()
{
}

void TargetMonster::Init(float targetDuration)
{
	this->targetDuration = targetDuration;
	this->heroX = 0;
	this->heroY = 0;

	this->clock.restart();
}

void TargetMonster::OnUpdate()
{
	// Do default update tasks
	BaseMonster::OnUpdate();

	// Only change direction if within the target duration
	if (clock.getElapsedTime().asSeconds() < targetDuration)
	{
		sf::Vector2f heroPos = Global::getHeroPosition();

		// Find vector pointing to hero

		// Normalize vector

		// set speed towards hero
	}
}

void TargetMonster::updateHeroPosition(float x, float y)
{
	this->heroX = x;
	this->heroY = y;
}