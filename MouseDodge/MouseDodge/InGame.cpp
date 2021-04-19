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
	if (monsterSpawnTimer > 0.3)
	{
		SpawnMonster();
		monsterSpawnTimer = 0;
	}
	scoreTimer += dt;
	if (scoreTimer > 1)
	{
		score++;
		UpdateScore();
		scoreTimer = 0;
	}
	// Update monsters
	// suggest(by won-gyu): its array is 100 but seems like there is probability i goes over 100.
	//			Would you have define a const integer value like #define MAX_MONSTER 100 and replace 100 with MAX_MONSTER
	//			Also use MAX_MONSTER to break forloop if i goes over MAX_MONSTER
	for (int i = 0; i < numMonsters; i++)
	{
		monsters[i]->Update(window, i);
	}

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
	strScore = "Score: " + std::to_string(score);
	textScore.setString(strScore);
}


void InGame::SpawnMonster()
{
	BaseMonster* monster;
	float spawnX = 0.0f, spawnY = 0.0f;
	float speedX = 0.0f, speedY = 0.0f;

	float radius = (float)(rand() % 30) + 10;

	switch (rand() % 4)
	{
	case 0: // Spawn at top
		spawnX = (float)(rand() % 800);
		spawnY = 0.0f - radius;
		speedX = (float)(rand() % 9) - 4.0f;
		speedY = (float)(rand() % 3) + 2.0f;
		break;
	case 1: // Spawn at bottom
		spawnX = (float)(rand() % 800);
		spawnY = 600.0f + radius;
		speedX = (float)(rand() % 9) - 4.0f;
		speedY = 0 - (float)(rand() % 3) + 2.0f;
		break;
	case 2: // Spawn at left
		spawnX = 0.0f - radius;
		spawnY = (float)(rand() % 600);
		speedX = (float)(rand() % 3) + 2.0f;
		speedY = (float)(rand() % 9) - 4.0f;
		break;
	default://3 // Spawn at right
		spawnX = 800.0f + radius;
		spawnY = (float)(rand() % 600);
		speedX = 0.0f - (float)(rand() % 3) + 2.0f;
		speedY = (float)(rand() % 9) - 4.0f;
		break;
	}

	// Scale down numbers so they move at normal speed 
	speedX = speedX / 100.0f;
	speedY = speedY / 100.0f;

	monster = new DynamicMonster(0.01f, speedX, speedY, radius, spawnX, spawnY);
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
		printf("%d\n", i);
	}
	monsters[numMonsters - 1] = nullptr; // avoid duplicate at the end after shifting

	numMonsters--;
}

void InGame::OnMonsterDied(int index)
{
	// Remove if out of bounds
	// suggest(by won-gyu): can we use window to get width and height?
	RemoveMonster(index);
}