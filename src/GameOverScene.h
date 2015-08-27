#pragma once
#include "Scene.h"
#include <sstream>

class GameScene;
class GameOverScene : public Scene
{
public:
	GameOverScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update();
	virtual void render();



	~GameOverScene() {}




private:
	//screenshot of last frame
	sf::Image mBackground;
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSpr;
	//highscore
	sf::Text mHighscore;
	//info
	sf::Text mInfo;

};