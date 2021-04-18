#include "MenuWrapper.h"

void MenuWrapper::Init(sf::RenderWindow* window)
{
	this->window = window;

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

	sceneState = SceneState::SCENE_MENU;
}

void MenuWrapper::Update()
{
	if (sceneState == SceneState::SCENE_GAME)
	{
		inGame.Update();
	}
	else if (sceneState == SceneState::SCENE_SCORES)
	{
		sceneScores.Update();
	}
	else if (sceneState == SceneState::SCENE_CREDIT)
	{
		sceneCredit.Update();
	}
}

void MenuWrapper::OnEvent(const sf::Event& event)
{
	if (sceneState == SceneState::SCENE_MENU)
	{
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Enter)
			{
				SelectMenu((MenuState)menuState);
			}
			else if (event.key.code == sf::Keyboard::Down)
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
}

void MenuWrapper::Render(sf::RenderWindow& window)
{
	if (sceneState == SceneState::SCENE_MENU)
	{
		for (int i = 0; i < MENU_COUNT; i++)
			window.draw(text[i]);
	}
	else if (sceneState == SceneState::SCENE_GAME)
	{
		inGame.Render(window);
	}
	else if (sceneState == SceneState::SCENE_SCORES)
	{
		sceneScores.Render(window);
	}
	else if (sceneState == SceneState::SCENE_CREDIT)
	{
		sceneCredit.Render(window);
	}
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
	if (menuState == MenuState::MENU_GAME)
	{
		sceneState = SceneState::SCENE_GAME;
		inGame.Init();
	}
	else if (menuState == MenuState::MENU_SCORES)
	{
		sceneState = SceneState::SCENE_SCORES;
		sceneScores.Init();
	}
	else if (menuState == MenuState::MENU_CREDIT)
	{
		sceneState = SceneState::SCENE_CREDIT;
		sceneCredit.Init();
	}
	else if (menuState == MenuState::MENU_EXIT)
	{
		window->close();
	}
}