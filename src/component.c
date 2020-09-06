#include <stdio.h>
#include "component.h"

component_t new_component(const component_desc* desc) {
	return (component_t) {
//			.owner = desc->owner,

			.init = component_init,
			.update = component_update,
			.render = component_render
	};
}

void component_init(void) {

}

void component_update(void) {
	// Update components.
	printf("my owners name is %s\n", "component");//owner->name);
}

void component_render(void) {
	// Render components.
}
