#include "Game.h"

int main(int argc, char** argv) {
	Game* game = new Game();
	bool success = game->initialize();

	if (success) {
		game->run_loop();
	}

	game->shutdown();
	delete game;

	return 0;
}


