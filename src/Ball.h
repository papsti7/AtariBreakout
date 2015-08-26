#ifndef BALL_H
#define BALL_H
//------------------------------------------------------------------------------
// Ball.h
// Description : 
// 
// Author : Stefan Papst
// Softwareengeneering and Businessmanagement @ TU GRAZ
//------------------------------------------------------------------------------   

#include "GameScene.h"



class Ball
{
private:
  sf::CircleShape ball;

  sf::Vector2f speed_up;



public:

	Ball() : speed_up(0.f, 0.f) { }

  void create();
  

  Result update(const InitWindow& window, Player& player_left, Player& player_right, int& state);

  void resetBallPos(const InitWindow& window);

  void setSpeed(float x, float y);

  sf::CircleShape& getBall();


};











#endif BALL_H