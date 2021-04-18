#pragma once

#include "BaseObject.h"

class Hero : public BaseObject
{
public:
	Hero(int hp = 100);
	~Hero();

protected:
	int hp;
};