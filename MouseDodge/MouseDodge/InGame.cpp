#include "InGame.h"

void InGame::Init()
{
	Global::LoadSoundSources();

	textScore.setFont(Global::commonFont);
	textScore.setFillColor(sf::Color::White);
	textScore.setCharacterSize(20);
	score = 0;
	UpdateScoreText();

	hero.Init(10, 10);

	textHp.setPosition(0, 30);
	textHp.setFont(Global::commonFont);
	textHp.setFillColor(sf::Color::White);
	textHp.setCharacterSize(20);
	UpdateHpText();

	level = 1;
	textLevel.setPosition(0, 60);
	textLevel.setFont(Global::commonFont);
	textLevel.setFillColor(sf::Color::White);
	textLevel.setCharacterSize(20);
	UpdateLevelText();

	// Monsters
	numMonsters = 0;
}

void InGame::Update(sf::RenderWindow& window, float& dt)
{
	Global::deltaTime = dt;

	// Check spawn timer
	monsterSpawnTimer += dt;
	if (monsterSpawnTimer > 0.3)
	{
		if (numMonsters < MAX_MONSTERS)
		{
			SpawnMonster(window);
		}
		else
		{
			printf("Max monsters on screen\n");
		}
		monsterSpawnTimer = 0;
	}

	scoreTimer += dt;
	if (scoreTimer > 0.1)
	{
		score++;
		UpdateScoreText();
		scoreTimer = 0;

		int newLevel = 1 + (score / 100);
		if (level != newLevel)
		{
			level = newLevel;
			OnLevelChanged();
		}
	}

	// Update monsters
	for (int i = 0; i < MAX_MONSTERS; i++)
	{
		if (monsters[i] != nullptr)
			monsters[i]->Update(window);
	}

	hero.Update(window, monsters);
}

void InGame::Render(sf::RenderWindow& window)
{
	// Render monsters
	for (int i = 0; i < MAX_MONSTERS; i++)
	{
		if (monsters[i] != nullptr)
			monsters[i]->Render(window);
	}

	hero.Render(window);
	window.draw(textScore);
	window.draw(textHp);
	window.draw(textLevel);
}

void InGame::UpdateScoreText()
{
	strScore = "Score: " + std::to_string(score);
	textScore.setString(strScore);
}

void InGame::UpdateHpText()
{
	strHp = "Hp: " + std::to_string(hero.GetHp());
	textHp.setString(strHp);
}

void InGame::UpdateLevelText()
{
	strLevel = "Level: " + std::to_string(level);
	textLevel.setString(strLevel);
}

void InGame::OnLevelChanged()
{
	UpdateLevelText();

	// reward player the extra hp
	hero.SetHp(hero.GetHp() + 1);
	UpdateHpText();
}

int InGame::AssignMonsterId()
{
	for (int i = 0; i < MAX_MONSTERS; i++)
	{
		if (monsters[i] == nullptr)
		{
			return i;
		}
	}
	return -1;
}

void InGame::SpawnMonster(sf::RenderWindow& window)
{
	BaseMonster* monster;
	float spawnX = 0.0f, spawnY = 0.0f;
	float speedX = 0.0f, speedY = 0.0f;

	// Allows for change in screen size
	float screenMultiplier = window.getSize().x / 800.0f;

	float radius = ((float)(rand() % 30) + 10) * screenMultiplier;

	// Choose starting location and base speed off of it
	switch (rand() % 4)
	{
	case 0: // Spawn at top
		spawnX = (float)(rand() % window.getSize().x);
		spawnY = 0.0f - radius;
		speedX = (float)(rand() % 9) - 4.0f;
		speedY = (float)(rand() % 3) + 2.0f;
		break;
	case 1: // Spawn at bottom
		spawnX = (float)(rand() % window.getSize().x);
		spawnY = window.getSize().y + radius;
		speedX = (float)(rand() % 9) - 4.0f;
		speedY = 0.0f - ((float)(rand() % 3) + 2.0f);
		break;
	case 2: // Spawn at left
		spawnX = 0.0f - radius;
		spawnY = (float)(rand() % window.getSize().y);
		speedX = (float)(rand() % 3) + 2.0f;
		speedY = (float)(rand() % 9) - 4.0f;
		break;
	case 3: // Spawn at right
		spawnX = window.getSize().x + radius;
		spawnY = (float)(rand() % window.getSize().y);
		speedX = 0.0f - ((float)(rand() % 3) + 2.0f);
		speedY = (float)(rand() % 9) - 4.0f;
		break;
	}

	// Scale down numbers so they move at normal speed 
	speedX = (speedX / 100.0f) * screenMultiplier;
	speedY = (speedY / 100.0f) * screenMultiplier;

	int id = AssignMonsterId();

	// Choose what type of monster to spawn
	if (rand() % 20 == 0) // 1 in 20 chance
	{
		radius = ((float)(rand() % 10) + 10) * screenMultiplier;
		float speedMultiplier = (1 / ((float)(rand() % 3) + 3.0f)) * screenMultiplier; // 0.33 - 0.2
		monster = new FastMonster(id, speedMultiplier, speedX, speedY, radius, spawnX, spawnY);
	}
	else if (rand() % 4 == 0) // 1 in 4 chance
	{
		float speedMultiplier = (1 / ((float)(rand() % 5) + 8.0f)) * screenMultiplier; // 0.125 - 0.0833
		radius += (5.0f * screenMultiplier); // they seemed a little small with the same radius as Dynamic
		float timeTargeting = (0.25f * level) + 1.5f;
		float maxSteeringAdjustment = 0.001 * screenMultiplier;
		monster = new TargetMonster(id, maxSteeringAdjustment, timeTargeting, speedMultiplier, speedX, speedY, radius, spawnX, spawnY);
	}
	else
	{
		float sizeSpeed = 1 / ((float)(rand() % 120) + 80.0f); // 0.0125 - 0.005
		monster = new DynamicMonster(id, sizeSpeed, speedX, speedY, radius, spawnX, spawnY);
	}
	
	// Add monster too list
	monsters[id] = monster;
	numMonsters++;
}

void InGame::RemoveMonster(int index)
{
	delete monsters[index];
	monsters[index] = nullptr;

	numMonsters--;
}

void InGame::OnHeroHit()
{
	UpdateHpText();
}

void InGame::OnMonsterDied(int index)
{
	RemoveMonster(index);
}

void InGame::OnLeaveGame()
{
	for (int i = 0; i < MAX_MONSTERS; i++)
	{
		if (monsters[i] != nullptr)
		{
			monsters[i]->Die(true);
		}
	}
}

sf::Vector2f& InGame::getHeroPosition() const
{
	return hero.getPostition();
}