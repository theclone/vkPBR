// vkPBR.cpp : Defines the entry point for the application.
//

#include "vkPBR.h"
#include <SDL.h>
#include <SDL_Vulkan.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <memory>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	std::cout << "Hello CMake." << std::endl;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "[SDL] Init Error: " << SDL_GetError() << std::endl;
	}

	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window(SDL_CreateWindow(
		"vkPBR",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_VULKAN
	), SDL_DestroyWindow);

	if (window == nullptr)
	{
		std::cout << "[SDL] Window creation error: " << SDL_GetError() << std::endl;
	}

	std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface(SDL_GetWindowSurface(window.get()), SDL_FreeSurface);

	SDL_FillRect(surface.get(), nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window.get());

	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

	SDL_Quit();

	return 0;
}
