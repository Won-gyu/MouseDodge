#pragma once

#include <SFML/Graphics.hpp>

#define MENU_COUNT 4

enum class MenuState
{
	MENU_GAME,
	MENU_SCORES,
	MENU_CREDIT,
	MENU_EXIT
};

class MenuWrapper
{
public:
	void Init();
	void OnEvent(const sf::Event& event);
	void Update();
	void Render(sf::RenderWindow& window);

private:
	void UpdateMenuColor();
	void SelectMenu(MenuState menuState);

	int menuState;
	sf::Font font;
	sf::Text text[MENU_COUNT];
};