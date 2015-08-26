#include "IntroScene.h"


void IntroScene::processEvent(const sf::Event& e)
{
	if (e.type == sf::Event::KeyReleased)
	{
		if (e.key.code == sf::Keyboard::Return)
		{
			//Intro beenden
			getApp().setActiveScene(new GameScene(getApp()));
		}
	}
}

void IntroScene::update()
{
	
}

void IntroScene::render()
{
	getApp().getWindow().draw(mBackgroundSpr);
}