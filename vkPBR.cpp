// vkPBR.cpp : Defines the entry point for the application.
//

#include "vkPBR.h"
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	std::cout << "Hello CMake." << std::endl;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "[SDL] Init Error: " << SDL_GetError() << std::endl;
	}

	{
		WindowManager window(SCREEN_WIDTH, SCREEN_HEIGHT);
		window.runWindowTest();
	}

	SDL_Quit();

	return 0;
}
