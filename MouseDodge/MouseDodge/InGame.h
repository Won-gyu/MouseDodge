#pragma once

#include <SFML/Graphics.hpp>
#include "Hero.h"

class InGame
{
public:
	void Init();
	void Update();
	void Render(sf::RenderWindow& window);

private:
	Hero hero;
};