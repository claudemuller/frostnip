#include "game.h"
#include "asset_manager.h"
#include "entity_manager.h"
#include "display.h"

game_t game;

game_t new_game() {
	entity_manager_t em = new_entity_manager();
	asset_manager_t am = new_asset_manager(&em);

	return (game_t) {
			.entity_manager = em,
			.asset_manager = am,
			.renderer = NULL,
			.window = NULL,
			.running = true,
			.window_width = 800,
			.window_height = 600,
			.flags = SDL_WINDOW_BORDERLESS, // | SDL_WINDOW_FULLSCREEN_DESKTOP
			.debug = true,

			.setup = game_setup,
			.process_input = game_process_input,
			.update = game_update,
			.render = game_render,
			.cleanup = game_cleanup
	};
}

void game_setup(void) {
	init_window(&game);
}

void game_process_input(void) {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			game.running = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				game.running = false;
			}
			break;
		default:
			break;
	}
}

void game_update(void) {
	game.entity_manager.update();
}

void game_render(void) {
	// Set colour.
	SDL_SetRenderDrawColor(game.renderer, 21, 21, 21, 255);
	// Clear renderer.
	SDL_RenderClear(game.renderer);

	// Renderer entities.
	game.entity_manager.render();

	// Swap back buffer
	SDL_RenderPresent(game.renderer);
}

void game_cleanup(void) {
	SDL_DestroyWindow(game.window);
	SDL_DestroyRenderer(game.renderer);
	SDL_Quit();
}
