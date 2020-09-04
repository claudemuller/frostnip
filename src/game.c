#include "game.h"
#include "asset_manager.h"
#include "entity_manager.h"
#include "display.h"
#include "constants.h"

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
			.window_width = WINDOW_WIDTH,
			.window_height = WINDOW_HEIGHT,
			.flags = SDL_WINDOW_BORDERLESS, // | SDL_WINDOW_FULLSCREEN_DESKTOP
			.last_frame_time = 0,
			.waited_for = 0,

			.setup = game_setup,
			.process_input = game_process_input,
			.update = game_update,
			.render = game_render,
			.get_fps = game_get_fps,
			.cleanup = game_cleanup
	};
}

void game_setup(void) {
	init_window(&game);

	// Add entities.
	SDL_Rect rect = {
			.x = 100,
			.y = 100,
			.w = 200,
			.h = 200,
	};
	game.entity_manager.add(rect);
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
	game.waited_for = SDL_GetTicks();
	// Waste time/sleep until the frame target time is reached.
	// While A hasn't passed B i.e. the time now hasn't passed the last frame + frame target time.
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), game.last_frame_time + FRAME_TARGET_TIME));
	game.last_frame_time = SDL_GetTicks();
	if (DEBUG) {
		printf("FPS: %d\n", game.get_fps());
	}

	game.entity_manager.update();
}

void game_render(void) {
	// Set colour.
	SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
	// Clear renderer.
	SDL_RenderClear(game.renderer);

	// Renderer entities.
	game.entity_manager.render();

	// Swap backbuffer.
	SDL_RenderPresent(game.renderer);
}

int game_get_fps(void) {
	return game.last_frame_time - game.waited_for;
}

void game_cleanup(void) {
	SDL_DestroyWindow(game.window);
	SDL_DestroyRenderer(game.renderer);
	SDL_Quit();
}
