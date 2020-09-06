#ifndef FROSTNIP_ENTITY_H
#define FROSTNIP_ENTITY_H

#include <stdbool.h>
#include "entity_manager.h"
#include "layer_type.h"

typedef struct {
	void (* update)(void);
	void (* render)(void);
	void (* destroy)(void);
	void (* list_components)(void);
	void (* add_component)(void);
	void (* get_component)(void);
	void (* has_component)(void);

	entity_manager_t* manager;
	char* name;
	layer_type_t layer;
	bool is_active;
	// components
	// component_type_map
} entity_t;

// The entity factory optional named param struct.
typedef struct {
	entity_manager_t* manager;
	char* name;
	layer_type_t layer;
} entity_desc;

entity_t new_entity(const entity_desc* desc);

void entity_update(void);
void entity_render(void);
void entity_destroy(void);
void entity_list_components(void);
void entity_add_component(void);
void entity_get_component(void);
void entity_has_component(void);

#endif //FROSTNIP_ENTITY_H
