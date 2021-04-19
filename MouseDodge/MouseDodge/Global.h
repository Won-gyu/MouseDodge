#pragma once
#include <SFML/Graphics.hpp>

class MenuWrapper;
class Global
{
public:
	static MenuWrapper* menuWrapper;
	static sf::Font commonFont;

	static void OnHeroDied();
	static void OnMonsterDied(int index);
};