#include "entity.h"

entity_t new_entity(const entity_desc* desc) {
	return (entity_t) {
		.manager = desc->manager,
		.name = desc->name,
		.layer =  desc->layer,
		.is_active = true,

		.update = entity_update,
		.render = entity_render,
		.destroy = entity_destroy,
		.list_components = entity_list_components,
		.add_component = entity_add_component,
		.get_component = entity_get_component,
		.has_component = entity_has_component
	};
}

void entity_update(void) {
	// Update components.
}

void entity_render(void) {
	// Render components.
}

void entity_destroy(void) {
	// Destroy something?
}

void entity_list_components(void) {
	// Get list of components.
}

void entity_add_component(void) {
	// Add component.
}

void entity_get_component(void) {
	// Get component.
}

void entity_has_component(void) {
	// Check if has component.
}

