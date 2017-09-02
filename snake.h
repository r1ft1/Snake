#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "fruit.h"
//Player struct

struct Snake : public Fruit
{
public:
	std::vector <sf::RectangleShape> snakePlayer;
	sf::Vector2f prevPos;
	sf::Vector2f temp;
	void addBodyPart();
	Snake(float x, float y);

	//int snakeSpeed; //Use for creating difficulty levels

	sf::Clock clock;	

	enum Direction
	{
		Stop, Up, Down, Right, Left
	} snakeDirection = Stop;

	void changeDir();
	void moveTail();
	void moveBody();
	void moveSnake(Fruit, int*);
};
