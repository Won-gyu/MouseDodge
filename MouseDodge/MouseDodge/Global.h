#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "BaseObject.h"
#include "Hero.h"
#include "InGame.h"
#include "SceneScores.h"
#include "SceneCredit.h"

class MenuWrapper;
class Global
{
public:
	static MenuWrapper* menuWrapper;
	static sf::Font commonFont;
};