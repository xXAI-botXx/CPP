


#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

#include "Entity.h"
#include "Player.h"
#include "Wall.h"
#include "Ball.h"

#include "Game.h"


// constructor
Game::Game(){
	window = nullptr;
	shouldRun = true;
	WINDOW_WIDTH = 1024;
	WINDOW_HEIGHT = 768;
	WINDOW_TOP_LEFT = {100, 100};
	name = "Simple SDL Game >>Pong<<";

	double wall_x_pos = 0.04;
	double wall_y_pos;
	for(int column=0; column<20; ++column){
		wall_x_pos += 0.04;
		wall_y_pos = 0.01;
		for(int row=0; row<10; ++row){
			wall_y_pos += 0.01;
			walls.push_back(new Wall(wall_x_pos, wall_y_pos));
		}
	}
	player = new Player();
	ball = new Ball();
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

	delete player;
	delete ball;
	for(auto wall:walls){
		delete wall;
	}
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

	if(state[SDL_SCANCODE_A] && state[SDL_SCANCODE_D]){
		player->set_movement(MOVE::NOTHING);
	} else if(state[SDL_SCANCODE_A]){
		player->set_movement(MOVE::LEFT);
	} else if(state[SDL_SCANCODE_D]){
		player->set_movement(MOVE::RIGHT);
	}



}

// 2. Update Game
void Game::UpdateGame(){
	// update window sizes
	player->update_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
	ball->update_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
	for(Entity* entity:walls){
		entity->update_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
	}

	// input processing
	player->update();
	player->set_movement(MOVE::NOTHING);

	// update ball
	ball->update();

	// update walls
	for(auto wall:walls){
			wall->update();
	}

	// check for collision with bottom
	if(ball->is_on_bottom()){
		this->Shutdown();
	}

	// check for collision with player
	if(player->collide_with_other(ball)){
		std::vector<double> pos_info = player->get_pos_info();
		double player_width = pos_info.at(2);
		double player_height = pos_info.at(3);
		double player_x_pos = pos_info.at(0)-player_width/2;
		double player_y_pos = pos_info.at(1)-player_width/2;
		double player_x_pos_2 = player_x_pos+player_width;
		double player_y_pos_2 = player_y_pos+player_height;
		Vector2D normal = Vector2D(-(player_y_pos_2-player_y_pos), (player_x_pos_2-player_x_pos));    // in stack
		ball->bounce(normal);
	} else {
		// check for collision with wall
		for (size_t i = 0; i < walls.size(); ++i) {
			if(ball->collide_with_other(walls.at(i))){
				std::vector<double> pos_info = walls.at(i)->get_pos_info();
				double wall_width = pos_info.at(2);
				double wall_height = pos_info.at(3);
				double wall_x_pos = pos_info.at(0)-wall_width/2;
				double wall_y_pos = pos_info.at(1)-wall_width/2;
				double wall_x_pos_2 = wall_x_pos+wall_width;
				double wall_y_pos_2 = wall_y_pos+wall_height;
				Vector2D normal = Vector2D((wall_y_pos_2-wall_y_pos), -(wall_x_pos_2-wall_x_pos));
				ball->bounce(normal);
				// destroy and remove the wall from the vector
				delete walls.at(i);
				walls.erase(walls.begin() + i);
				break;
			}
		}

		// check for collision with side walls
		std::vector<double> pos_info = ball->get_pos_info();
		double ball_width = pos_info.at(2);
		double ball_height = pos_info.at(3);
		double ball_x_pos = pos_info.at(0)-ball_width/2;
		double ball_x_pos_2 = ball_x_pos+ball_width;

		if(ball_x_pos <= 0.0){
			Vector2D normal = Vector2D(1.0, 0.0);
			ball->bounce(normal);
		} else if(ball_x_pos_2 >= WINDOW_WIDTH){
			Vector2D normal = Vector2D(-1.0, 0.0);
			ball->bounce(normal);
		}

	}
}

// 3. Generate Output
void Game::GenerateOutput(){
	// 1. Clear Back Buffer          R  G  B     a
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	// 2. Draw the game scene
	player->draw(renderer);
	ball->draw(renderer);
	for(auto wall:walls){
			wall->draw(renderer);
	}

	// 3. Swap back buffer and front buffer
	SDL_RenderPresent(renderer);
}












