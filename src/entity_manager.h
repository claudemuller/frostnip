#ifndef PLATFORMER_ENTITY_MANAGER_H
#define PLATFORMER_ENTITY_MANAGER_H

typedef struct {
	void (* update)(void);
	void (* render)(void);
} entity_manager_t;

entity_manager_t new_entity_manager(void);
void entity_manager_update(void);
void entity_manager_render(void);

#endif //PLATFORMER_ENTITY_MANAGER_H
