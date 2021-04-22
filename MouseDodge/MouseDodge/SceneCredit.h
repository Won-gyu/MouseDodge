#pragma once

#include <SFML/Graphics.hpp>
#include "Global.h"
#include "SceneCredit.h"

#define CREDIT_COUNT 9

class SceneCredit
{
public:
	SceneCredit();
	~SceneCredit();

	void Init(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, float& dt);
	void Render(sf::RenderWindow& window);

private:
	void resetPositions(sf::RenderWindow& window);

	sf::Text text[CREDIT_COUNT];

	sf::Texture andyTexture;
	sf::Sprite andySprite;
};