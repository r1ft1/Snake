// Snake.cpp : Defines the entry point for the console application.
/////////////////////////////////////////////////////  04/03/17 James Sundaram //////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "snake.h"
#include "fruit.h"
#include "Game.h"

int main()
{
	//Constants
	const int screenWidth = 400;
	const int screenHeight = 400;
	const int tileSize = 16;
	//const sf::Vector2i gridSize(screenWidth % tileSize, screenHeight % tileSize);
	//int gridArray[25][25];
	//const float pi = 3.141592654f;   //not needed 
	//sf::Clock delayTimer;
	//sf::Time delay = sf::seconds(2.f);
	
	//Loading Map background
	sf::Texture Bkgd;
	if (!Bkgd.loadFromFile("Res/Img/grass-light-tile-2.png"))
		return EXIT_FAILURE;
	Bkgd.setRepeated(true);
	sf::Sprite spriteBkgd;
	spriteBkgd.setTexture(Bkgd);
	spriteBkgd.setTextureRect(sf::IntRect(0, 0, screenWidth, screenHeight));

	//Loading Fonts and creating Score Properties
	sf::Font font;
	if (!font.loadFromFile("Res/Fonts/Strasua.ttf"))
		return EXIT_FAILURE;
	int intScore = 0;
	int* ptr = &intScore;
	sf::Text textScore;
	textScore.setFont(font);
	textScore.setCharacterSize(screenHeight / 10);
	

	//Window Properties
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Snake", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);
	
	//sf::Clock Time; //Use to delay gameover or something
	

	//When play is pressed or Gameover is reached
	bool Playing = true;

	//Instantiating the Snake class, creating player 1, at specific location
	Snake player1(400, 400);
	
	
	//player1.snakeSpeed = 160;
	//Instantiating the Fruit class, creating the apple
	Fruit food;
	

	sf::Event event;


	//While window is open
	while (window.isOpen())
	{
		//returns time, multiply by movement for smooth action ****** reword
		//float deltaTime = clock.restart().asSeconds() * 160;
		//float factor = deltaTime * 16;
		
		while (Playing)
		{	
			
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case (sf::Event::Closed):
				{
					window.close();
					Playing = false;
					break;
				}
				case (sf::Event::KeyPressed):
					switch (event.key.code)
					{
					case (sf::Keyboard::Escape):
						Playing = false;
						window.close();
						break;
					}
				}
				

			}
			
			//Display score
			textScore.setString(std::to_string(*ptr));

			
			player1.moveSnake(food, ptr);
			//player1.changeDir();

			
			
			if (player1.snakePlayer[0].getPosition().y > screenHeight - tileSize || player1.snakePlayer[0].getPosition().x > screenWidth - tileSize 
				|| player1.snakePlayer[0].getPosition().x < 0 || player1.snakePlayer[0].getPosition().y < 0)
				{
					player1.snakeDirection = Snake::Direction::Stop;
					player1.snakePlayer[0].setPosition(sf::Vector2f(floor(screenWidth / tileSize / 2) * tileSize, floor(screenHeight / tileSize / 2) * tileSize));
				}

			window.clear(sf::Color::Cyan);
			//window.draw(spriteBkgd);
			
			window.draw(player1.snakePlayer[0]);
			
			
			if (player1.snakePlayer.size() > 1)
			{
				for (int i = 1; i < player1.snakePlayer.size(); i++)
				{
					window.draw(player1.snakePlayer[i]);
				}

			}
			window.draw(food.getShape());
			window.draw(textScore);
			window.display();
				
		}

	}

	return 0;
}