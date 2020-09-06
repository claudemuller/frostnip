#include <stdio.h>
#include "./lib/stretchy_buffer.h"
#include "entity_manager.h"
#include "constants.h"
#include "game.h"

void entity_manager_update(float delta_time) {
	if (DEBUG) {
		printf("updating entities...\n");
	}

	for (int i = 0; i < sb_count(game.entity_manager.entities); i++) {
		game.entity_manager.entities[i].update();
	}
}

void entity_manager_render(void) {
	if (DEBUG) {
		printf("rendering entities...\n");
	}

	SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 255);
	for (int i = 0; i < sb_count(game.entity_manager.entities); i++) {
		game.entity_manager.entities[i].update();
	}
}

void entity_manager_add(entity_t entity) {
	sb_push(game.entity_manager.entities, entity);
}

entity_manager_t new_entity_manager(void) {
	return (entity_manager_t){
			.update = entity_manager_update,
			.render = entity_manager_render,
			.add = entity_manager_add
	};
}

