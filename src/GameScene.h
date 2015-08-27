#pragma once
#include "Scene.h"
#include "GameOverScene.h"
#include "WinScene.h"

#include <vector>

class GameScene : public Scene
{
public:
	GameScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update();
	virtual void render();



	~GameScene() {}




private:
	sf::RectangleShape mBat;
	sf::CircleShape mBall;

	sf::Vector2f mBallSpeed;

	sf::Text mHighscore;
	
	//rects and counter
	std::vector<std::vector<sf::RectangleShape>> mStones;
	unsigned mWidthSpaceCounter;
	unsigned mHeightSpaceCounter;
	unsigned mUpRow;
	unsigned mDownRow;
	unsigned mStonesNumber;

	bool active;
	bool active2;
};