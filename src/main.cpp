#include "Application.h"

#include "IntroScene.h"

int main()
{
    Application app;
    app.setActiveScene(new IntroScene(app));
    
    try
    {   
	    app.run();
    } catch(std::exception& e)
    {
        std::cout << e.what << std::endl;
        return -1;
    }
	return 0
}