#pragma once

#include "SFML\Graphics.hpp"

class Scene;
class Application
{
public:
	Application();

	void run();

	void setActiveScene(Scene* ptr);

	sf::RenderWindow& getWindow() { return mWindow; }
	sf::Font& getFont() { return mFont; }
	unsigned& getHighscore() { return mHighscore; }

	void increaseHighscore() { mHighscore++; }
	void resetHighscore() { mHighscore = 0; }

	~Application();

private:

	sf::RenderWindow mWindow;
	Scene* mActiveScene;
	sf::Font mFont;
	unsigned mHighscore;

	void processEvent(const sf::Event& e);
	void update();
	void render();

};