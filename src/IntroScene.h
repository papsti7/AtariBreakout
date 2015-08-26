#pragma once
#include "Scene.h"

class IntroScene : public Scene
{
public:
	IntroScene(Application& app) : Scene(app)
	{ 
		mBackgroundTex.loadFromFile("data/intro.jpg");
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