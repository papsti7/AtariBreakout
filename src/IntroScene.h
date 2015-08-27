#pragma once
#include "Scene.h"
#include "GameScene.h"

class IntroScene : public Scene
{
public:
	IntroScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update();
	virtual void render();


	
	~IntroScene() {}


	

private:
	sf::Texture mBackgroundTex;
	sf::Sprite mBackgroundSpr;
	




};