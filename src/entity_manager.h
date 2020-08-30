#ifndef PLATFORMER_ENTITY_MANAGER_H
#define PLATFORMER_ENTITY_MANAGER_H

typedef struct entity_manager_s {
	void (* test)(void);
} entity_manager_t;

entity_manager_t new_entity_manager(void);

void entity_manager_test(void);

#endif //PLATFORMER_ENTITY_MANAGER_H
