#include "Application.h"
#include "Scene.h"

Application::~Application()
{
	if(mActiveScene)
		delete mActiveScene;
}

Application::Application() : mActiveScene(nullptr), mWindow(sf::VideoMode(800,600), "Atari Breakout"), mHighscore(0)
{
	mWindow.setVerticalSyncEnabled(true);
	mFont.loadFromFile("D:/Programmieren/AtariBreakout/AtariBreakout/data/VideoPhreak.ttf");
}

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
			processEvent(event);
		}
		update();
		render();
	}
}

void Application::processEvent(const sf::Event& e)
{
	if (e.type == sf::Event::Closed)
		mWindow.close();

	if (mActiveScene)
		mActiveScene->processEvent(e);
}

void Application::update()
{
	if (mActiveScene)
		mActiveScene->update();
}

void Application::render()
{
	mWindow.clear(sf::Color(46, 46, 46));

	if (mActiveScene)
		mActiveScene->render();

	mWindow.display();
}