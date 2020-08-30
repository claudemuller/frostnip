#include "entity_manager.h"
#include <stdio.h>

void entity_manager_test(void) {

}

entity_manager_t new_entity_manager(void) {
	return (entity_manager_t) {
		.test = entity_manager_test
	};
}

