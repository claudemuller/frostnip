#include <stdio.h>
#include "entity_manager.h"
#include "constants.h"
#include "game.h"

void entity_manager_update(float delta_time) {
	if (DEBUG) {
		printf("updating entities...\n");
	}

	for (int i = 0; i < 1; i++) {
		SDL_Rect *rect = &game.entity_manager.entities[i];
		rect->x += 100 * delta_time;
		rect->y += 100 * delta_time;
	}
}

void entity_manager_render(void) {
	if (DEBUG) {
		printf("rendering entities...\n");
	}

	SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 255);
	for (int i = 0; i < 1; i++) {
		SDL_Rect rect = game.entity_manager.entities[i];
		if (DEBUG) {
			printf("entity: x - %d, y - %d, w - %d, h - %d\n", rect.x, rect.y, rect.w, rect.h);
		}
		SDL_RenderFillRect(game.renderer, &rect);
	}
}

void entity_manager_add(SDL_Rect entity) {
	game.entity_manager.entities[0] = entity;
}

entity_manager_t new_entity_manager(void) {
	return (entity_manager_t) {
		.update = entity_manager_update,
		.render = entity_manager_render,
		.add = entity_manager_add
	};
}

