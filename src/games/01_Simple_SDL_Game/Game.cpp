


#include <iostream>
#include <chrono>    // for time stopping
#include <thread>
#include <algorithm>
#include <vector>

#include "GraphicsHandler.h"
#include "SDLHandler.h"
#include "Event.h"
#include "InputProcessor.h"
#include "SDLInputProcessor.h"

#include "Entity.h"
#include "Player.h"
#include "Wall.h"
#include "Ball.h"

#include "Game.h"


// constructor
Game::Game() {
	should_run = true;
	game_pause = false;
	game_fps_delta_pause = false;
	WINDOW_WIDTH = 1024;
	WINDOW_HEIGHT = 768;
	WINDOW_TOP_LEFT = { 100, 100 };
	name = "Simple SDL Game >>Pong<<";

	double side_padding = 0.2;
	double column_padding = 0.005;
	int columns = 10;
	double column_step_size = (1.0 - side_padding) / (columns + columns * column_padding);
	double width = column_step_size - column_padding;

	double row_padding = 0.005;
	int rows = 5;
	double row_step_size = 0.2 / (rows + rows * row_padding);
	double height = row_step_size - row_padding;

	std::cout << "width: " << width << ", height: " << height << std::endl;

	double wall_x_pos = side_padding/2;
	double wall_y_pos;
	for (int column = 0; column < columns; ++column) {
		wall_x_pos += column_step_size;
		wall_y_pos = 0.05;
		for (int row = 0; row < rows; ++row) {
			wall_y_pos += row_step_size;
			walls.push_back(new Wall(wall_x_pos, wall_y_pos, width, height));
		}
	}
	player = new Player();
	ball = new Ball();

	get_render_entities();

	GOAL_GRAPHICS_FPS = 60;
	use_highest_graphics_fps = false;
	graphics_handler = new SDLHandler(this, GOAL_GRAPHICS_FPS, name, WINDOW_WIDTH, WINDOW_HEIGHT, use_highest_graphics_fps);
	input_processor = new SDLInputProcessor();
}

Game::~Game() {
	delete graphics_handler;

	delete player;
	delete ball;
	for (auto wall : walls) {
		delete wall;
	}

	game_pause = true;
}

// init method
bool Game::initialize() {
	return graphics_handler->init(WINDOW_TOP_LEFT.at(0), WINDOW_TOP_LEFT.at(1));
}

// running the game until the game is over
void Game::run_loop() {
	// init variables
	std::chrono::time_point<std::chrono::high_resolution_clock> start_frame, end_frame;
	double delta_time, goal_delta_time;
	delta_time = 0.0;
	std::chrono::duration<double> duration_frame;

	// start graphics thread
	std::thread graphic_handler_thread(
		[&]() { graphics_handler->render_loop(); }
	);
	// std::thread graphic_handler_thread(&GraphicsHandler::render_loop, this);
	graphic_handler_thread.detach();

	// while(this->should_run){
	while (should_run) {

		delta_time = std::min(delta_time, DELTA_TIME_LIMIT);

		// run frame
		if (!game_fps_delta_pause) {
			// stop time for delta
			start_frame = std::chrono::high_resolution_clock::now();
			process_input();
			update_game(delta_time);
			// GenerateOutput();
		}

		// add delta time, to come to Game FPS
		end_frame = std::chrono::high_resolution_clock::now();
		duration_frame = end_frame - start_frame;
		delta_time = duration_frame.count();
		goal_delta_time = static_cast<double>(DURATION_GAME_FRAME) - delta_time;

		if (goal_delta_time > 0.0) {
			// sleep
			// std::this_thread::sleep_for(std::chrono::duration<double>(delta_time));

			// wait the delta time
			while (std::chrono::high_resolution_clock::now() - end_frame < std::chrono::duration<double>(goal_delta_time)) {
				std::this_thread::yield(); // Allows other threads to run
			}
		}

		// set Game pause or not with FPS
		if (goal_delta_time > 0.0) {
			game_fps_delta_pause = true;
			// std::this_thread::sleep_for(std::chrono::duration<double>(goal_delta_time));
		}
		else {
			// reset and ready for the next frame
			game_fps_delta_pause = false;
		}
	}
	graphics_handler->set_rendering(false);
}

// shutdown the game
void Game::shutdown() {
	// delete graphics_handler;

	/*delete player;
	delete ball;
	for (auto wall : walls) {
		delete wall;
	}*/

	game_pause = true;
}



// 1. Input Processing
void Game::process_input() {
	// Event var, to store event
	Event* event = nullptr;
	std::vector<int> new_size;
	KEY esc = KEY::ESC;

	// get next event in queue
	while (input_processor->poll_event(event)) {
		if (event == nullptr)
			break;

		switch (event->type) {
		case EVENT_TYPE::QUIT:
			graphics_handler->set_rendering(false);
			should_run = false;
			break;
		case EVENT_TYPE::WINDOW_RESIZING:
			new_size = graphics_handler->get_window_size();
			WINDOW_WIDTH = new_size.at(0);
			WINDOW_HEIGHT = new_size.at(1);
			break;
		case EVENT_TYPE::PRESSED_KEY:
			std::vector<KEY> keys = event->pressed_keys;
			//for (KEY key : keys) {
			//	// ... if ...
			//}
			if (contains(keys, KEY::ESC)) {
				graphics_handler->set_rendering(false);
				should_run = false;
			}

			if (!this->game_pause) {
				if (contains(keys, KEY::D) && contains(keys, KEY::A)) {
					player->add_movement(MOVE2D::NOTHING);
				}
				else if (contains(keys, KEY::A)) {
					player->add_movement(MOVE2D::LEFT);
				}
				else if (contains(keys, KEY::D)) {
					player->add_movement(MOVE2D::RIGHT);
				}
			}

			break;
		}
	}

	// cleaning
	delete event;

}

// 2. Update Game
void Game::update_game(double delta_time) {
	// update window sizes
	player->update_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
	ball->update_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
	for (Entity* entity : walls) {
		entity->update_window_size(WINDOW_WIDTH, WINDOW_HEIGHT);
	}

	if(!game_pause){
		// input processing
		player->update(delta_time);
		player->add_movement(MOVE2D::NOTHING);

		// update ball
		ball->update(delta_time);

		// update walls
		for (auto wall : walls) {
			wall->update(delta_time);
		}

		// check for collision with bottom
		if (ball->is_on_bottom()) {
			this->shutdown();
			return;
		}

		// check for collision with player
		if (ball->collide_with_other(player)) {
			std::vector<double> pos_info = player->get_pos_info();
			double player_width = pos_info.at(2);
			double player_height = pos_info.at(3);
			double player_x_pos = pos_info.at(0) - player_width / 2;
			double player_y_pos = pos_info.at(1) - player_width / 2;
			double player_x_pos_2 = player_x_pos + player_width;
			double player_y_pos_2 = player_y_pos + player_height;
			// Vector2D normal = Vector2D((player_y_pos_2 - player_y_pos), (player_x_pos_2 - player_x_pos));    // in stack
			Vector2D normal = Vector2D(0.0, 1.0);
			ball->bounce(normal);
		}
		else {
			// check for collision with wall
			for (size_t i = 0; i < walls.size(); ++i) {
				if (ball->collide_with_other(walls.at(i))) {
					std::vector<double> pos_info = walls.at(i)->get_pos_info();
					double wall_width = pos_info.at(2);
					double wall_height = pos_info.at(3);
					double wall_x_pos = pos_info.at(0) - wall_width / 2;
					double wall_y_pos = pos_info.at(1) - wall_width / 2;
					double wall_x_pos_2 = wall_x_pos + wall_width;
					double wall_y_pos_2 = wall_y_pos + wall_height;
					Vector2D normal = Vector2D((wall_y_pos_2 - wall_y_pos), -(wall_x_pos_2 - wall_x_pos));
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
			double ball_x_pos = pos_info.at(0) - ball_width / 2;
			double ball_x_pos_2 = ball_x_pos + ball_width;
			double ball_y_pos = pos_info.at(1) - ball_height / 2;

			if (ball_x_pos <= 0.0) {
				Vector2D normal = Vector2D(1.0, 0.0);
				ball->bounce(normal);
			}
			else if (ball_x_pos_2 >= 1.0) {
				Vector2D normal = Vector2D(-1.0, 0.0);
				ball->bounce(normal);
			}
			else if (ball_y_pos <= 0.0) {
				Vector2D normal = Vector2D(0.0, -1.0);
				ball->bounce(normal);
			}
		}
	}
}

// 3. Generate Output
void Game::generate_output() {

	//	player->draw(renderer);
	//	ball->draw(renderer);
	//	for(auto wall:walls){
	//			wall->draw(renderer);
	//	}
}



std::vector<Entity*> Game::get_render_entities() {
	// refresh the all entity list
	for (Entity* e:all_entities) {
		delete e;
	}
	all_entities.clear();
	all_entities.push_back(new Player(*player));
	all_entities.push_back(new Ball(*ball));
	for (Wall* cur_wall : walls) {
		all_entities.push_back(new Wall(*cur_wall));
	}
	return all_entities;
}












