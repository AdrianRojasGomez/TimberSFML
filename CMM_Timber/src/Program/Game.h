#pragma once
#include <SFML/Graphics.hpp>
enum class Side { LEFT, RIGHT, NONE };

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
	const std::string pathBranchGraphic =
		"res/assets/graphics/branch.png";
	const std::string pathPlayerGraphic =
		"res/assets/graphics/player.png";
	const std::string pathRIPGraphic = 
		"res/assets/graphics/RIP.png";
	const std::string pathAxeGraphic = 
		"res/assets/graphics/axe.png";
	const std::string pathLogGraphic = 
		"res/assets/graphics/log.png";


	const std::string pathFont =
		"res/assets/fonts/FugazOne-Regular.ttf";


	sf::RenderWindow* window;
	sf::VideoMode* videoMode;
	sf::Event* event;

	sf::Clock dtClock;

	bool isPaused = true;
	bool canAcceptInput = false;

	sf::RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;

	sf::Time gameTimeTotal;
	const float INITIAL_TIME = 6.0f;
	float timeRemaining = INITIAL_TIME;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

	sf::Font font;
	sf::Text messageText;
	int sizeMessageText = 75;
	float posMessageX = 1920 / 2;
	float posMessageY = 1080 / 2;
	std::string messageString =
		"Press Enter To Start!";

	sf::Text scoreText;
	int sizeScoreText = 100;
	float posScoreX = 250;
	float posScoreY = 50;
	int score = 0;
	const std::string STRING_SCORE_TEXT =
		"Score = 0";

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

	sf::Texture textureBranch;
	static const int NUM_BRANCHES = 6;
	sf::Sprite branches[NUM_BRANCHES];
	Side branchPositions[NUM_BRANCHES];

	sf::Texture texturePlayer;
	sf::Sprite spritePlayer;
	Side playerSide = Side::LEFT;
	int playerInitPosX = 600;
	int playerInitPosY = 860;

	sf::Texture textureRIP;
	sf::Sprite spriteRIP;
	int RIPInitPosX = 675;
	int RIPInitPosY = 2000;

	sf::Texture textureAxe;
	sf::Sprite spriteAxe;
	int axeInitPosX = 700;
	int axeInitPosY = 830;
	const float AXE_POSITION_LEFT = 700;
	const float AXE_POSITION_RIGHT = 1075;

	sf::Texture textureLog;
	sf::Sprite spriteLog;
	int logInitPosX = 810;
	int logInitPosY = 720;
	bool isLogActive = false;
	float logSpeedX = 1000;
	float logSpeedY = 1500;


	void SetupSprite(std::string path, sf::Texture& texture,
		float posX, float posY, sf::Sprite& spriteToSet);
	void SetupText(std::string path, sf::Font& font,
		sf::Text& text, std::string stringToShow, int size);
	void PositionText(sf::Text& text, float posX, float posY);
	void CreateBar(sf::RectangleShape& bar, float width, float height);

	void DrawSprites();
	void DrawText();
	void UpdateBranches(int seed);

};

