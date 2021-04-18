#pragma once

#include "Global.h"
#include "Hero.h"

class InGame
{
public:
	void Init();
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

private:
	sf::Text textScore;

	int score;
	Hero hero;
};