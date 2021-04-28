#include "SceneScores.h"

SceneScores::SceneScores()
{
}

SceneScores::~SceneScores()
{
}

void SceneScores::Init(sf::RenderWindow& window)
{
	BST tree;
	tree.populateFromFile();
	int scores[10] = { 0 };
	tree.fillArray(scores);

	header.setString("TOP TEN");
	header.setCharacterSize(60);
	header.setFont(Global::addFont);
	header.setFillColor(sf::Color::White);
	header.setPosition(10, 15);

	line.setString("-----------");
	line.setCharacterSize(50);
	line.setFont(Global::addFont);
	line.setFillColor(sf::Color::White);
	line.setPosition(12, 55);
	

	for (int i = 0; i < 10; i++)
	{
		text[i].setString(std::to_string(scores[i]));
		text[i].setFont(Global::addFont);
		text[i].setPosition(80, 110 + 50 * i);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(40);
		nums[i].setString(std::to_string(i + 1) + ": ");
		nums[i].setFont(Global::addFont);
		if (i == 0)
		{
			nums[i].setPosition(47, 110 + 50 * i);
		}
		else
		{
			nums[i].setPosition(30, 110 + 50 * i);
		}
		nums[i].setFillColor(sf::Color::White);
		nums[i].setCharacterSize(40);
	}
}

void SceneScores::Update(sf::RenderWindow& window)
{

}

void SceneScores::Render(sf::RenderWindow& window)
{
	window.draw(header);
	window.draw(line);
	for (int i = 0; i < 10; i++)
	{
		window.draw(nums[i]);
		window.draw(text[i]);
	}
}
