#include "TargetMonster.h"

TargetMonster::~TargetMonster()
{
}

void TargetMonster::Init(double targetDuration)
{
	this->targetDuration = targetDuration;
}

void TargetMonster::Update(sf::RenderWindow& window)
{
	// Do default update tasks
	BaseMonster::Update(window);



}