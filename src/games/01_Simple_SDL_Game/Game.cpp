


#include <iostream>
#include <SDL3/SDL.h>



class Game{
public:
	// constructor
	Game(){
		window = nullptr;
		shouldRun = true;
	}

	// init method
	bool Initialize(){
		// init Video subsystem
		int sdlResult = SDL_Init(SDL_INIT_VIDEO);
		if (sdlResult == 0){
			// create window
			// FIXME ...

			return true;
		} else{
			SDL_Log("Unable to init SDL: %s", SDL_GetError());
			return false;
		}
	}

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

	// SDL Window Creation
	SDL_Window* window;

	// defines whether to run the game or not
	bool shouldRun;
};












