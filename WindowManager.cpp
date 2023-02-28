#include "WindowManager.h"
#include <iostream>

WindowManager::WindowManager(int width, int height) :
	window(SDL_CreateWindow(
		"vkPBR",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_VULKAN
	), SDL_DestroyWindow),
	surface(SDL_GetWindowSurface(window.get()), SDL_FreeSurface)
{

	if (window == nullptr)
	{
		std::cout << "[SDL] Window creation error: " << SDL_GetError() << std::endl;
	}
}

void WindowManager::runWindowTest()
{
	SDL_FillRect(surface.get(), nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window.get());
	mainLoop();
}

void WindowManager::runTriangleTest()
{
	VkInstance instance;
}

void WindowManager::mainLoop()
{
	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
}
