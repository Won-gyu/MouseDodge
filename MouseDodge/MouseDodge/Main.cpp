#include "MenuWrapper.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mouse Dodge");
	sf::Event event;

	MenuWrapper menu;
	menu.Init(&window);

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
		menu.Update();
		menu.Render(window);
		window.display();
	}

	return 0;
}