#pragma once

#include "BaseObject.h"
#include "BaseMonster.h"
#include "cmath"

#define MAX_HERO_TAILS 10

class baseObject;
class Hero : public BaseObject
{
public:
	Hero(int hp = 10, float radius = 20, bool isUser = true);
	~Hero();

	void Init(int hp, float radius, bool isUser);
	void Update(sf::RenderWindow& window, BaseMonster* monsters[]);
	void Render(sf::RenderWindow& window);

	int GetHp();
	void SetHp(int hp);
	void SetPosX(float x);
	void SetPosY(float y);

	void setInvincible(bool newState);
	void setUsed(bool newUse);
	bool getUsed() const;

	sf::Vector2f& getPostition() const;

private:
	bool IsCollided(BaseMonster* monster);
	void InterpolateTailPos(float& tailPosX, float& tailPosY, float& targetPosX, float& targetPosY, float& retPosX, float& retPosY);

	sf::CircleShape circleShapes[MAX_HERO_TAILS + 1];
	float tailsPosX[MAX_HERO_TAILS];
	float tailsPosY[MAX_HERO_TAILS];

	bool isUser;
	bool isInvincible;
	bool usedInvincible;
	int hp;
};