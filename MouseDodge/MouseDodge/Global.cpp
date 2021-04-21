#include "Global.h"
#include "MenuWrapper.h"

sf::Font Global::commonFont;
MenuWrapper* Global::menuWrapper = nullptr;
float Global::deltaTime;
sf::SoundBuffer Global::soundEffectBuffers[MAX_SOUND_SOURCE];
sf::Sound Global::soundEffects[MAX_SOUND_EFFECT];

void Global::LoadSoundSources()
{
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_MONSTER_DIE].loadFromFile("TargetMonster_die.wav");
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