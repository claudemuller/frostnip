#ifndef FROSTNIP_ENTITY_MANAGER_H
#define FROSTNIP_ENTITY_MANAGER_H

#include <SDL2/SDL.h>

typedef struct {
	void (* update)(float);
	void (* render)(void);
	void (* add)(SDL_Rect entity);

	SDL_Rect entities[];
} entity_manager_t;

entity_manager_t new_entity_manager(void);
void entity_manager_update(float);
void entity_manager_render(void);
void entity_manager_add(SDL_Rect entity);

#endif //FROSTNIP_ENTITY_MANAGER_H
