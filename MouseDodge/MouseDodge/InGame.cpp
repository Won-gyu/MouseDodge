#include "InGame.h"

void InGame::Init()
{
	hero.Init(100, 30);
}

void InGame::Update()
{
	hero.Update();
}

void InGame::Render(sf::RenderWindow& window)
{
	hero.Render(window);
}