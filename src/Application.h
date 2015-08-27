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

	~Application();

private:

	sf::RenderWindow mWindow;
	Scene* mActiveScene;
	sf::Font mFont;

	void processEvent(const sf::Event& e);
	void update();
	void render();

};