#pragma once
#include <random>
#include <SFML\Graphics.hpp>
struct Fruit
{
public:
	Fruit();
	sf::RectangleShape apple;
	void changeLoc(float screenSize, float blockSize);
	sf::RectangleShape getShape();
	sf::FloatRect getLoc();
	bool eaten = true;
};