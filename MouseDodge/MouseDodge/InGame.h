#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Hero.h"
#include "DynamicMonster.h"

class InGame
{
public:
	void Init();
	void Update(sf::RenderWindow& window, float& dt);
	void Render(sf::RenderWindow& window);

	void OnMonsterDied(int index);

private:
	void UpdateScore();
	void SpawnMonster();
	void RemoveMonster(int index);

	sf::Text textScore;
	std::string strScore;

	int score;
	float scoreTimer;
	Hero hero;

	float monsterSpawnTimer;
	BaseMonster *monsters[100];
	int numMonsters;
};