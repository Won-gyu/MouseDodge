#include "MenuWrapper.h"
#include "Global.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Mouse Dodge");
	sf::Event event;

	MenuWrapper menu;
	menu.Init(&window);
	sf::Clock clock;

	if (!Global::commonFont.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	if (!Global::addFont.loadFromFile("MandatoryPlaything-nRRd0.ttf"))
	{
		// handle error
	}

	if (!Global::titleFont.loadFromFile("MandaloreLaserTitle-GOOGy.otf"))
	{
		// handle error
	}

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		while (window.pollEvent(event))
		{
			menu.OnEvent(event);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		menu.Update(window, dt);
		menu.Render(window);
		window.display();
	}

	return 0;
}