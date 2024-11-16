#include <iostream>
#include "Game.h"

Game::Game()
{
	videoMode = new sf::VideoMode(SCREEN_X, SCREEN_Y);
	window = new sf::RenderWindow(*videoMode, windowName);
	event = new sf::Event;
	SetupSprites();



}

Game::~Game()
{
	if (videoMode != nullptr)
	{
		delete videoMode;
		videoMode = nullptr;
	}

	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}

	if (event != nullptr)
	{
		delete event;
		event = nullptr;
	}
}

void Game::Run()
{

	while (window->isOpen())
	{
		while (window->pollEvent(*event))
		{
			if (event->type == sf::Event::Closed)
				window->close();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();


		window->draw(spriteBackground);
		window->draw(spriteCloud01);
		window->draw(spriteCloud02);
		window->draw(spriteCloud03);
		window->draw(spriteTree);
		window->draw(spriteBee);
		window->display();
	}

}

void Game::SetupSprites()
{
	if (textureBackground.loadFromFile(pathBackgroundGraphic))
	{
		spriteBackground.setTexture(textureBackground);
		spriteBackground.setPosition(0, 0);
	}
	else
		std::cout << "ERROR LOADING BACKGROUND TEXTURE\n";

	if (textureTree.loadFromFile(pathTreeGraphic))
	{
		spriteTree.setTexture(textureTree);
		spriteTree.setPosition(TREE_X, TREE_Y);
	}

	if (textureBee.loadFromFile(pathBeeGraphic))
	{
		spriteBee.setTexture(textureBee);
		spriteBee.setPosition(0, 800);
	}

	if (textureCloud.loadFromFile(pathCloudGraphic))
	{
		spriteCloud01.setTexture(textureCloud);
		spriteCloud02.setTexture(textureCloud);
		spriteCloud03.setTexture(textureCloud);
		spriteCloud01.setPosition(0, 0);
		spriteCloud02.setPosition(0, 250);
		spriteCloud03.setPosition(0, 500);
	}

}
