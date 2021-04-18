#include "InGame.h"

void InGame::Init()
{
	textScore.setFont(Global::commonFont);
	textScore.setFillColor(sf::Color::White);
	textScore.setCharacterSize(40);
	score = 0;
	UpdateScore();

	hero.Init(100, 10);
}

void InGame::Update(sf::RenderWindow& window, float& dt)
{
	monsterSpawnTimer += dt;
	if (monsterSpawnTimer > 1)
	{
		SpawnMonster();
		monsterSpawnTimer = 0;
	}

	score++;
	UpdateScore();
	hero.Update(window);
}

void InGame::Render(sf::RenderWindow& window)
{
	hero.Render(window);
	window.draw(textScore);
}

void InGame::UpdateScore()
{
	strScore = "Score: " + std::to_string(score / 100);
	textScore.setString(strScore);
}


void InGame::SpawnMonster()
{
	printf("Spawn\n");
}