#include "./lib/stb_leakcheck.h"
#include "game.h"

int main(int argc, char* argv[]) {
	game = new_game();
	setup();

	while (game.running) {
		process_input();
		update();
		render();
	}

	cleanup();

	return 0;
}
