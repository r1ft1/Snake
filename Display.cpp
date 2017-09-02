#include "Display.h"
#include <memory>
namespace Display
{
	std::unique_ptr<sf::RenderWindow> window;

	void init()
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "Snake");
	}

	void clear()
	{
		(*window).clear();
	}
	void display()
	{
		window->display();
	}

	void checkWindowEvents()
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}

		}

	}

	bool isOpen()
	{
		return window->isOpen();
	}
}