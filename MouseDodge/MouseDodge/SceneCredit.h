#pragma once

#include <SFML/Graphics.hpp>
#include "SceneCredit.h"

class SceneCredit
{
public:
	SceneCredit();
	~SceneCredit();

	void Init();
	void Update();
	void Render(sf::RenderWindow& window);

private:
};