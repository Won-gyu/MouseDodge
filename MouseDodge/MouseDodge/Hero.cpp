#include "Hero.h"

Hero::Hero(int hp, float radius, bool isUser)
{
	Init(hp, radius, isUser);
}

Hero::~Hero()
{

}

void Hero::Init(int hp, float radius, bool isUser)
{
	this->isUser = isUser;
	this->hp = hp;
	this->radius = radius;
	for (int i = 0; i < MAX_HERO_TAILS + 1; i++)
	{
		circleShapes[i].setRadius(radius);
	}
}

void Hero::Update(sf::RenderWindow& window, BaseMonster* monsters[])
{
	if (isUser)
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f newPosition = Global::Lerp(sf::Vector2f(posX, posY),
			sf::Vector2f(mousePosition.x, mousePosition.y),
			Global::deltaTime * 10.0f);
		posX = newPosition.x;
		posY = newPosition.y;
	}
	circleShapes[0].setPosition(posX - radius, posY - radius);
	for (int i = 0; i < MAX_HERO_TAILS; i++)
	{
		if (hp > i)
		{
			if (i == 0)
			{
				InterpolateTailPos(tailsPosX[i], tailsPosY[i], posX, posY, tailsPosX[i], tailsPosY[i]);
			}
			else
			{
				InterpolateTailPos(tailsPosX[i], tailsPosY[i], tailsPosX[i - 1], tailsPosY[i - 1], tailsPosX[i], tailsPosY[i]);
			}
			circleShapes[i + 1].setPosition(tailsPosX[i] - radius, tailsPosY[i] - radius);
		}
	}



	// 100 -> some const variable
	if (isUser)
	{
		for (int i = 0; i < 100; i++)
		{
			if (monsters[i] != nullptr && IsCollided(monsters[i]))
			{
				if (!isInvincible)
				{
					hp--;
					Global::OnHeroHit();
				}
				monsters[i]->Die();
			}
		}
	}

	if (hp <= 0)
	{
		// Play sound
		Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_HERO_DIE);

		Global::OnHeroDied(isUser);
	}
}

void Hero::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_HERO_TAILS + 1; i++)
	{
		if (hp > i)
		{
			window.draw(circleShapes[i]);
		}
	}
}

int Hero::GetHp()
{
	return hp;
}

void Hero::SetHp(int hp)
{
	this->hp = hp;
}

void Hero::SetPosX(float x)
{
	posX = x;
}

void Hero::SetPosY(float y)
{
	posY = y;
}

void Hero::setInvincible(bool newState)
{
	this->isInvincible = newState;
}

void Hero::setUsed(bool newUse)
{
	this->usedInvincible = newUse;
}

bool Hero::getUsed() const
{
	return this->usedInvincible;
}

bool Hero::IsCollided(BaseMonster* monster)
{
	float distanceX;
	float distanceY;
	float distance;

	if (monster->AllowCollision() == false)
	{
		return false;
	}
	for (int i = 0; i < MAX_HERO_TAILS; i++)
	{
		if (hp > i)
		{
			distanceX = tailsPosX[i] - monster->GetPosX();
			distanceY = tailsPosY[i] - monster->GetPosY();
			distance = sqrt(distanceX * distanceX + distanceY * distanceY);
			if (distance < (float)(radius + monster->GetRadius()))
			{
				return true;
			}
		}
	}
	distanceX = posX - monster->GetPosX();
	distanceY = posY - monster->GetPosY();
	distance = sqrt(distanceX * distanceX + distanceY * distanceY);
	return distance < (float)(radius + monster->GetRadius());
}

void Hero::InterpolateTailPos(float& tailPosX, float& tailPosY, float& targetPosX, float& targetPosY, float& retPosX, float& retPosY)
{
	float distX = tailPosX - targetPosX;
	float distY = tailPosY - targetPosY;
	float length = sqrt(pow(distX, 2) + pow(distY, 2));
	if (length > radius * 2.0f)
	{
		float normalX = distX / length;
		float normalY = distY / length;

		retPosX = targetPosX + normalX * radius * 2.0f;
		retPosY = targetPosY + normalY * radius * 2.0f;
	}
}

sf::Vector2f& Hero::getPostition() const
{
	sf::Vector2f pos = sf::Vector2f(posX, posY);
	return pos;
}