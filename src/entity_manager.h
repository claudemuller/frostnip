#ifndef FROSTBIT_ENTITY_MANAGER_H
#define FROSTBIT_ENTITY_MANAGER_H

#include <SDL2/SDL.h>
#include "entity.h"

typedef struct {
	void (* update)(float);
	void (* render)(void);
	void (* add)(entity_t entity);

	entity_t* entities;
} entity_manager_t;

entity_manager_t new_entity_manager(void);
void entity_manager_update(float);
void entity_manager_render(void);
void entity_manager_add(entity_t entity);

#endif //FROSTBIT_ENTITY_MANAGER_H
