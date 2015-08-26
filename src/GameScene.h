#pragma once
#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene(Application& app);

	virtual void processEvent(const sf::Event& e);
	virtual void update();
	virtual void render();



	~GameScene() {}




private:
	sf::RectangleShape mBat;
	sf::CircleShape mBall;

	sf::Vector2f mBallSpeed;




};