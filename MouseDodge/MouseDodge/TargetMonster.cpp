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

	// Check if the time is up

	// Find vector pointing to hero

	// Normalize vector

	// set speed towards hero

}

void TargetMonster::updateHeroPosition(float x, float y)
{
	this->heroX = x;
	this->heroY = y;
}