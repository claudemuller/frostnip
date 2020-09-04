#ifndef PLATFORMER_ENTITY_MANAGER_H
#define PLATFORMER_ENTITY_MANAGER_H

#include <SDL2/SDL.h>

typedef struct {
	void (* update)(void);
	void (* render)(void);
	void (* add)(SDL_Rect entity);

	SDL_Rect entities[];
} entity_manager_t;

entity_manager_t new_entity_manager(void);
void entity_manager_update(void);
void entity_manager_render(void);
void entity_manager_add(SDL_Rect entity);

#endif //PLATFORMER_ENTITY_MANAGER_H
