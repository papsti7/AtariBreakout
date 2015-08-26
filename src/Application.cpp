#include "Application.h"

void Application::setActiveScene(Scene* ptr)
{
	if (mActiveScene)
		delete mActiveScene;
	mActiveScene = ptr;
}

void Application::run()
{
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