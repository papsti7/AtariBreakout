#include "GameScene.h"


GameScene::GameScene(Application& app) : Scene(app)
{
	mBat.setSize(sf::Vector2f(85.f, 12.f));
	mBat.setPosition(getApp().getWindow().getSize().x / 2.f - mBat.getSize().x / 2.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	mBat.setFillColor(sf::Color(51, 102, 255));
}

void GameScene::processEvent(const sf::Event& e)
{
	
}

void GameScene::update()
{
	//Bat movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		mBat.move(-5.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		mBat.move(5.f, 0.f);
	//bat clamping
	if (mBat.getPosition().x <= 0)
		mBat.setPosition(0.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	else if ((mBat.getPosition().x + mBat.getSize().x) >= getApp().getWindow().getSize().x)
		mBat.setPosition(getApp().getWindow().getSize().x - mBat.getSize().x, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
}

void GameScene::render()
{
	getApp().getWindow().draw(mBat);
}