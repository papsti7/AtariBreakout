#include "GameScene.h"


GameScene::GameScene(Application& app) : Scene(app), mStonesNumber(0), active(true), active2(true)
{
	//init Highscore
	getApp().resetHighscore();
	mHighscore.setFont(getApp().getFont());
	mHighscore.setCharacterSize(20);
	mHighscore.setColor(sf::Color(255, 255, 255));
	mHighscore.setPosition(10.f, 10.f);



	//init Ball
	mBat.setSize(sf::Vector2f(85.f, 12.f));
	mBat.setPosition(getApp().getWindow().getSize().x / 2.f - mBat.getSize().x / 2.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	mBat.setFillColor(sf::Color(51, 102, 255));

	mBall.setRadius(7.f);
	mBall.setPosition(getApp().getWindow().getSize().x / 2.f - mBall.getRadius(), getApp().getWindow().getSize().y - 100.f);
	mBall.setFillColor(sf::Color(150, 150, 150));

	mBallSpeed = { -5.f, -4.f };
	
	sf::RectangleShape temp_rect;
	
	//stones init
	for (int row = 0; row <= 2; row++)
	{
		if (row == 0)
		{
			temp_rect.setFillColor(sf::Color::Red);
			mHeightSpaceCounter = 50;
		}
		else if (row == 1)
		{
			temp_rect.setFillColor(sf::Color::Green);
			mHeightSpaceCounter = 105;
		}
		else if (row == 2)
		{
			temp_rect.setFillColor(sf::Color::Blue);
			mHeightSpaceCounter = 155;
		}
		mStones.push_back(std::vector<sf::RectangleShape>());
		temp_rect.setSize(sf::Vector2f(70.f - row*10.f, 40.f - row*5.f));
		mWidthSpaceCounter = 0;
		while (mWidthSpaceCounter <= (getApp().getWindow().getSize().x - (10 + 70 - row*10.f)))
		{
			mWidthSpaceCounter += 10;

			temp_rect.setPosition(float(mWidthSpaceCounter), float(mHeightSpaceCounter));
			mStones.at(row).push_back(temp_rect);
			mStonesNumber++;

			mWidthSpaceCounter += 70 - row*10;
		}
	}
	
	
	//-------------------------------------------------------------------------------------
	
	
	
	
	mUpRow = 50 - 15;//
	mDownRow = 50 + 40;

}

void GameScene::processEvent(const sf::Event& e)
{
	
}

void GameScene::update()
{
	//Bat movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		mBat.move(-5.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		mBat.move(5.f, 0.f);
	//bat clamping
	if (mBat.getPosition().x <= 0.f)
		mBat.setPosition(0.f, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));
	else if ((mBat.getPosition().x + mBat.getSize().x) >= getApp().getWindow().getSize().x)
		mBat.setPosition(getApp().getWindow().getSize().x - mBat.getSize().x, getApp().getWindow().getSize().y - (mBat.getSize().y + 25.f));


	for (int row = 0; row <= 2; row++)
	{
		if (row == 0)
		{
			mUpRow = 42;
			mDownRow = 90;
		}
		else if (row == 1)
		{
			mUpRow = 97;
			mDownRow = 140;
		}
		else if (row == 2)
		{
			mUpRow = 147;
			mDownRow = 185;
		}
		//Ball collision with stones
		unsigned counter = 0;
		//upside
		if (mBall.getPosition().y <= (mUpRow))
		{
			counter = 0;
			for (auto& it : mStones.at(row))
			{
				if (((mBall.getPosition().y + mBall.getRadius()*2.f) >= it.getPosition().y) && (mBall.getPosition().x >= (it.getPosition().x - mBall.getRadius())) && (mBall.getPosition().x <= (it.getPosition().x + it.getSize().x - mBall.getRadius())))
				{
					mBallSpeed.y *= -1.f;
					mStones.at(row).erase(mStones.at(row).begin() + counter);
					getApp().increaseHighscore();
					counter = 0;
					break;
				}
				counter++;
			}
		}
		else if (mBall.getPosition().y <= mDownRow)
		{
			counter = 0;
		
			for (auto& it : mStones.at(row))
			{	
				if ((mBall.getPosition().x >= (it.getPosition().x - mBall.getRadius())) && (mBall.getPosition().x <= (it.getPosition().x + it.getSize().x - mBall.getRadius())))
				{
					if (mBall.getPosition().y <= (mDownRow - 5.f))//sides
					{
						if (mBall.getPosition().x > (it.getPosition().x + (it.getSize().x / 2.f)))//right side
						{
							mBall.setPosition(it.getPosition().x + it.getSize().x, mBall.getPosition().y);
							mBallSpeed.x *= -1.f;
							getApp().increaseHighscore();
						}
						else//left side
						{
							mBall.setPosition(it.getPosition().x - mBall.getRadius() * 2.f, mBall.getPosition().y);
							mBallSpeed.x *= -1.f;
							getApp().increaseHighscore();
						}
					
				
					}
					else//down
					{
						mBall.setPosition(mBall.getPosition().x, float(mDownRow));
						mBallSpeed.y *= -1.f;
						getApp().increaseHighscore();
					}
					mStones.at(row).erase(mStones.at(row).begin() + counter);
					counter = 0;
					break;
				}
				counter++;
			}
			counter = 0;
		
		}

	}

	//calculate current score
	std::stringstream strstring;
	strstring << "Score: " << getApp().getHighscore();
	mHighscore.setString(strstring.str());

	//ball speed management
	unsigned counter = 0;
	for (auto& rows : mStones)
		for (auto& stones : rows)
			counter++;

	if (mStones.at(0).empty() && mStones.at(1).empty() && mStones.at(2).empty())
		getApp().setActiveScene(new WinScene(getApp()));


	

	


	if ((mStonesNumber - counter) >= 10)
		if (active)
		{
			mBallSpeed *= 1.3f;
			active = false;
		}
	else if ((mStonesNumber - counter) >= 28)
		if (active2)
		{
			mBallSpeed *= 1.3f;
			active2 = false;
		}

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
	for (auto& row : mStones)
		for (auto& stone : row)
			getApp().getWindow().draw(stone);

	getApp().getWindow().draw(mBat);
	getApp().getWindow().draw(mBall);
	//show current score
	getApp().getWindow().draw(mHighscore);
}