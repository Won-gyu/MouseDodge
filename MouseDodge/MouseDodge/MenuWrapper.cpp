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

	Global::LoadSoundSources();

	Global::screenMultiplier = window->getSize().x / 800.0f;

	Global::titleColor = sf::Color(0, 240, 255);

	title.setFont(Global::titleFont);
	title.setFillColor(Global::titleColor);
	title.setCharacterSize(65);
	title.setPosition(10, 0);
	title.setString("Mouse Dodge");

	line.setFont(Global::commonFont);
	line.setFillColor(sf::Color::White);
	line.setCharacterSize(20);
	line.setPosition(12, 70);
	line.setString("-----------------------------------------------------------");

	for (int i = 0; i < MENU_COUNT; i++)
	{
		text[i].setFont(Global::addFont);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(40);
		text[i].setPosition(10, (float)((i * 50) + 90));
	}

	text[0].setString("Start Game");
	text[1].setString("Start Game - Server (Unstable)");
	text[2].setString("Start Game - Client (Unstable)");
	text[3].setString("Scores");
	text[4].setString("Credit");
	text[5].setString("Exit");

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
		sceneScores.Update(window);
	}
	else if (sceneState == SceneState::SCENE_CREDIT)
	{
		sceneCredit.Update(window, dt);
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
					Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_MENU_CHANGE);

					menuState = menuState + 1;
					UpdateMenuColor();
				}
			}
			else if (event.key.code == sf::Keyboard::Up)
			{
				if (menuState > 0)
				{
					Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_MENU_CHANGE);

					menuState = menuState - 1;
					UpdateMenuColor();
				}
			}
		}
	}
	else if (sceneState == SceneState::SCENE_GAME)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//if (this->GetInGame().getHero().getUsed() == false)
				//{
				//	int time = iTimer.getElapsedTime().asSeconds();
				//	this->GetInGame().getHero().setInvincible(true);
				//	this->GetInGame().getHero().setUsed(true);
				//	while (iTimer.getElapsedTime().asSeconds() < time + 10)
				//	{
				//		// nothing
				//	}
				//	this->GetInGame().getHero().setInvincible(false);
				//}
			}
		}
	}
	else
	{
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				if (sceneState == SceneState::SCENE_GAME)
				{
					Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_RETURN_TO_MENU);

					inGame.OnLeaveGame();
				}

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
		window.draw(line);
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
	sf::Color selectColor(0, 255, 80);

	for (int i = 0; i < MENU_COUNT; i++)
	{
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(40);
	}

	text[menuState].setFillColor(selectColor);
	text[menuState].setCharacterSize(45);
}

void MenuWrapper::SelectMenu(MenuState menuState)
{
	if (menuState == MenuState::MENU_GAME)
	{
		Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_MENU_START_GAME);

		sceneState = SceneState::SCENE_GAME;
		inGame.Init(IN_GAME_MODE::IN_GAME_MODE_SINGLE);
	}
	else if (menuState == MenuState::MENU_GAME_SERVER)
	{
		sceneState = SceneState::SCENE_GAME;

		sf::Text text;
		text.setFont(Global::addFont);
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(40);
		text.setString("Wait...");
		window->clear();
		window->draw(text);
		window->display();
		inGame.Init(IN_GAME_MODE::IN_GAME_MODE_SERVER);
	}
	else if (menuState == MenuState::MENU_GAME_CLIENT)
	{
		sceneState = SceneState::SCENE_GAME;
		inGame.Init(IN_GAME_MODE::IN_GAME_MODE_CLIENT);
	}
	else if (menuState == MenuState::MENU_SCORES)
	{
		sceneState = SceneState::SCENE_SCORES;
		sceneScores.Init(*window);
	}
	else if (menuState == MenuState::MENU_CREDIT)
	{
		sceneState = SceneState::SCENE_CREDIT;
		sceneCredit.Init(*window);
	}
	else if (menuState == MenuState::MENU_EXIT)
	{
		window->close();
	}
}

void MenuWrapper::OnHeroDied(bool isUser)
{
	sceneState = SceneState::SCENE_MENU;

	if (isUser)
	{
		printf("You lost\n");
	}
	else
	{
		printf("You won\n");
	}
}