#include "game.h"

int main(int argc, char* argv[]) {
	game = new_game();
	game.setup();

	while (game.running) {
		game.process_input();
		game.update();
		game.render();
	}

	game.cleanup();

	return 0;
}
