#pragma once

#include "Global.h"
#include "Hero.h"
#include "DynamicMonster.h"
class InGame
{
public:
	void Init();
	void Update(sf::RenderWindow& window, float& dt);
	void Render(sf::RenderWindow& window);

private:
	void UpdateScore();
	void SpawnMonster();
	void RemoveMonster(int index);

	sf::Text textScore;
	std::string strScore;

	int score;
	Hero hero;

	float monsterSpawnTimer;
	BaseMonster *monsters[100];
	int numMonsters;
};