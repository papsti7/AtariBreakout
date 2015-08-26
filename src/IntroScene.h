#pragma once
#include "Scene.h"
#include "GameScene.h"

class IntroScene : public Scene
{
public:
	IntroScene(Application& app) : Scene(app)
	{ 
		mBackgroundTex.loadFromFile("D:/Programmieren/AtariBreakout/AtariBreakout/data/intro.png");
		mBackgroundSpr.setTexture(mBackgroundTex);
	}

	virtual void processEvent(const sf::Event& e);
	virtual void update();
	virtual void render();


	
	~IntroScene() {}


	

private:
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSpr;
	




};