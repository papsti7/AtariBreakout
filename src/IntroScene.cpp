#include "IntroScene.h"


IntroScene::IntroScene(Application& app) : Scene(app)
{
	mBackgroundTex.loadFromFile("D:/Programmieren/AtariBreakout/AtariBreakout/data/intro.png");
	mBackgroundSpr.setTexture(mBackgroundTex);
	mBackgroundSpr.setOrigin(getApp().getWindow().getSize().x / 2.f, getApp().getWindow().getSize().y / 2.f);
	mBackgroundSpr.setPosition(getApp().getWindow().getSize().x / 2.f, getApp().getWindow().getSize().y / 2.f);
}

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
	//mBackgroundSpr.rotate(2);
}                                  

void IntroScene::render()
{
	getApp().getWindow().draw(mBackgroundSpr);
}