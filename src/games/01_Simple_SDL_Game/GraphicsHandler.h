#pragma once

#include <vector>
#include <atomic>
#include <chrono>
#include <string>

#include "Entity.h"

class GraphicsHandler {
public:
	GraphicsHandler(std::vector<Entity*>& entities, int FPS, std::string name, int width, int height, bool use_highest_fps);
	virtual ~GraphicsHandler();
	// all in absolute values -> so that the specific game can have rel or abs system and the render still works
	// only one responsibility!
	virtual void render() = 0;
	virtual bool init(int window_top_left_x, int window_top_left_y) = 0;
	virtual std::vector<int> get_window_size() = 0;

	void pause_rendering(bool should_pause_rendering);
	void set_rendering(bool should_render);
	void change_highest_fps_rate(bool use_highest_fps);
	void change_FPS(int FPS);
	void render_loop();    // maybe define renderloop here and use the abstract method, so every subclass can decide how to render
	void update_window_size(int width, int height);
	// void update_render_entities(std::vector<Entity*> entities);    // -> not neede, we have the real exact same vector, changes will also apply on this entity vector

protected:
	std::vector<Entity*> entities;
	int width, height;
	std::string name;

	std::atomic<bool> render_pause;
	std::atomic<bool> should_render;

	bool USE_HIGHEST_GRAPHIC_FPS = false;
	int GOAL_GRAPHIC_FPS = 60;
	double DURATION_GRAPHIC_FRAME = 1.0 / static_cast<double>(GOAL_GRAPHIC_FPS);

	std::chrono::time_point<std::chrono::high_resolution_clock> start_graphics_frame, end_graphics_frame;
	double seconds_g_frame, delta_g_time;
	std::chrono::duration<double> duration_g_frame;
	bool graphic_fps_delta_pause = false;


};










