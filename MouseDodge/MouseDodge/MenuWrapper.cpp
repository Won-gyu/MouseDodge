#include "MenuWrapper.h"

InGame& MenuWrapper::GetInGame()
{
	return inGame;
}

SceneScores& MenuWrapper::GetSceneScores()
{
	return sceneScores;
}

SceneCredit& MenuWrapper::GetSceneCredit()
{
	return sceneCredit;
}

void MenuWrapper::Init(sf::RenderWindow* window)
{
	Global::menuWrapper = this;
	this->window = window;

	title.setFont(Global::commonFont);
	title.setFillColor(sf::Color::Cyan);
	title.setCharacterSize(50);
	title.setPosition(0, 10);
	title.setString("MOUSE DODGE\n---------------------");

	for (int i = 0; i < MENU_COUNT; i++)
	{
		text[i].setFont(Global::commonFont);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(40);
		text[i].setPosition(5, (float)((i * 50) + 110));
	}

	text[0].setString("Start Game");
	text[1].setString("Scores");
	text[2].setString("Credit");
	text[3].setString("Exit");

	menuState = (int)MenuState::MENU_GAME;
	UpdateMenuColor();

	sceneState = SceneState::SCENE_MENU;
}

void MenuWrapper::Update(sf::RenderWindow& window, float& dt)
{
	if (sceneState == SceneState::SCENE_GAME)
	{
		inGame.Update(window, dt);
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
	else
	{
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				sceneState = SceneState::SCENE_MENU;
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
		window.draw(title);
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

void MenuWrapper::OnHeroDied()
{
	sceneState = SceneState::SCENE_MENU;
}