#include <SDL2/SDL.h>
#include "display.h"

bool init_window() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "An error occurred: %s\n", SDL_GetError());
		return false;
	}

//	if (TTF_Init() != 0) {
//		fprintf(stderr, "Error intialising SDL TTF: %s\n", SDL_GetError());
//		return false;
//	}

	// Set width and height to full screen resolution.
//	SDL_DisplayMode display_mode;
//	SDL_GetCurrentDisplayMode(0, &display_mode);
//	game.window_width = display_mode.w;
//	game.window_height = display_mode.h;

	// Create SDL window.
	game.window = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			game.window_width,
			game.window_height,
			game.flags
	);
	if (!game.window) {
		fprintf(stderr, "An error occurred creating SDL window: %s\n", SDL_GetError());
		return false;
	}

	// Create SDL renderer.
	game.renderer = SDL_CreateRenderer(game.window, -1, 0);
	if (!game.renderer) {
		fprintf(stderr, "An error occurred creating SDL renderer: %s\n", SDL_GetError());
		return false;
	}

	return true;
}