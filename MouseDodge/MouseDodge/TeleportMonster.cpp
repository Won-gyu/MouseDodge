#include "TeleportMonster.h"

TeleportMonster::~TeleportMonster()
{
}

void TeleportMonster::Init()
{
	clock.restart();
	tpClock.restart();
	this->teleporting = false;
	this->tpX = 0;
	this->tpY = 0;
	this->inTransport = false;

	circleShape.setFillColor(sf::Color::Magenta);
	tpCircleShape1.setFillColor(sf::Color::Magenta);
	tpCircleShape1.setRadius(10 * Global::screenMultiplier);
	tpCircleShape2.setFillColor(sf::Color::Magenta);
	tpCircleShape2.setRadius(10 * Global::screenMultiplier);
}

void TeleportMonster::OnUpdate()
{
	// Check if teleporting or if it is time to start teleporing
	if (teleporting)
	{
		updateTeleporting();
	}
	else
	{
		// Do default update tasks
		BaseMonster::OnUpdate();

		if (clock.getElapsedTime().asSeconds() > 3.0f)
		{
			teleporting = true;
			if (rand() % 2 == 0)
			{
				tpX = Global::getHeroPosition().x + (2.0f * radius);
			}
			else
			{
				tpX = Global::getHeroPosition().x - (2.0f * radius);
			}
			if (rand() % 2 == 0)
			{
				tpY = Global::getHeroPosition().y + (2.0f * radius);
			}
			else
			{
				tpY = Global::getHeroPosition().y - (2.0f * radius);
			}
			tpCircleShape1.setPosition(posX - tpCircleShape1.getRadius(), posY - tpCircleShape1.getRadius());
			tpCircleShape2.setPosition(tpX - tpCircleShape2.getRadius(), tpY - tpCircleShape2.getRadius());

			tpClock.restart();

			Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_TELEPORT_MONSTER_TELEPORT);
		}
	}
}

void TeleportMonster::Render(sf::RenderWindow& window)
{
	if (inTransport)
	{
		window.draw(tpCircleShape1);
		window.draw(tpCircleShape2);
	}
	else
	{
		BaseMonster::Render(window);
	}
}

bool TeleportMonster::AllowCollision()
{
	if (teleporting)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void TeleportMonster::playDieSound()
{
	Global::PlaySoundEffect(SOUND_SOURCE::SOUND_SOURCE_TELEPORT_MONSTER_DIE);
}

void TeleportMonster::updateTeleporting()
{
	if (tpClock.getElapsedTime().asSeconds() < 1)
	{
		// Fade alpha value of color
		int alpha = 255 - (tpClock.getElapsedTime().asSeconds() * 255);
		sf::Color newColor(
			circleShape.getFillColor().r, 
			circleShape.getFillColor().g, 
			circleShape.getFillColor().b, 
			alpha);
		circleShape.setFillColor(newColor);
	}
	else if (tpClock.getElapsedTime().asSeconds() < 2)
	{
		// Show small pulsing circles at both locations if possible
		inTransport = true;

		int alpha = 0;
		if (tpClock.getElapsedTime().asSeconds() < 2.5)
		{
			alpha = (tpClock.getElapsedTime().asSeconds() - 2.0f) * 2 * 255;
		}
		else
		{
			alpha = 255 - ((tpClock.getElapsedTime().asSeconds() - 2.5f) * 2 * 255);
		}
		sf::Color newColor(
			circleShape.getFillColor().r,
			circleShape.getFillColor().g,
			circleShape.getFillColor().b,
			alpha);
		tpCircleShape1.setFillColor(newColor);
		tpCircleShape2.setFillColor(newColor);
	}
	else if (tpClock.getElapsedTime().asSeconds() < 3)
	{
		// Raise alpha value of color at new location
		posX = tpX;
		posY = tpY;
		circleShape.setPosition(posX - radius, posY - radius);
		inTransport = false;

		int alpha = (tpClock.getElapsedTime().asSeconds() - 2) * 255;
		sf::Color newColor(
			circleShape.getFillColor().r,
			circleShape.getFillColor().g,
			circleShape.getFillColor().b,
			alpha);
		circleShape.setFillColor(newColor);
	}
	else
	{
		// End teleportation and set new speed values
		teleporting = false;
		clock.restart();
		// Update speed in the same way as InGame
		float sX = 0.0f, sY = 0.0f;
		switch (rand() % 4)
		{
		case 0:
			sX = (float)(rand() % 9) - 4.0f;
			sY = (float)(rand() % 3) + 2.0f;
			break;
		case 1:
			sX = (float)(rand() % 9) - 4.0f;
			sY = 0.0f - ((float)(rand() % 3) + 2.0f);
			break;
		case 2:
			sX = (float)(rand() % 3) + 2.0f;
			sY = (float)(rand() % 9) - 4.0f;
			break;
		case 3:
			sX = 0.0f - ((float)(rand() % 3) + 2.0f);
			sY = (float)(rand() % 9) - 4.0f;
			break;
		}
		// Scale down numbers so they move at normal speed 
		sX = (sX / 100.0f) * Global::screenMultiplier;
		sY = (sY / 100.0f) * Global::screenMultiplier;
		speedX = sX * 2000.0f;
		speedY = sY * 2000.0f;
	}
}