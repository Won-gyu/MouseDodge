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
	// suggest(by won-gyu): its array is 100 but seems like there is probability i goes over 100.
	//			Would you have define a const integer value like #define MAX_MONSTER 100 and replace 100 with MAX_MONSTER
	//			Also use MAX_MONSTER to break forloop if i goes over MAX_MONSTER
	for (int i = 0; i < numMonsters; i++)
	{
		monsters[i]->Update(window);
		// Remove if out of bounds
		// suggest(by won-gyu): can we use window to get width and height?
		if (!monsters[i]->checkInBounds(window.getSize().x, window.getSize().y))
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
	double speedX = 0.0, speedY = 0.0;

	float radius = (double)(rand() % 30) + 10;

	switch (rand() % 4)
	{
	case 0: // Spawn at top
		spawnX = rand() % 800;
		spawnY = 0 - radius;
		speedX = (double)(rand() % 9) - 4;
		speedY = (double)(rand() % 3) + 2;
		break;
	case 1: // Spawn at bottom
		spawnX = rand() % 800;
		spawnY = 600 + radius;
		speedX = (double)(rand() % 9) - 4;
		speedY = 0 - (double)(rand() % 3) + 2;
		break;
	case 2: // Spawn at left
		spawnX = 0 - radius;
		spawnY = rand() % 600;
		speedX = (double)(rand() % 3) + 2;
		speedY = (double)(rand() % 9) - 4;
		break;
	default://3 // Spawn at right
		spawnX = 800 + radius;
		spawnY = rand() % 600;
		speedX = 0 - (double)(rand() % 3) + 2;
		speedY = (double)(rand() % 9) - 4;
		break;
	}

	// Scale down numbers so they move at normal speed 
	speedX = speedX / 100.0;
	speedY = speedY / 100.0;

	monster = new DynamicMonster(0.01, speedX, speedY, radius, spawnX, spawnY);
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