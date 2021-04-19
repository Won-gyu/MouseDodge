#pragma once

#include <SFML/Graphics.hpp>
#include "SceneScores.h"

class SceneScores
{
public:
	SceneScores();
	~SceneScores();

	void Init();
	void Update();
	void Render(sf::RenderWindow& window);

private:
};