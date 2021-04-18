#include "MenuWrapper.h"
#include "Global.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mouse Dodge");
	sf::Event event;

	MenuWrapper menu;
	menu.Init(&window);

	if (!Global::commonFont.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			menu.OnEvent(event);
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		menu.Update(window);
		menu.Render(window);
		window.display();
	}

	return 0;
}