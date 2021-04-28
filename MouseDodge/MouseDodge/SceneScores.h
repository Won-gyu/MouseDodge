#pragma once

#include <SFML/Graphics.hpp>
#include "SceneScores.h"
#include "Global.h"

class SceneScores
{
public:
	SceneScores();
	~SceneScores();

	void Init(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

private:
	sf::Text header;
	sf::Text line;
	sf::Text text[10];
	sf::Text nums[10];
};