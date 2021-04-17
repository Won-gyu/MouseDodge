#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mouse Dodge");

	sf::Event event;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(40);
	text.setString("TEST");

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();

		window.draw(text);

		window.display();
	}

	return 0;
}