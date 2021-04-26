#include "Global.h"
#include "MenuWrapper.h"

sf::Font Global::commonFont;
sf::Font Global::titleFont;
sf::Font Global::addFont;
sf::Color Global::titleColor;
MenuWrapper* Global::menuWrapper = nullptr;
float Global::deltaTime;
sf::SoundBuffer Global::soundEffectBuffers[MAX_SOUND_SOURCE];
sf::Sound Global::soundEffects[MAX_SOUND_EFFECT];
float Global::screenMultiplier;

sf::Vector2f Global::Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, const float& t)
{
	return sf::Vector2f(v1.x + (v2.x - v1.x) * t, v1.y + (v2.y - v1.y) * t);
}

void Global::LoadSoundSources()
{
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_MONSTER_DIE].loadFromFile("basic_sound.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_DYNAMIC_MONSTER_DIE].loadFromFile("DynamicMonster_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_TARGET_MONSTER_DIE].loadFromFile("TargetMonster_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_FAST_MONSTER_DIE].loadFromFile("FastMonster_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_TELEPORT_MONSTER_DIE].loadFromFile("TeleportMonster_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_TELEPORT_MONSTER_TELEPORT].loadFromFile("TeleportMonster_teleport.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_HERO_LEVEL_UP].loadFromFile("level_up.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_HERO_DIE].loadFromFile("Hero_die.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_MENU_CHANGE].loadFromFile("click.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_MENU_START_GAME].loadFromFile("select_game.wav");
	soundEffectBuffers[(int)SOUND_SOURCE::SOUND_SOURCE_RETURN_TO_MENU].loadFromFile("return_to_menu.wav");
}

void Global::PlaySoundEffect(const SOUND_SOURCE& soundSource)
{
	for (int i = 0; i < MAX_SOUND_EFFECT; i++)
	{
		if (soundEffects[i].getStatus() == sf::Sound::SoundSource::Stopped)
		{
			soundEffects[i].setBuffer(soundEffectBuffers[(int)soundSource]);
			if (soundSource == SOUND_SOURCE::SOUND_SOURCE_TELEPORT_MONSTER_TELEPORT)
			{
				soundEffects[i].setVolume(25); // (0 - 100)
			}
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
	manageScore();
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

void Global::manageScore()
{
	BST scoreTree;
	ofstream output;
	scoreTree.insert(menuWrapper->GetInGame().getScore());
	scoreTree.populateFromFile();
	output.open("ranks.txt");
	scoreTree.printToFile(output);
	output.close();
	//scoreTree.~BST();
}