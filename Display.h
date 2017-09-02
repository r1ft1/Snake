#pragma once
#include <SFML\Graphics.hpp>

namespace Display
{
	void init();

	void clear();
	void display();

	void checkWindowEvents();

	bool isOpen();

	constexpr int WIDTH = 400;
	constexpr int HEIGHT = 400;
}