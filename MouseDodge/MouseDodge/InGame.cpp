#include "InGame.h"

void InGame::Init()
{
	textScore.setFont(Global::commonFont);
	textScore.setFillColor(sf::Color::White);
	textScore.setCharacterSize(40);
	score = 0;
	UpdateScore();

	hero.Init(100, 10);

	// Monsters
	numMonsters = 0;
}

void InGame::Update(sf::RenderWindow& window, float& dt)
{
	// Check spawn timer
	monsterSpawnTimer += dt;
	if (monsterSpawnTimer > 1)
	{
		SpawnMonster();
		monsterSpawnTimer = 0;
	}
	// Update monsters
	for (int i = 0; i < numMonsters; i++)
	{
		monsters[i]->Update(window);
		// Remove if out of bounds
		if (!monsters[i]->checkInBounds(800, 600))
		{
			RemoveMonster(i);
		}
	}

	score++;
	UpdateScore();
	hero.Update(window);
}

void InGame::Render(sf::RenderWindow& window)
{
	// Render monsters
	for (int i = 0; i < numMonsters; i++)
	{
		monsters[i]->Render(window);
	}

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
	BaseMonster* monster;
	int spawnX = 0, spawnY = 0;
	float radius = 30;
	double speedX = 0.0, speedY = 0.0;

	switch (rand() % 4)
	{
	case 0: // Spawn at top
		spawnX = rand() % 800;
		spawnY = 0 - radius;
		speedX = (double)(rand() % 11) - 5;
		speedY = (double)(rand() % 10) + 1;
		break;
	case 1: // Spawn at bottom
		spawnX = rand() % 800;
		spawnY = 600 + radius;
		speedX = (double)(rand() % 11) - 5;
		speedY = 0 - (double)(rand() % 10) + 1;
		break;
	case 2: // Spawn at left
		spawnX = 0 - radius;
		spawnY = rand() % 600;
		speedX = (double)(rand() % 10) + 1;
		speedY = (double)(rand() % 11) - 5;
		break;
	default://3 // Spawn at right
		spawnX = 800 + radius;
		spawnY = rand() % 600;
		speedX = 0 - (double)(rand() % 10) + 1;
		speedY = (double)(rand() % 11) - 5;
		break;
	}

	// Scale down numbers so they move at normal speed 
	speedX = speedX / 10.0;
	speedY = speedY / 10.0;

	monster = new DynamicMonster(0.5, speedX, speedY, radius, spawnX, spawnY);
	monsters[numMonsters] = monster;
	numMonsters++;
}

void InGame::RemoveMonster(int index)
{
	delete monsters[index];

	// Shift all monsters up in the array
	for (int i = index; i < numMonsters - 1; i++)
	{
		monsters[i] = monsters[i + 1];
	}
	monsters[numMonsters] = nullptr; // avoid duplicate at the end after shifting

	numMonsters--;
}