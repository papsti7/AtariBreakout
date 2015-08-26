#include "Application.h"

Application::~Application()
{
	if(mActiveScene)
		delete mActiveScene;
}

void Application::setActiveScene(Scene* ptr)
{
	if (mActiveScene)
		delete mActiveScene;
	mActiveScene = ptr;
}

void Application::run()
{
	setActiveScene(new IntroScene(*this));
	
	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			processEvents(event);
		}
		update();
		render();
	}
}