#pragma once
#include "Scene.h"
#include "SFML\Graphics.hpp"

class Application
{
public:
	Application() : mActiveScene(nullptr) {	};

	void run();

	void setActiveScene(Scene* ptr);

private:

	sf::RenderWindow mWindow;
	Scene* mActiveScene;

	void processEvents(const sf::Event& e);
	void update();
	void render();

};