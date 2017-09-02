#pragma once
#include "fruit.h"
#include <iostream>
Fruit::Fruit()
{
	//Apple properties
	apple.setSize(sf::Vector2f(16.f, 16.f));
	apple.setFillColor(sf::Color::Red);
	//apple.setOrigin(sf::Vector2f(0,0));
	changeLoc(400, apple.getSize().x);
}

sf::RectangleShape Fruit::getShape()
{
	return apple;
}

sf::FloatRect Fruit::getLoc()
{
	return apple.getGlobalBounds();
}

void Fruit::changeLoc(float screenSize, float blockSize)
{
	//Create random x,y coordinates, then Move apple to random location
	//if (eaten)
	//{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> loc(1, 24); //loc, create number between 16 and 384, 
		int X = loc(rng);
		int Y = loc(rng);
		apple.setPosition(X * 16, Y * 16);
	//	eaten = false;
		std::cout << X * 16 << ", " << Y * 16 << std::endl;
	//}
}

