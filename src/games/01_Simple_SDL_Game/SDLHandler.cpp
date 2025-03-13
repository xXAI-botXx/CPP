#include <string>
#include <vector>

#include <SDL3/SDL.h>

#include "Entity.h"
#include "GraphicsData.h"
#include "Rectangle.h"
#include "Sprite.h"
#include "GraphicsHandler.h"
#include "Game.h"
#include "SDLHandler.h"

SDLHandler::SDLHandler(Game* game, int FPS, std::string name, int width, int height, bool use_highest_fps)
	: GraphicsHandler(game, FPS, name, width, height, use_highest_fps) {
	window = nullptr;
	renderer = nullptr;
}

SDLHandler::~SDLHandler() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool SDLHandler::init(int window_top_left_x, int window_top_left_y) {
	// init Video subsystem
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult >= 0) {
		// create window
		window = SDL_CreateWindow(
			name.c_str(),
			width,    // Width
			height,    // Height
			SDL_WINDOW_RESIZABLE    // Flags -> 0 = no flags set
		);

		//check the window
		if (!window) {
			SDL_Log("FAILED to create window: %s", SDL_GetError());
			return false;
		}
		SDL_SetWindowPosition(window, window_top_left_x, window_top_left_y);

		// create renderer
		renderer = SDL_CreateRenderer(window, nullptr);

		//check the renderer
		if (!renderer) {
			SDL_Log("FAILED to create renderer: %s", SDL_GetError());
			return false;
		}

		return true;
	}
	else {
		SDL_Log("Unable to init SDL: %s", SDL_GetError());
		return false;
	}
}

void SDLHandler::render() {
	// 1. Clear Back Buffer          R  G  B     a
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	// 2. Draw the game scene
	for (Entity* e : this->entities) {
		std::vector<GraphicsData*> all_data = e->get_graphic_data();

		for (GraphicsData* data : all_data) {
			if (!data) continue;

			// Check Type
			if (Rectangle* rect = dynamic_cast<Rectangle*>(data)) {
				// extract data from data class


				// set color
				SDL_SetRenderDrawColor(renderer, rect->fill_color.at(0), rect->fill_color.at(1), rect->fill_color.at(2), 255);

				// set position
				double x_left_corner = rect->bounding_box.min_x;
				double y_left_corner = rect->bounding_box.min_y;
				double width = rect->bounding_box.max_x - rect->bounding_box.min_x;
				double height = rect->bounding_box.max_y - rect->bounding_box.min_y;
				SDL_FRect draw_rect = SDL_FRect{
					static_cast<float>(x_left_corner),
					static_cast<float>(y_left_corner),
					// static_cast<float>(x_pos*window_width + (width*0.5)*window_width),
					// static_cast<float>(y_pos*window_height + (height*0.5)*window_height)
					static_cast<float>(width),
					static_cast<float>(height)
				};

				// render
				SDL_RenderFillRect(renderer, &draw_rect);
			}
			else if (Sprite* circ = dynamic_cast<Sprite*>(data)) {
				// FIXME
			}

			// cleanup
			delete data;
		}
	}

	// 3. Swap back buffer and front buffer
	SDL_RenderPresent(renderer);
}


std::vector<int> SDLHandler::get_window_size() {
	int window_width, window_height;
	SDL_GetWindowSize(window, &window_width, &window_height);
	this->width = window_width;
	this->height = window_height;
	return std::vector<int>{window_width, window_height};
}






