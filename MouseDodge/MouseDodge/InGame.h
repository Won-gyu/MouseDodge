#pragma once

#include "Global.h"
class InGame
{
public:
	void Init();
	void Update(sf::RenderWindow& window, float& dt);
	void Render(sf::RenderWindow& window);

private:
	void UpdateScore();
	void SpawnMonster();

	sf::Text textScore;
	std::string strScore;

	int score;
	Hero hero;

	float monsterSpawnTimer;
};