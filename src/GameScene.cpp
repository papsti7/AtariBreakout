#include "GameScene.h"


GameScene::GameScene(Application& app) : Scene(app)
{
	mBat.setSize(sf::Vector2f(85.f, 12.f));
	mBat.setPosition(getApp().getWindow().getSize().x / 2.f - mBat.getSize().x / 2.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	mBat.setFillColor(sf::Color(51, 102, 255));

	mBall.setRadius(7.f);
	mBall.setPosition(getApp().getWindow().getSize().x / 2.f - mBall.getRadius(), getApp().getWindow().getSize().y - 100.f);
	mBall.setFillColor(sf::Color(150, 150, 150));

	mBallSpeed = { -5.f, -2.f };
	
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

	//ball clamping

	//ball movement
	mBall.move(mBallSpeed);
}

void GameScene::render()
{
	getApp().getWindow().draw(mBat);
	getApp().getWindow().draw(mBall);

}