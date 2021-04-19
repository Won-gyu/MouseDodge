#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Hero.h"
#include "DynamicMonster.h"

#define MAX_MONSTERS 100

class InGame
{
public:
	void Init();
	void Update(sf::RenderWindow& window, float& dt);
	void Render(sf::RenderWindow& window);

	void OnHeroHit();
	void OnMonsterDied(int index);

private:
	void UpdateScoreText();
	void UpdateHpText();
	void SpawnMonster(sf::RenderWindow& window);
	void RemoveMonster(int index);

	sf::Text textHp;
	sf::Text textScore;
	std::string strHp;
	std::string strScore;

	int score;
	float scoreTimer;
	Hero hero;

	float monsterSpawnTimer;
	BaseMonster *monsters[MAX_MONSTERS];
	int numMonsters;
};