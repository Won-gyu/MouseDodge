#pragma once

#include "BaseMonster.h"

class TargetMonster : public BaseMonster
{
public:
	TargetMonster(int id, float maxSteeringAdjustment = 0.001, float targetDuration = 3, float speedMultiplier = 0.02f,
		float speedX = 1, float speedY = 1, float radius = 10, float posX = 0, float posY = 0) :
		BaseMonster(id, speedX, speedY, radius, posX, posY)
	{
		Init(maxSteeringAdjustment, targetDuration, speedMultiplier, speedX, speedY);
	}
	~TargetMonster();

	void Init(float maxSteeringAdjustment, float targetDuration, float speedMultiplier, float speedX, float speedY);
	void OnUpdate();

private:
	void playDieSound();

	sf::Clock clock;

	float targetDuration; // seconds
	float speedMultiplier; // adds a slight randomness to every monster's speed
	sf::Vector2f directionVector;

	float maxSteeringAdjustment;
};