#include "InGame.h"

void InGame::Init()
{
	hero.Init(100, 30);
}

void InGame::Update(sf::RenderWindow& window)
{
	hero.Update(window);
}

void InGame::Render(sf::RenderWindow& window)
{
	hero.Render(window);
}