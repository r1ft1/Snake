#pragma once
#include "snake.h"
#include "fruit.h"

Snake::Snake(float x, float y)
{
	sf::RectangleShape snakeHead;
	snakeHead.setFillColor(sf::Color::Green);
	snakeHead.setSize(sf::Vector2f(16.f, 16.f));
	snakeHead.setOutlineThickness(-1);
	snakePlayer.push_back(snakeHead);
}

void Snake::addBodyPart()
{
	sf::RectangleShape snakeBody;
	snakeBody.setSize(sf::Vector2f(16,16));
	snakeBody.setPosition(sf::Vector2f(-16, -16)); //Spawns offscreen then position is set to behind the head
	snakeBody.setOutlineThickness(-1);
	snakeBody.setFillColor(sf::Color::Magenta);
	snakePlayer.push_back(snakeBody);
}

void Snake::changeDir()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (snakeDirection != Direction::Down)
			snakeDirection = Direction::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (snakeDirection != Direction::Up)
			snakeDirection = Direction::Down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (snakeDirection != Direction::Right)
			snakeDirection = Direction::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (snakeDirection != Direction::Left)
			snakeDirection = Direction::Right;
	}
}

void Snake::moveTail()
{
	if (snakePlayer.size() > 1)
	{
		prevPos = snakePlayer[0].getPosition();
		for (int i = 1; i < snakePlayer.size(); i++)
		{
			temp = snakePlayer[i].getPosition();
			snakePlayer[i].setPosition(prevPos);
			prevPos = temp;
		}
	}
}

void Snake::moveBody()
{
	switch (snakeDirection)
	{
		case Snake::Direction::Right:
		{
			snakePlayer[0].move(16.f, 0);
			break;
		}
		case Snake::Direction::Left:
		{
			snakePlayer[0].move(-16.f, 0);
			break;
		}
		case Snake::Direction::Up:
		{
			snakePlayer[0].move(0, -16.f);
			break;
		}
		case Snake::Direction::Down:
		{
			snakePlayer[0].move(0, 16.f);
			break;
		}
	//default:
	//	break;
	}
}

void Snake::moveSnake(Fruit food, int* score)
{
	if (clock.getElapsedTime().asSeconds() >= 0.1)
	{
		changeDir();
		moveTail();
		moveBody();
		clock.restart();
	}
	if (snakePlayer[0].getGlobalBounds().intersects(food.getLoc()))
	{
		//eaten = true;  //change value 400 to DISPLAY's SCREENWIDTH
		changeLoc(400, apple.getSize().x);
		*score++;
		addBodyPart();
	}
}

