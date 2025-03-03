#include "GraphicsHandler.h"

#include <atomic>
#include <chrono>
#include <thread>
#include <string>

#include "GraphicsData.h"
#include "Rectangle.h"
#include "Sprite.h"
#include "Entity.h"
#include "Game.h"

GraphicsHandler::GraphicsHandler(Game* game, int FPS, std::string name, int width, int height, bool use_highest_fps)
	: game(game), GOAL_GRAPHIC_FPS(FPS), name(name),   // Initlist
	USE_HIGHEST_GRAPHIC_FPS(use_highest_fps),
	width(width), height(height) {

	render_pause.store(false);
	should_render.store(true);
	start_graphics_frame = std::chrono::high_resolution_clock::now();

	seconds_g_frame = 0.0;
	delta_g_time = 0.0;
	duration_g_frame = std::chrono::duration < double>(0.0);
}

GraphicsHandler::~GraphicsHandler() {

}

void GraphicsHandler::render_loop() {

	while (should_render.load()) {
		if (!render_pause.load() && (!graphic_fps_delta_pause || USE_HIGHEST_GRAPHIC_FPS)) {
			start_graphics_frame = std::chrono::high_resolution_clock::now();

			// Update Entities
			this->entities = this->game->get_render_entities();
			
			// rendering
			render();
		}

		// calculate waiting/delta time
		end_graphics_frame = std::chrono::high_resolution_clock::now();
		duration_g_frame = end_graphics_frame - start_graphics_frame;
		seconds_g_frame = duration_g_frame.count();
		delta_g_time = static_cast<double>(DURATION_GRAPHIC_FRAME) - seconds_g_frame;

		// apply delta time
		if (delta_g_time > 0.0) {
			// sleep
			// std::this_thread::sleep_for(std::chrono::duration<double>(delta_time));

			// wait the delta time
			while (std::chrono::high_resolution_clock::now() - end_graphics_frame < std::chrono::duration<double>(delta_g_time)) {
				std::this_thread::yield(); // Allows other threads to run
			}
		}

		// post delta check
		end_graphics_frame = std::chrono::high_resolution_clock::now();
		duration_g_frame = end_graphics_frame - start_graphics_frame;
		seconds_g_frame = duration_g_frame.count();
		delta_g_time = static_cast<double>(DURATION_GRAPHIC_FRAME) - seconds_g_frame;
		// set Graphics pause or not -> with FPS
		if (delta_g_time > 0.0) {
			graphic_fps_delta_pause = true;
		}
		else {
			// reset and ready for the next graphics frame
			graphic_fps_delta_pause = false;
		}
	}

}

void GraphicsHandler::pause_rendering(bool should_pause_rendering) {
	render_pause.store(should_pause_rendering);
}

void GraphicsHandler::set_rendering(bool should_render) {
	this->should_render.store(should_render);
}

void GraphicsHandler::change_highest_fps_rate(bool use_highest_fps) {
	USE_HIGHEST_GRAPHIC_FPS = use_highest_fps;
}

void GraphicsHandler::change_FPS(int FPS) {
	if (FPS > 0) {    // && !USE_HIGHEST_GRAPHIC_FPS
		GOAL_GRAPHIC_FPS = FPS;
		DURATION_GRAPHIC_FRAME = 1.0 / static_cast<double>(GOAL_GRAPHIC_FPS);
	}
}

void GraphicsHandler::update_window_size(int width, int height) {
	this->width = width;
	this->height = height;
}






