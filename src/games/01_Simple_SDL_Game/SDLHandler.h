#pragma once

#include <vector>
#include <string>

#include <SDL3/SDL.h>

#include "GraphicsHandler.h"
#include "Entity.h"
#include "Game.h"

class SDLHandler :public GraphicsHandler {
public:
	SDLHandler(Game* game, int FPS, std::string name, int width, int height, bool use_highest_fps);
	~SDLHandler();

	void render();
	bool init(int window_top_left_x, int window_top_left_y);
	std::vector<int> get_window_size();
protected:
	// SDL Window Creation
	SDL_Window* window;

	// SDL renderer (graphics drawer)
	SDL_Renderer* renderer;
};





