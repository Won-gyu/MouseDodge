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
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

private:
	sf::Text text[CREDIT_COUNT];
};