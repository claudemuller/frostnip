#include "game.h"
#include "asset_manager.h"
#include "entity_manager.h"
#include "display.h"
#include "constants.h"

game_t game;

game_t new_game() {
	entity_manager_t em = new_entity_manager();
	asset_manager_t am = new_asset_manager(&em);

	return (game_t){
			.entity_manager = em,
			.asset_manager = am,
			.renderer = NULL,
			.window = NULL,
			.running = true,
			.window_width = WINDOW_WIDTH,
			.window_height = WINDOW_HEIGHT,
			.flags = SDL_WINDOW_BORDERLESS, // | SDL_WINDOW_FULLSCREEN_DESKTOP
			.last_frame_time = 0,
			.waited_for = 0
	};
}

void setup(void) {
	init_window();

	// Add entities.
	SDL_Rect rect = {
			.x = 100,
			.y = 100,
			.w = 200,
			.h = 200,
	};
	game.entity_manager.add(rect);
}

void process_input(void) {
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

void update(void) {
	game.waited_for = SDL_GetTicks();
	// Waste time/sleep until the frame target time is reached.
	// While A hasn't passed B i.e. the time now hasn't passed the last frame + frame target time.
	// naive implementation (doesn't yield to OS)
	//while (!SDL_TICKS_PASSED(SDL_GetTicks(), game.last_frame_time + FRAME_TARGET_TIME));

	// Sleep the execution until the target time in milliseconds is reached.
	int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - game.last_frame_time);
	// Only call delay if processing is too fast in the current frame.
	if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
		SDL_Delay(time_to_wait);
	}
	if (DEBUG) {
		printf("FPS: %d\n", get_fps());
	}
	// Difference in ticks from last frame converted to seconds.
	// delta_time becomes a factor that changes "..moves pixels per frame" to "..moves pixels per second"
	float delta_time = (float)(SDL_GetTicks() - game.last_frame_time) / 1000.0f;
	// Clamp deltaTime to a maximum value
	delta_time = delta_time > 0.05f ? 0.05f : delta_time;
	// Sets the new ticks fo the current frame to be used in the next pass
	game.last_frame_time = SDL_GetTicks();

	game.entity_manager.update(delta_time);
}

void render(void) {
	// Set colour.
	SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, 255);
	// Clear renderer.
	SDL_RenderClear(game.renderer);

	// Renderer entities.
	game.entity_manager.render();

	// Swap backbuffer.
	SDL_RenderPresent(game.renderer);
}

int get_fps(void) {
	return game.last_frame_time - game.waited_for;
}

void cleanup(void) {
	SDL_DestroyWindow(game.window);
	SDL_DestroyRenderer(game.renderer);
	SDL_Quit();
}
