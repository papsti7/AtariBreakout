#include "GameScene.h"


GameScene::GameScene(Application& app) : Scene(app)
{
	mBat.setSize(sf::Vector2f(85.f, 12.f));
	mBat.setPosition(getApp().getWindow().getSize().x / 2.f - mBat.getSize().x / 2.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	mBat.setFillColor(sf::Color(51, 102, 255));

	mBall.setRadius(7.f);
	mBall.setPosition(getApp().getWindow().getSize().x / 2.f - mBall.getRadius(), getApp().getWindow().getSize().y - 100.f);
	mBall.setFillColor(sf::Color(150, 150, 150));

	mBallSpeed = { -5.f, -4.f };
	
	//stones init
	sf::RectangleShape temp_rect;
	temp_rect.setFillColor(sf::Color::Red);
	temp_rect.setSize(sf::Vector2f(70.f, 40.f));
	mUpRowOne = 50 - 8;
	mDownRowOne = 50 + 40;
	while (mSpaceCounter <= (getApp().getWindow().getSize().x - (10 + 70)))
	{
		mSpaceCounter += 10;
		
		temp_rect.setPosition(float(mSpaceCounter), 50.f);
		mStones.push_back(temp_rect);

		mSpaceCounter += 70;
	}

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
	if (mBat.getPosition().x <= 0.f)
		mBat.setPosition(0.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	else if ((mBat.getPosition().x + mBat.getSize().x) >= getApp().getWindow().getSize().x)
		mBat.setPosition(getApp().getWindow().getSize().x - mBat.getSize().x, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));



	//Ball collision with stones
	unsigned counter = 0;
	//upside
	if (mBall.getPosition().y <= mUpRowOne)
	{
		counter = 0;
		for (auto& it : mStones)
		{
			if (((mBall.getPosition().y + mBall.getRadius()*2.f) >= it.getPosition().y) && (mBall.getPosition().x >= (it.getPosition().x - mBall.getRadius())) && (mBall.getPosition().x <= (it.getPosition().x + it.getSize().x - mBall.getRadius())))
			{
				mBallSpeed.y *= -1.f;
				mStones.erase(mStones.begin() + counter);
				counter = 0;
				break;
			}
			counter++;
		}
	}
	else if (mBall.getPosition().y <= mDownRowOne)
	{
		counter = 0;
		
		for (auto& it : mStones)
		{	
			if ((mBall.getPosition().x >= (it.getPosition().x - mBall.getRadius())) && (mBall.getPosition().x <= (it.getPosition().x + it.getSize().x - mBall.getRadius())))
			{
				if (mBall.getPosition().y <= (mDownRowOne - 5.f))//sides
				{
					if (mBall.getPosition().x > (it.getPosition().x + (it.getSize().x / 2.f)))//right side
					{
						mBall.setPosition(it.getPosition().x + it.getSize().x, mBall.getPosition().y);
						mBallSpeed.x *= -1.f;
					}
					else//left side
					{
						mBall.setPosition(it.getPosition().x - mBall.getRadius() * 2.f, mBall.getPosition().y);
						mBallSpeed.x *= -1.f;
					}
					
				
				}
				else//down
				{
					mBall.setPosition(mBall.getPosition().x, float(mDownRowOne));
					mBallSpeed.y *= -1.f;
				}
				mStones.erase(mStones.begin() + counter);
				counter = 0;
				break;
			}
			counter++;
		}
		counter = 0;
		
	}

	if (mStones.empty())
		getApp().setActiveScene(new WinScene(getApp()));





	//ball clamping of three sides
	if (mBall.getPosition().x <= 0.f)
	{
		mBall.setPosition(0.f, mBall.getPosition().y);
		mBallSpeed.x *= -1.f;
	}
	else if (mBall.getPosition().y <= 0.f)
	{
		mBall.setPosition(mBall.getPosition().x, 0.f);
		mBallSpeed.y *= -1.f;
	}
	else if ((mBall.getPosition().x + mBall.getRadius()*2.f) >= getApp().getWindow().getSize().x)
	{
		mBall.setPosition(getApp().getWindow().getSize().x - mBall.getRadius()*2.f, mBall.getPosition().y);
		mBallSpeed.x *= -1.f;
	}
	//ball and bat collision
	else if (((mBall.getPosition().y + mBall.getRadius()*2.f) >= mBat.getPosition().y) && (mBall.getPosition().x >= (mBat.getPosition().x - mBall.getRadius())) && (mBall.getPosition().x <= (mBat.getPosition().x + mBat.getSize().x - mBall.getRadius())))
	{
		mBall.setPosition(mBall.getPosition().x, (mBat.getPosition().y) - mBall.getRadius() * 2.f - 1.f);
		mBallSpeed.y *= -1.f;
	}
	//game over -> new Scene
	else if ((mBall.getPosition().y + mBall.getRadius()*2.f) >= mBat.getPosition().y)
	{
		getApp().setActiveScene(new GameOverScene(getApp()));
	}
	//ball movement
	mBall.move(mBallSpeed);
}

void GameScene::render()
{
	for(auto& it : mStones)
		getApp().getWindow().draw(it);
	getApp().getWindow().draw(mBat);
	getApp().getWindow().draw(mBall);

}