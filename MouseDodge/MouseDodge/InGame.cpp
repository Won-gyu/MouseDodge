#include "InGame.h"

void InGame::Init()
{
	textScore.setFont(Global::commonFont);
	textScore.setFillColor(sf::Color::White);
	textScore.setCharacterSize(40);
	textScore.setString("Score: ");

	hero.Init(100, 30);
}

void InGame::Update(sf::RenderWindow& window)
{
	hero.Update(window);
}

void InGame::Render(sf::RenderWindow& window)
{
	hero.Render(window);
	window.draw(textScore);
}