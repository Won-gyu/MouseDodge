#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Hero.h"
#include "DynamicMonster.h"
#include "TargetMonster.h"
#include "FastMonster.h"
#include "TeleportMonster.h"

#define MAX_MONSTERS 100

class InGame
{
public:
	void Init();
	void Update(sf::RenderWindow& window, float& dt);
	void Render(sf::RenderWindow& window);

	void OnHeroHit();
	void OnMonsterDied(int index);
	void OnLeaveGame();

	sf::Vector2f& getHeroPosition() const;
	int getScore() const;

private:
	void UpdateScoreText();
	void UpdateHpText();
	void UpdateLevelText();
	void SpawnMonster(sf::RenderWindow& window);
	void RemoveMonster(int index);
	int AssignMonsterId();

	void OnLevelChanged();

	sf::Text textHp;
	sf::Text textScore;
	sf::Text textLevel;
	std::string strHp;
	std::string strScore;
	std::string strLevel;

	int level;
	int score;
	float scoreTimer;
	Hero hero;

	float monsterSpawnTimer;
	BaseMonster *monsters[MAX_MONSTERS];
	int numMonsters;
};