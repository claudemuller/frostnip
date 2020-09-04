#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "asset_manager.h"
#include "entity_manager.h"

typedef struct {
	entity_manager_t entity_manager;
	asset_manager_t asset_manager;
	SDL_Renderer* renderer;
	SDL_Window* window;
	bool running;
	int window_width;
	int window_height;
	uint32_t flags;
	bool debug;

	void (* setup)(void);
	void (* process_input)(void);
	void (* update)(void);
	void (* render)(void);
	void (* cleanup)(void);
} game_t;

extern game_t game;

game_t new_game(void);
void game_setup(void);
void game_process_input(void);
void game_update(void);
void game_render(void);
void game_cleanup(void);

#endif //PLATFORMER_GAME_H
