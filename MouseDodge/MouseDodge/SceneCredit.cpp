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
	text[0].setCharacterSize(70 * Global::screenMultiplier);
	text[1].setString("Credits");
	text[1].setCharacterSize(60 * Global::screenMultiplier);
	text[2].setString("Hero Programmer");
	text[2].setCharacterSize(40 * Global::screenMultiplier);
	text[3].setString("Won-gyu Hwang");
	text[3].setCharacterSize(30 * Global::screenMultiplier);
	text[4].setString("Behind the Scenes Expert");
	text[4].setCharacterSize(40 * Global::screenMultiplier);
	text[5].setString("Scott Van Laar");
	text[5].setCharacterSize(30 * Global::screenMultiplier);
	text[6].setString("Monster Programmer");
	text[6].setCharacterSize(40 * Global::screenMultiplier);
	text[7].setString("Zack Harrington");
	text[7].setCharacterSize(30 * Global::screenMultiplier);
	text[8].setString("Special thanks to Andy");
	text[8].setCharacterSize(40 * Global::screenMultiplier);

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
	andySprite.setScale(sf::Vector2f(1.0f * Global::screenMultiplier, 1.0f * Global::screenMultiplier));
	andySprite.setColor(sf::Color(255, 255, 255, 200));

	// Positions
	resetPositions(window);
}

void SceneCredit::Update(sf::RenderWindow& window, float& dt)
{
	float newY = 0.0f;
	for (int i = 0; i < CREDIT_COUNT; i++)
	{
		newY = text[i].getPosition().y - 30.0f * dt * Global::screenMultiplier;
		text[i].setPosition(text[i].getPosition().x, newY);
	}

	newY = andySprite.getPosition().y - 30.0f * dt * Global::screenMultiplier;
	if (newY < - andySprite.getTextureRect().height * andySprite.getScale().y - 20.0f * Global::screenMultiplier)
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
	text[0].setPosition(window.getSize().x / 2.0f, window.getSize().y + 50.0f * Global::screenMultiplier);
	text[1].setPosition(window.getSize().x / 2.0f, window.getSize().y + 120.0f * Global::screenMultiplier);
	text[2].setPosition(window.getSize().x / 2.0f, window.getSize().y + 220.0f * Global::screenMultiplier);
	text[3].setPosition(window.getSize().x / 2.0f, window.getSize().y + 270.0f * Global::screenMultiplier);
	text[4].setPosition(window.getSize().x / 2.0f, window.getSize().y + 350.0f * Global::screenMultiplier);
	text[5].setPosition(window.getSize().x / 2.0f, window.getSize().y + 400.0f * Global::screenMultiplier);
	text[6].setPosition(window.getSize().x / 2.0f, window.getSize().y + 480.0f * Global::screenMultiplier);
	text[7].setPosition(window.getSize().x / 2.0f, window.getSize().y + 530.0f * Global::screenMultiplier);
	text[8].setPosition(window.getSize().x / 2.0f, window.getSize().y + 700.0f * Global::screenMultiplier);

	andySprite.setPosition((window.getSize().x / 2.0f) - (andySprite.getTextureRect().width * andySprite.getScale().x / 2.0f),
		window.getSize().y + 750.0f * Global::screenMultiplier);
}