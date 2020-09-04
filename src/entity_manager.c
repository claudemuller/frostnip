#include <stdio.h>
#include <SDL2/SDL.h>
#include "entity_manager.h"
#include "game.h"

void entity_manager_update(void) {
	if (game.debug) {
		printf("updating entities...\n");
	}
}

void entity_manager_render(void) {
	if (game.debug) {
		printf("rendering entities...\n");
	}

	SDL_Rect rect = {
			.x = 100,
			.y = 100,
			.w = 200,
			.h = 200,
	};
	SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(game.renderer, &rect);
}

entity_manager_t new_entity_manager(void) {
	return (entity_manager_t) {
		.update = entity_manager_update,
		.render = entity_manager_render

	};
}

