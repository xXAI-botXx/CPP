
#pragma once

#include "GraphicsHandler.h"
#include "Entity.h"
#include "Player.h"
#include "Wall.h"
#include "Ball.h"
#include "InputProcessor.h"

#include <vector>
#include <string>

#include <SDL3/SDL.h>

class GraphicsHandler;

class Game {
public:
	// constructor
	Game();

	// init method
	bool initialize();

	// running the game until the game is over
	void run_loop();

	// shutdown the game
	void shutdown();

	std::vector<Entity*> get_render_entities();

private:
	// 1. Input Processing
	void process_input();

	// 2. Update Game
	void update_game();

	// 3. Generate Output
	void generate_output();

	// === VARIABLES ===

	// defines whether to run the game or not
	bool should_run;
	bool game_pause;
	bool game_fps_delta_pause;
	const int GAME_FPS = 30;
	const double DURATION_GAME_FRAME = 1.0 / static_cast<double>(GAME_FPS);    // every frame have to wait to fill this

	int WINDOW_WIDTH = 1024;
	int WINDOW_HEIGHT = 768;
	std::vector<int> WINDOW_TOP_LEFT = { 100, 100 };
	GraphicsHandler* graphics_handler;

	InputProcessor* input_processor;

	std::string name;

	std::vector<Wall*> walls;
	Player* player;
	Ball* ball;

	std::vector<Entity*> all_entities;

	int GOAL_GRAPHICS_FPS = 60;
	bool use_highest_graphics_fps;
};









