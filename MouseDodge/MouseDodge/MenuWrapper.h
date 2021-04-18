#pragma once

#include <SFML/Graphics.hpp>
#include "InGame.h"
#include "SceneScores.h"
#include "SceneCredit.h"

#define MENU_COUNT 4

enum class MenuState
{
	MENU_GAME,
	MENU_SCORES,
	MENU_CREDIT,
	MENU_EXIT
};

enum class SceneState
{
	SCENE_MENU,
	SCENE_GAME,
	SCENE_SCORES,
	SCENE_CREDIT
};

class MenuWrapper
{
public:
	void Init(sf::RenderWindow* window);
	void OnEvent(const sf::Event& event);
	void Update();
	void Render(sf::RenderWindow& window);

private:
	void UpdateMenuColor();
	void SelectMenu(MenuState menuState);

	sf::RenderWindow* window;
	int menuState;
	SceneState sceneState;
	sf::Font font;
	sf::Text text[MENU_COUNT];

	InGame inGame;
	SceneScores sceneScores;
	SceneCredit sceneCredit;
};