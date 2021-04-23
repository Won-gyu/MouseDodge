#include "FastMonster.h"

FastMonster::~FastMonster()
{
}

void FastMonster::Init(float speedMultiplier)
{
	circleShape.setFillColor(sf::Color::Red);

	// Adjust speed so it's directed at hero (like first part of TargetMonster)
	sf::Vector2f heroPos = Global::getHeroPosition();
	sf::Vector2f goalVector(heroPos.x - posX, heroPos.y - posY);
	float goalVectorMagnitude = sqrt(pow(goalVector.x, 2) + pow(goalVector.y, 2));
	sf::Vector2f normGoalVector(goalVector.x / goalVectorMagnitude, goalVector.y / goalVectorMagnitude);
	// Set speed
	speedX = normGoalVector.x * speedMultiplier * 1000;
	speedY = normGoalVector.y * speedMultiplier * 1000;
}

void FastMonster::OnUpdate()
{
	// Do default update tasks
	BaseMonster::OnUpdate();
}

void FastMonster::playDieSound()
{
	Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_FAST_MONSTER_DIE);
}