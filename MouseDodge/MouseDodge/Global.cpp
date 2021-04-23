#include "Global.h"
#include "MenuWrapper.h"

sf::Font Global::commonFont;
sf::Font Global::titleFont;
sf::Font Global::addFont;
MenuWrapper* Global::menuWrapper = nullptr;
float Global::deltaTime;
sf::SoundBuffer Global::soundEffectBuffers[MAX_SOUND_SOURCE];
sf::Sound Global::soundEffects[MAX_SOUND_EFFECT];

sf::Vector2f Global::Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, const float& t)
{
	return sf::Vector2f(v1.x + (v2.x - v1.x) * t, v1.y + (v2.y - v1.y) * t);
}

void Global::LoadSoundSources()
{
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_MONSTER_DIE].loadFromFile("FastMonster_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_DYNAMIC_MONSTER_DIE].loadFromFile("DynamicMonster_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_TARGET_MONSTER_DIE].loadFromFile("TargetMonster_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_FAST_MONSTER_DIE].loadFromFile("FastMonster_die.wav");
}

void Global::PlaySoundEffect(const SOUND_SOURCE& soundSource)
{
	for (int i = 0; i < MAX_SOUND_EFFECT; i++)
	{
		if (soundEffects[i].getStatus() == sf::Sound::SoundSource::Stopped)
		{
			soundEffects[i].setBuffer(soundEffectBuffers[(int)soundSource]);
			soundEffects[i].play();
			break;
		}
	}
}

void Global::OnHeroHit()
{
	menuWrapper->GetInGame().OnHeroHit();
}

void Global::OnHeroDied()
{
	menuWrapper->GetInGame().OnLeaveGame();
	menuWrapper->OnHeroDied();
}

void Global::OnMonsterDied(int index)
{
	menuWrapper->GetInGame().OnMonsterDied(index);
}

sf::Vector2f& Global::getHeroPosition()
{
	return menuWrapper->GetInGame().getHeroPosition();
}