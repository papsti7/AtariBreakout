#pragma once
#include "Scene.h"

class GameScene;
class WinScene : public Scene
{
public:
	WinScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update();
	virtual void render();



	~WinScene() {}




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