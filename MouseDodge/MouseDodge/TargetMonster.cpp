#include "TargetMonster.h"

TargetMonster::~TargetMonster()
{
}

void TargetMonster::Init(float targetDuration, float speedMultiplier)
{
	this->targetDuration = targetDuration;
	this->speedMultiplier = speedMultiplier;

	this->clock.restart();
	circleShape.setFillColor(sf::Color::Green);
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
		sf::Vector2f difVector(heroPos.x - posX, heroPos.y - posY);

		// Normalize vector
		float distance = sqrt(pow(difVector.x, 2) + pow(difVector.y, 2));
		sf::Vector2f normalizedVector(difVector.x / distance, difVector.y / distance);

		// set speed towards hero
		this->speedX = normalizedVector.x * speedMultiplier;
		this->speedY = normalizedVector.y * speedMultiplier;
	}
}