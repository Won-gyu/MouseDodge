#include "TargetMonster.h"

TargetMonster::~TargetMonster()
{
}

void TargetMonster::Init(float maxSteeringAdjustment, float targetDuration, float speedMultiplier, float speedX, float speedY)
{
	this->targetDuration = targetDuration;
	this->speedMultiplier = speedMultiplier * 1000.0f;
	this->maxSteeringAdjustment = maxSteeringAdjustment;

	float length = sqrt(pow(speedX, 2) + pow(speedY, 2));
	sf::Vector2f normDirectionVector(speedX / length, speedY / length);
	directionVector = normDirectionVector;

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

		// Find vector pointing to hero (Our goal target)
		sf::Vector2f goalVector(heroPos.x - posX, heroPos.y - posY);

		// Normalize vector
		float goalVectorMagnitude = sqrt(pow(goalVector.x, 2) + pow(goalVector.y, 2));
		sf::Vector2f normGoalVector(goalVector.x / goalVectorMagnitude, goalVector.y / goalVectorMagnitude);

		// Find steering vector (difference of direction and one pointing to hero) and magnitude
		sf::Vector2f steeringVector(normGoalVector.x - directionVector.x, normGoalVector.y - directionVector.y);
		float steeringMagnitude = sqrt(pow(steeringVector.x, 2) + pow(steeringVector.y, 2));

		// Adjust master direction vector
		if (steeringMagnitude > maxSteeringAdjustment)
		{
			// Constrain steering, normalize and only add vector of magnitude equal to the maximum allowed
			sf::Vector2f normSteeringVector(steeringVector.x / steeringMagnitude, steeringVector.y / steeringMagnitude);
			sf::Vector2f addVector(normSteeringVector.x * maxSteeringAdjustment, normSteeringVector.y * maxSteeringAdjustment);

			// Add to current direction vector
			directionVector = sf::Vector2f(directionVector.x + addVector.x, directionVector.y + addVector.y);

			// Make sure direction vector isn't 0 so they at least move in the
			// event their target duration runs out as they are turning around
			if (sqrt(pow(directionVector.x, 2) + pow(directionVector.y, 2)) == 0)
			{
				// Add again to current direction vector
				directionVector = sf::Vector2f(directionVector.x + addVector.x, directionVector.y + addVector.y);
			}
		}
		else
		{
			// Distance is small enough
			directionVector = normGoalVector;
		}

		// Set speed towards hero
		this->speedX = directionVector.x * speedMultiplier;
		this->speedY = directionVector.y * speedMultiplier;
	}
}

void TargetMonster::playDieSound()
{
	Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_TARGET_MONSTER_DIE);
}