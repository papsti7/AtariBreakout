#include "Application.h"

#include "IntroScene.h"

#include <iostream>

int main()
{
    Application app;
    app.setActiveScene(new IntroScene(app));
	app.run();
    /*try
    {   
	    app.run();
    } catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }*/
	return 0;
}