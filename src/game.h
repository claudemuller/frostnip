#ifndef FROSTBIT_GAME_H
#define FROSTBIT_GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "asset_manager.h"
#include "entity_manager.h"

typedef struct {
	SDL_Renderer* renderer;
	SDL_Window* window;
	bool running;
	int window_width;
	int window_height;
	uint32_t flags;
	bool debug;
	int last_frame_time;
	int waited_for;
	asset_manager_t asset_manager;
	entity_manager_t entity_manager;
} game_t;

extern game_t game;

game_t new_game(void);
void setup(void);
void process_input(void);
void update(void);
void render(void);
int get_fps(void);
void cleanup(void);

#endif //FROSTBIT_GAME_H
