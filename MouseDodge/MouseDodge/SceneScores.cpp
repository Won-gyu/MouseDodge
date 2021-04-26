#include "SceneScores.h"

SceneScores::SceneScores()
{
}

SceneScores::~SceneScores()
{
}

void SceneScores::Init(sf::RenderWindow& window)
{
	BST scores;
	//scores.populateFromFile();
	//int l = scores.getLength();
	sf::Text text[10];
	sf::Text header;

	header.setString("TOP TEN\n---------");
	header.setCharacterSize(70);
	header.setFont(Global::addFont);
	header.setFillColor(sf::Color::White);
	header.setPosition(10, 15);

	for (int i = 0; i < 9 && i < 10; i++)
	{
		//text[i].setString();
	}
}

void SceneScores::Update(sf::RenderWindow& window)
{

}

void SceneScores::Render(sf::RenderWindow& window)
{
	window.draw(header);
}