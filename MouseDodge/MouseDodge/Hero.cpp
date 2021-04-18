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

void Hero::Update()
{
	circleShape.setPosition(posX, posY);
}

void Hero::Render(sf::RenderWindow& window)
{
	window.draw(circleShape);
}