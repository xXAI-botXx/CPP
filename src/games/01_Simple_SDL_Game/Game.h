
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#include <SDL3/SDL.h>

#include "Entity.h"
#include "Player.h"
#include "Wall.h"
#include "Ball.h"
#include "GraphicsHandler.h"

class Game {
public:
	// constructor
	Game();

	// init method
	bool Initialize();

	// running the game until the game is over
	void RunLoop();

	// shutdown the game
	void Shutdown();

private:
	// 1. Input Processing
	void ProcessInput();

	// 2. Update Game
	void UpdateGame();

	// 3. Generate Output
	void GenerateOutput();

	// === VARIABLES ===

	// defines whether to run the game or not
	bool shouldRun;
	bool game_pause;
	bool game_fps_delta_pause;
	const int GAME_FPS = 30;
	const double DURATION_GAME_FRAME = 1.0 / static_cast<double>(GAME_FPS);    // every frame have to wait to fill this

	int WINDOW_WIDTH = 1024;
	int WINDOW_HEIGHT = 768;
	std::vector<int> WINDOW_TOP_LEFT = { 100, 100 };
	GraphicsHandler* graphics_handler;

	std::string name;

	std::vector<Entity*> walls;
	Player* player;
	Ball* ball;

	std::vector<Entity*> all_entities;

	int GOAL_GRAPHICS_FPS = 60;
	bool use_highest_graphics_fps;
};


#endif // GAME_H







