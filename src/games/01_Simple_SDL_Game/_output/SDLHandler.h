#pragma once

#include <vector>
#include <string>

#include <SDL3/SDL.h>

#include "Entity.h"
#include "GraphicsHandler.h"

class SDLHandler:public GraphicsHandler{
public:
	SDLHandler(std::vector<Entity*>& entities, int FPS, std::string name, int width, int height, bool use_highest_fps);
	~SDLHandler();

	void render();
	bool init(int window_top_left_x, int window_top_left_y);
protected:
	// SDL Window Creation
	SDL_Window* window;

	// SDL renderer (graphics drawer)
	SDL_Renderer* renderer;
};





