#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "BST.h"

#define MAX_SOUND_EFFECT 10

#define MAX_SOUND_SOURCE 11
enum class SOUND_SOURCE {
	SOUND_SOURCE_MONSTER_DIE, 
	SOUND_SOURCE_DYNAMIC_MONSTER_DIE, 
	SOUND_SOURCE_TARGET_MONSTER_DIE,
	SOUND_SOURCE_FAST_MONSTER_DIE,
	SOUND_SOURCE_TELEPORT_MONSTER_DIE,
	SOUND_SOURCE_TELEPORT_MONSTER_TELEPORT,
	SOUND_SOURCE_HERO_LEVEL_UP,
	SOUND_SOURCE_HERO_DIE,
	SOUND_SOURCE_MENU_CHANGE,
	SOUND_SOURCE_MENU_START_GAME,
	SOUND_SOURCE_RETURN_TO_MENU,
};

class MenuWrapper;
class Global
{
public:
	static MenuWrapper* menuWrapper;
	static sf::Font commonFont;
	static sf::Font titleFont;
	static sf::Font addFont;
	static sf::Color titleColor;
	static float deltaTime;
	static sf::SoundBuffer soundEffectBuffers[MAX_SOUND_SOURCE];
	static sf::Sound soundEffects[MAX_SOUND_EFFECT];
	static float screenMultiplier;

	static sf::Vector2f Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2 , const float& t);

	static void LoadSoundSources();
	static void PlaySoundEffect(const SOUND_SOURCE& soundSource);

	static void OnHeroDied();
	static void OnHeroHit();
	static void OnMonsterDied(int index);
	static void manageScore();

	static sf::Vector2f& getHeroPosition();
};