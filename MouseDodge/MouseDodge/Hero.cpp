#include "Global.h"

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

void Hero::Update(sf::RenderWindow& window)
{
	sf::Vector2i position = sf::Mouse::getPosition(window);
	posX = (float)position.x;
	posY = (float)position.y;
	circleShape.setPosition(posX - radius, posY - radius);
}

void Hero::Render(sf::RenderWindow& window)
{
	window.draw(circleShape);
}