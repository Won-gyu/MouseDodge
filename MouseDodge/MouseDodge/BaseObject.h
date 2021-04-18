#pragma once

class BaseObject
{
public:
	BaseObject(float posX = 0, float posY = 0);
	~BaseObject();

private:
	float posX;
	float posY;
};