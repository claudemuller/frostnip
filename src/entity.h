#ifndef FROSTBIT_ENTITY_H
#define FROSTBIT_ENTITY_H

#include <stdbool.h>
#include "component.h"
#include "layer_type.h"

typedef struct {
	void (* update)(void);
	void (* render)(int*);
	void (* destroy)(void);
	void (* list_components)(void);
	void (* add_component)();
	void (* get_component)(void);
	void (* has_component)(void);

	char* name;
	layer_type_t layer;
	bool is_active;
	component_t* components;
	// component_type_map
} entity_t;

// The entity factory optional named param struct.
typedef struct {
	char* name;
	layer_type_t layer;
} entity_desc;

entity_t new_entity(const entity_desc* desc);

void entity_update(void);
void entity_render(entity_t* e);
void entity_destroy(void);
void entity_list_components(void);
void entity_add_component(component_t c);
void entity_get_component(void);
void entity_has_component(void);

#endif //FROSTBIT_ENTITY_H
