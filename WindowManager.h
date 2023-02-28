#pragma once

#include <SDL.h>
#include <SDL_Vulkan.h>
#include <memory>

class WindowManager {
public:
	
	WindowManager(int width, int height);
	void runWindowTest();
	void runTriangleTest();

private:
	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
	std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface;

	void initWindow();
	void mainLoop();
};