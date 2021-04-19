#include "Global.h"
#include "MenuWrapper.h"

sf::Font Global::commonFont;
MenuWrapper* Global::menuWrapper = nullptr;

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