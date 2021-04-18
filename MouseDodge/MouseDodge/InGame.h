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
	void UpdateScore();

	sf::Text textScore;
	std::string strScore;

	int score;
	Hero hero;
};