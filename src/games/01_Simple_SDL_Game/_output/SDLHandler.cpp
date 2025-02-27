#include <string>
#include <vector>

#include <SDL3/SDL.h>

#include "Entity.h"
#include "GraphicsData.h"
#include "Rectangle.h"
#include "Sprite.h"
#include "GraphicsHandler.h"
#include "SDLHandler.h"

SDLHandler::SDLHandler(std::vector<Entity*>& entities, int FPS, std::string name, int width, int height, bool use_highest_fps)
			: GraphicsHandler(entities, FPS, name, width, height, use_highest_fps){
	window = nullptr;
	renderer = nullptr;
}

bool SDLHandler::init(int window_top_left_x, int window_top_left_y) {
	// init Video subsystem
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult >= 0){
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
	} else{
		SDL_Log("Unable to init SDL: %s", SDL_GetError());
		return false;
	}
}

void SDLHandler::render(){
	// 1. Clear Back Buffer          R  G  B     a
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	// 2. Draw the game scene
	for (Entity* e : this->entities) {
		GraphicsData* data = e->get_graphic_data();
		if (!data) continue;

		// Check Type
		if (Rectangle* rect = dynamic_cast<Rectangle*>(data)) {
			// set color
			std::vector<int> rgb_color = this->color_scaling();
			SDL_SetRenderDrawColor(renderer, rgb_color.at(0), rgb_color.at(1), rgb_color.at(2), 255);

			// set position
			SDL_FRect rect = SDL_FRect{
				static_cast<float>(get_abs_x_left_corner()),
				static_cast<float>(get_abs_y_left_corner()),
				// static_cast<float>(x_pos*window_width + (width*0.5)*window_width),
				// static_cast<float>(y_pos*window_height + (height*0.5)*window_height)
				static_cast<float>(get_abs_width()),
				static_cast<float>(get_abs_height())
			};

			// render
			SDL_RenderFillRect(renderer, &rect);
		}
		else if (Sprite* circ = dynamic_cast<Sprite*>(data)) {
			// FIXME
		}
	}

	// 3. Swap back buffer and front buffer
	SDL_RenderPresent(renderer);
}






