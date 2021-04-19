#include "BaseObject.h"

BaseObject::BaseObject(float radius, float posX, float posY)
{
	this->posX = posX;
	this->posY = posY;
	this->radius = radius;
}

BaseObject::~BaseObject()
{
}

float BaseObject::GetRadius()
{
	return radius;
}

float BaseObject::GetPosX()
{
	return posX;
}

float BaseObject::GetPosY()
{
	return posY;
}