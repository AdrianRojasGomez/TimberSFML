#include <iostream>
#include <sstream>
#include "Game.h"

Game::Game()
{
	videoMode = new sf::VideoMode(SCREEN_X, SCREEN_Y);
	window = new sf::RenderWindow(*videoMode, windowName);
	event = new sf::Event;
	SetupSprite(pathBackgroundGraphic, textureBackground, 0.0f, 0.0f, spriteBackground);
	SetupSprite(pathBeeGraphic, textureBee, 0.0f, 800.0f, spriteBee);
	SetupSprite(pathCloudGraphic, textureCloud, 0.0f, 0.0f, spriteCloud01);
	SetupSprite(pathCloudGraphic, textureCloud, 0.0f, 250, spriteCloud02);
	SetupSprite(pathCloudGraphic, textureCloud, 0.0f, 500, spriteCloud03);
	SetupText(pathFont, font, messageText, messageString, sizeWelcomeText);
	SetupText(pathFont, font, scoreText, STRING_SCORE_TEXT, sizeScoreText);
	PositionText(messageText, posMessageX, posMessageY);
	PositionText(scoreText, posScoreX, posScoreY);
	CreateBar(timeBar, timeBarStartWidth, timeBarHeight);
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				isPaused = false;
				timeRemaining = 6.0f;
				dtClock.restart();

			}

		}

		if (!isPaused)
		{
			//restart dt clock
			sf::Time dt = dtClock.restart();

			//modify time bar
			timeRemaining -= dt.asSeconds();
			timeBar.setSize(sf::Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

			if (timeRemaining <= 0.0f)
			{
				isPaused = true;
				messageText.setString("Out of time!");
				PositionText(messageText, posMessageX, posMessageY);
			}


			//Update the bee
			if (!isbeeActive)
			{
				srand((int)time(0));
				beeSpeed = (rand() % 200) + 200;
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				isbeeActive = true;
			}
			else
			{
				spriteBee.setPosition(
					spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);
			}

			if (spriteBee.getPosition().x < -100)
				isbeeActive = false;

			//Update the coulds
			if (!isCloud01Active)
			{
				srand((int)time(0) * 10);
				cloud01Speed = (rand() % 200);

				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud01.setPosition(-200, height);
				isCloud01Active = true;
			}
			else
			{
				spriteCloud01.setPosition(
					spriteCloud01.getPosition().x + (cloud01Speed * dt.asSeconds()),
					spriteCloud01.getPosition().y);
			}
			if (spriteCloud01.getPosition().x > SCREEN_X)
				isCloud01Active = false;

			if (!isCloud02Active)
			{
				srand((int)time(0) * 20);
				cloud02Speed = (rand() % 200);

				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud02.setPosition(-200, height);
				isCloud02Active = true;
			}
			else
			{
				spriteCloud02.setPosition(
					spriteCloud02.getPosition().x + (cloud02Speed * dt.asSeconds()),
					spriteCloud02.getPosition().y);
			}
			if (spriteCloud02.getPosition().x > SCREEN_X)
				isCloud02Active = false;

			if (!isCloud03Active)
			{
				srand((int)time(0) * 30);
				cloud03Speed = (rand() % 200);

				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud03.setPosition(-200, height);
				isCloud03Active = true;
			}
			else
			{
				spriteCloud03.setPosition(
					spriteCloud03.getPosition().x + (cloud03Speed * dt.asSeconds()),
					spriteCloud03.getPosition().y);
			}
			if (spriteCloud03.getPosition().x > SCREEN_X)
				isCloud03Active = false;

			std::stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());
		}

		window->clear();
		DrawSprites();
		DrawText();
		window->display();
	}

}

void Game::SetupSprite(std::string path, sf::Texture& texture, float posX, float posY, sf::Sprite& spriteToSet)
{
	if (texture.loadFromFile(path))
	{
		spriteToSet.setTexture(texture);
		spriteToSet.setPosition(posX, posY);
	}
	else
		std::cout << "ERROR LOADING" << path << "TEXTURE\n";
}

void Game::SetupText(std::string path, sf::Font& font, sf::Text& text, std::string stringToShow, int size)
{
	if (font.loadFromFile(path))
	{
		text.setString(stringToShow);
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(size);
		text.setFont(font);
		text.setOutlineColor(sf::Color::Black);
		text.setOutlineThickness(2);
	}
	else
		std::cout << "ERROR LOADING" << path << "TEXTURE\n";
}

void Game::PositionText(sf::Text& text, float posX, float posY)
{
	sf::FloatRect rect = text.getLocalBounds();
	text.setOrigin((rect.left + rect.width) / 2, (rect.top + rect.height) / 2);
	text.setPosition(posX, posY);

}

void Game::CreateBar(sf::RectangleShape& bar, float width, float height)
{
	bar.setSize(sf::Vector2f(width, height));
	bar.setFillColor(sf::Color::Red);
	bar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
}

void Game::DrawSprites()
{
	window->draw(spriteBackground);
	window->draw(spriteCloud01);
	window->draw(spriteCloud02);
	window->draw(spriteCloud03);
	window->draw(spriteTree);
	window->draw(spriteBee);
	window->draw(timeBar);
}

void Game::DrawText()
{
	window->draw(messageText);
	window->draw(scoreText);
}
