#include "Global.h"
#include "MenuWrapper.h"

sf::Font Global::commonFont;
MenuWrapper* Global::menuWrapper = nullptr;
float Global::deltaTime;

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