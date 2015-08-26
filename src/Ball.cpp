
#include "Ball.h"



void Ball::create(const InitWindow& Window)
{
  //ball.setPosition(100.f , Window.getWindowHeight() / 2.f);
  ball.setFillColor(sf::Color::Black);
  ball.setRadius(20.f);
  
}

Result Ball::update(const InitWindow& window, Player& player_left, Player& player_right, int& state)
{
	ball.move(speed_up);
	if (ball.getPosition().y >= (window.getWindowHeight() - ball.getRadius()*2.f) || ball.getPosition().y <= 0.f)
		speed_up.y *= -1.f;
	else if (ball.getPosition().x >= (window.getWindowWidth() - ball.getRadius()*2.f))
	{
		state = 0;
		return LEFT_WON;
	}
	else if (ball.getPosition().x <= 0.f)
	{
		state = 0;
		return RIGHT_WON;
	}
	else if (ball.getPosition().x >= (player_right.getPlayerBat().getPosition().x - ball.getRadius()*2.f) && ((ball.getPosition().y + ball.getRadius()) >= player_right.getPlayerBat().getPosition().y &&
		(ball.getPosition().y + ball.getRadius()) <= (player_right.getPlayerBat().getPosition().y + player_right.getPlayerBat().getSize().y)))
	{
		ball.setPosition(player_right.getPlayerBat().getPosition().x - ball.getGlobalBounds().width, ball.getPosition().y);
		speed_up.x *= -1.f;
	
		if (speed_up.x < 0)
			speed_up.x -= 0.3f;
		else if (speed_up.x > 0)
			speed_up.x += 0.3f;
		if (speed_up.y < 0)
			speed_up.y -= 0.3f;
		else if (speed_up.y > 0)
			speed_up.y += 0.3f;


	}
		
	else if (ball.getPosition().x <= (player_left.getPlayerBat().getSize().x + 5.f) && ((ball.getPosition().y + ball.getRadius()) >= player_left.getPlayerBat().getPosition().y &&
		(ball.getPosition().y + ball.getRadius()) <= (player_left.getPlayerBat().getPosition().y + player_left.getPlayerBat().getSize().y)))
	{
		ball.setPosition(player_left.getPlayerBat().getPosition().x + player_left.getPlayerBat().getGlobalBounds().width, ball.getPosition().y);
		speed_up.x *= -1.f;
		if (speed_up.x < 0)
			speed_up.x -= 0.3f;
		else if (speed_up.x > 0)
			speed_up.x += 0.3f;
		if (speed_up.y < 0)
			speed_up.y -= 0.3f;
		else if (speed_up.y > 0)
			speed_up.y += 0.3f;
	}
		
	return NOTHING;
}



sf::CircleShape& Ball::getBall()
{
  return ball;
}

void Ball::resetBallPos(const InitWindow& window)
{
	ball.setPosition(float(window.getWindowWidth() / 2.f - ball.getGlobalBounds().width / 2.f), float(window.getWindowHeight() / 2.f - ball.getGlobalBounds().height / 2.f));

}

void Ball::setSpeed(float x, float y)
{
	speed_up.x = x;
	speed_up.y = y;
}