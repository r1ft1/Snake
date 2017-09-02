#include "Game.h"
#include "Display.h"

Game::Game()
{
	Display::init();
}

void Game::runMainLoop()
{
	while (Display::isOpen())
	{
		Display::checkWindowEvents();

		Display::clear();

		//input
		//update
		//draw

		Display::display();
		
	}
}