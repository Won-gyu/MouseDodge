#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

#define MAX_SOUND_EFFECT 10

#define MAX_SOUND_SOURCE 6
enum class SOUND_SOURCE {
	SOUND_SOURCE_MONSTER_DIE, 
	SOUND_SOURCE_DYNAMIC_MONSTER_DIE, 
	SOUND_SOURCE_TARGET_MONSTER_DIE,
	SOUND_SOURCE_FAST_MONSTER_DIE,
	SOUND_SOURCE_HERO_LEVEL_UP,
	SOUND_SOURCE_HERO_DIE,
};

class MenuWrapper;
class Global
{
public:
	static MenuWrapper* menuWrapper;
	static sf::Font commonFont;
	static sf::Font titleFont;
	static sf::Font addFont;
	static float deltaTime;
	static sf::SoundBuffer soundEffectBuffers[MAX_SOUND_SOURCE];
	static sf::Sound soundEffects[MAX_SOUND_EFFECT];

	static sf::Vector2f Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2 , const float& t);

	static void LoadSoundSources();
	static void PlaySoundEffect(const SOUND_SOURCE& soundSource);

	static void OnHeroDied();
	static void OnHeroHit();
	static void OnMonsterDied(int index);

	static sf::Vector2f& getHeroPosition();
};