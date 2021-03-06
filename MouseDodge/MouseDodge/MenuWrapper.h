#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "SceneScores.h"
#include "SceneCredit.h"
#include "InGame.h"

#define MENU_COUNT 6

enum class MenuState
{
	MENU_GAME,
	MENU_GAME_SERVER,
	MENU_GAME_CLIENT,
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
	void Update(sf::RenderWindow& window, float& dt);
	void Render(sf::RenderWindow& window);

	InGame& GetInGame();
	SceneScores& GetSceneScores();
	SceneCredit& GetSceneCredit();

	void OnHeroDied(bool isUser);

private:
	void UpdateMenuColor();
	void SelectMenu(MenuState menuState);

	sf::RenderWindow* window;
	int menuState;
	SceneState sceneState;
	sf::Text text[MENU_COUNT];
	sf::Text title;
	sf::Text line;
	sf::Clock iTimer;

	InGame inGame;
	SceneScores sceneScores;
	SceneCredit sceneCredit;
};