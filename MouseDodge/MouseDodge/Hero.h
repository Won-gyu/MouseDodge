#pragma once

#include "BaseObject.h"
#include "BaseMonster.h"
#include "cmath"

class baseObject;
class Hero : public BaseObject
{
public:
	Hero(int hp = 10, float radius = 20);
	~Hero();

	void Init(int hp, float radius);
	void Update(sf::RenderWindow& window, BaseMonster* monsters[]);
	void Render(sf::RenderWindow& window);

	int GetHp();
	void SetHp(int hp);

	sf::Vector2f& getPostition() const;

private:
	bool IsCollided(BaseMonster* monster);

	sf::CircleShape circleShape;

	bool isInvincible;
	int hp;
};