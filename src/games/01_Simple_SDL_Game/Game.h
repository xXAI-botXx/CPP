
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SDL3/SDL.h>

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

	int WINDOW_WIDTH = 1024;
	int WINDOW_HEIGHT = 768;
	std::vector<int> WINDOW_TOP_LEFT = {100, 100};

	const char* name;
};


#endif // GAME_H






