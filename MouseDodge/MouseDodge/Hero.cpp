#include "Hero.h"

Hero::Hero(int hp, float radius)
{
	Init(hp, radius);
}

Hero::~Hero()
{

}

void Hero::Init(int hp, float radius)
{
	this->hp = hp;
	this->radius = radius;
	circleShape.setRadius(radius);
}

void Hero::Update(sf::RenderWindow& window, BaseMonster* monsters[])
{
	sf::Vector2i position = sf::Mouse::getPosition(window);
	posX = (float)position.x;
	posY = (float)position.y;
	circleShape.setPosition(posX - radius, posY - radius);

	// 100 -> some const variable
	for (int i = 0; i < 100; i++)
	{
		if (monsters[i] != nullptr && IsCollided(monsters[i]))
		{
			hp--;
			Global::OnHeroHit();
			monsters[i]->Die();
		}
	}

	if (hp <= 0)
	{
		Global::OnHeroDied();
	}
}

void Hero::Render(sf::RenderWindow& window)
{
	window.draw(circleShape);
}

int Hero::GetHp()
{
	return hp;
}

void Hero::SetHp(int hp)
{
	this->hp = hp;
}

bool Hero::IsCollided(BaseMonster* monster)
{
	float distanceX = posX - monster->GetPosX();
	float distanceY = posY - monster->GetPosY();
	float distance = sqrt(distanceX * distanceX + distanceY * distanceY);
	return distance < (float)(radius + monster->GetRadius());
}

sf::Vector2f& Hero::getPostition() const
{
	sf::Vector2f pos = sf::Vector2f(posX, posY);
	return pos;
}