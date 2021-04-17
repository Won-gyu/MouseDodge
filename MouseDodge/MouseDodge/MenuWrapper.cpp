#include "MenuWrapper.h"

void MenuWrapper::Init()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	for (int i = 0; i < MENU_COUNT; i++)
	{
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(40);
		text[i].setPosition(0, i * 50);
	}

	text[0].setString("Start Game");
	text[1].setString("Scores");
	text[2].setString("Credit");
	text[3].setString("Exit");

	menuState = (int)MenuState::MENU_GAME;
	UpdateMenuColor();
}

void MenuWrapper::Update()
{
}

void MenuWrapper::OnEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Down)
		{
			if (menuState < MENU_COUNT - 1)
			{
				menuState = menuState + 1;
				UpdateMenuColor();
			}
		}
		else if (event.key.code == sf::Keyboard::Up)
		{
			if (menuState > 0)
			{
				menuState = menuState - 1;
				UpdateMenuColor();
			}
		}
	}
}

void MenuWrapper::Render(sf::RenderWindow& window)
{
	for (int i = 0; i < MENU_COUNT; i++)
		window.draw(text[i]);
}


void MenuWrapper::UpdateMenuColor()
{
	for (int i = 0; i < MENU_COUNT; i++)
	{
		text[i].setFillColor(sf::Color::White);
	}

	text[menuState].setFillColor(sf::Color::Green);
}

void MenuWrapper::SelectMenu(MenuState menuState)
{

}