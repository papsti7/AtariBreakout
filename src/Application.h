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

	~Application();

private:

	sf::RenderWindow mWindow;
	Scene* mActiveScene;

	void processEvent(const sf::Event& e);
	void update();
	void render();

};