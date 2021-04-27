#include "MenuWrapper.h"
#include "Global.h"
#include "TestClass.h"

int main()
{
	// Initial test cases
	TestClass tester;
	tester.testBSTInsert();
	tester.testBSTGetLength();
	tester.testBSTSetLength();
	tester.testBSTPrintToFile();
	tester.testBSTPopulateFromFile();
	std::cout << std::endl;

	// Game
	sf::RenderWindow window(sf::VideoMode(1280, 960), "Mouse Dodge");
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