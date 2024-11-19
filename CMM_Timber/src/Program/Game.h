#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	void Run();

private:

	const int SCREEN_X = 1920;
	const int SCREEN_Y = 1080;
	const int TREE_X = 810;
	const int TREE_Y = 0;
	const std::string windowName = "Timber!!!";

	const std::string pathBackgroundGraphic = 
		"res/assets/graphics/background.png";
	const std::string pathTreeGraphic = 
		"res/assets/graphics/tree.png";
	const std::string pathBeeGraphic =
		"res/assets/graphics/bee.png";
	const std::string pathCloudGraphic =
		"res/assets/graphics/cloud.png";

	bool isPaused = true;

	sf::RenderWindow* window;
	sf::VideoMode* videoMode;
	sf::Event* event;

	sf::Clock dtClock;

	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	sf::Texture textureTree;
	sf::Sprite spriteTree;

	sf::Texture textureBee;
	sf::Sprite spriteBee;
	bool isbeeActive = false;
	float beeSpeed = 0.0f;

	sf::Texture textureCloud;
	sf::Sprite spriteCloud01;
	bool isCloud01Active = false;
	float cloud01Speed = 0.0f;
	sf::Sprite spriteCloud02;
	bool isCloud02Active = false;
	float cloud02Speed = 0.0f;
	sf::Sprite spriteCloud03;
	bool isCloud03Active = false;
	float cloud03Speed = 0.0f;

	void SetupSprite(std::string path, sf::Texture& texture,
		float posX, float posY, sf::Sprite& spriteToSet);
	void DrawSprites();

};

