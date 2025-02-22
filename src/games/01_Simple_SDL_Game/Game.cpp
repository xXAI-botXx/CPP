


#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

#include "Game.h"


// constructor
Game::Game(){
	window = nullptr;
	shouldRun = true;
	WINDOW_WIDTH = 1024;
	WINDOW_HEIGHT = 768;
	WINDOW_TOP_LEFT = {100, 100};
	name = "Simple SDL Game >>Pong<<";
}

// init method
bool Game::Initialize(){
	// init Video subsystem
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult >= 0){
		// create window
		window = SDL_CreateWindow(
				name,
				WINDOW_WIDTH,    // Width
				WINDOW_HEIGHT,    // Height
				SDL_WINDOW_RESIZABLE    // Flags -> 0 = no flags set
		);

		//check the window
		if (!window) {
			SDL_Log("FAILED to create window: %s", SDL_GetError());
			return false;
		}
		SDL_SetWindowPosition(window, WINDOW_TOP_LEFT.at(0), WINDOW_TOP_LEFT.at(1));

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

// running the game until the game is over
void Game::RunLoop(){
	// while(this->shouldRun){
	while(shouldRun){
		// this->ProcessInput();
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

// shutdown the game
void Game::Shutdown(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}



// 1. Input Processing
void Game::ProcessInput(){
	// create var to save one event
	SDL_Event event;
	// get next event in queue
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_EVENT_QUIT:
				shouldRun = false;
				break;
			case SDL_EVENT_WINDOW_RESIZED:
				SDL_GetWindowSize(window, &WINDOW_WIDTH, &WINDOW_HEIGHT);
				break;
		}
	}

	// get keyboard inputs
	const bool* state = SDL_GetKeyboardState(nullptr);
	if(state[SDL_SCANCODE_ESCAPE]){
		shouldRun = false;
	}

}

// 2. Update Game
void Game::UpdateGame(){

}

// 3. Generate Output
void Game::GenerateOutput(){
	// 1. Clear Back Buffer          R  G  B     a
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	// 2. Draw the game scene
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_FRect rect = {
		0, 0,
		static_cast<int>(0.2*WINDOW_WIDTH),
		static_cast<int>(0.05*WINDOW_HEIGHT)
	};
	const SDL_FRect* rect_p = &rect;

	SDL_RenderFillRect(renderer, rect_p);

	// 3. Swap back buffer and front buffer
	SDL_RenderPresent(renderer);
}












