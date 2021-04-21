#include "SceneCredit.h"
#include <iostream>

SceneCredit::SceneCredit()
{
}

SceneCredit::~SceneCredit()
{
}

void SceneCredit::Init(sf::RenderWindow& window)
{
	// Words and sizes
	text[0].setString("Mouse Dodge");
	text[0].setCharacterSize(70);
	text[1].setString("Credits");
	text[1].setCharacterSize(60);
	text[2].setString("Hero Programmer");
	text[2].setCharacterSize(40);
	text[3].setString("Won-gyu Hwang");
	text[3].setCharacterSize(30);
	text[4].setString("Behind the Scenes Expert");
	text[4].setCharacterSize(40);
	text[5].setString("Scott Van Laar");
	text[5].setCharacterSize(30);
	text[6].setString("Monster Programmer");
	text[6].setCharacterSize(40);
	text[7].setString("Zack Harrington");
	text[7].setCharacterSize(30);
	text[8].setString("Special thanks to Andy");
	text[8].setCharacterSize(40);

	// Font, color, origin
	for (int i = 0; i < CREDIT_COUNT; i++)
	{
		text[i].setFont(Global::commonFont);
		text[i].setFillColor(sf::Color::White);
		// Change origin to center as opposed to top left
		sf::FloatRect textRect = text[i].getLocalBounds();
		text[i].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	}

	// Andy
	andyTexture.loadFromFile("Andy-O'Fallon.jpg");
	andySprite.setTexture(andyTexture);
	andySprite.setTextureRect(sf::IntRect(0, 0, 198, 198));
	andySprite.setColor(sf::Color(255, 255, 255, 200));

	// Positions
	resetPositions(window);
}

void SceneCredit::Update(sf::RenderWindow& window)
{
	float newY = 0.0f;
	for (int i = 0; i < CREDIT_COUNT; i++)
	{
		newY = text[i].getPosition().y - 0.01;
		text[i].setPosition(text[i].getPosition().x, newY);
	}

	newY = andySprite.getPosition().y - 0.01;
	if (newY < 0.0f - andySprite.getTextureRect().height - 10.0f)
	{
		resetPositions(window);
	}
	else
	{
		andySprite.setPosition(andySprite.getPosition().x, newY);
	}
}

void SceneCredit::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < CREDIT_COUNT; i++)
		window.draw(text[i]);

	window.draw(andySprite);
}

void SceneCredit::resetPositions(sf::RenderWindow& window)
{
	text[0].setPosition(window.getSize().x / 2.0f, window.getSize().y + 50.0f);
	text[1].setPosition(window.getSize().x / 2.0f, window.getSize().y + 120.0f);
	text[2].setPosition(window.getSize().x / 2.0f, window.getSize().y + 220.0f);
	text[3].setPosition(window.getSize().x / 2.0f, window.getSize().y + 270.0f);
	text[4].setPosition(window.getSize().x / 2.0f, window.getSize().y + 350.0f);
	text[5].setPosition(window.getSize().x / 2.0f, window.getSize().y + 400.0f);
	text[6].setPosition(window.getSize().x / 2.0f, window.getSize().y + 480.0f);
	text[7].setPosition(window.getSize().x / 2.0f, window.getSize().y + 530.0f);
	text[8].setPosition(window.getSize().x / 2.0f, window.getSize().y + 700.0f);

	andySprite.setPosition((window.getSize().x / 2.0f) - (andySprite.getTextureRect().width / 2.0f),
		window.getSize().y + 750.0f);
}