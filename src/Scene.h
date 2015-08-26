#pragma once
#include "Application.h"
#include "SFML\Window.hpp"

class Scene
{
public:
	Scene(Application& app) : mApp(app) {  }

	

	virtual void processEvent(const sf::Event& e) = 0;
	virtual void update() = 0;
	virtual void render() = 0;



	virtual ~Scene()
	{}

protected:
	Application& getApp() { return mApp; }

private:
	Application& mApp;
};
