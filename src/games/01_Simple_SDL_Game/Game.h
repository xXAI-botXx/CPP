
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL3/SDL.h>
#include "Entity.h"
#include "Player.h"
#include "Wall.h"
#include "Ball.h"

class Game{
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
	// SDL Window Creation
	SDL_Window* window;

	// SDL renderer (graphics drawer)
	SDL_Renderer* renderer;

	// defines whether to run the game or not
	bool shouldRun;
	bool game_fps_delta_pause;
	bool graphic_fps_delta_pause;
	bool USE_HIGHEST_GRAPHIC_FPS = false;
	const int GAME_FPS = 30;
	const double DURATION_GAME_FRAME = 1.0/static_cast<double>(GAME_FPS);    // every frame have to wait to fill this
	const int GOAL_GRAPHIC_FPS = 60;
	const double DURATION_GRAPHIC_FRAME = 1.0/static_cast<double>(GOAL_GRAPHIC_FPS);

	int WINDOW_WIDTH = 1024;
	int WINDOW_HEIGHT = 768;
	std::vector<int> WINDOW_TOP_LEFT = {100, 100};

	const char* name;

	std::vector<Entity*> walls;
	Player* player;
	Ball* ball;
};


#endif // GAME_H






