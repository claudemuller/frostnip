#include "asset_manager.h"
#include <stdio.h>

void asset_manager_clear_data(void) {

}

asset_manager_t new_asset_manager(entity_manager_t* em) {
	return (asset_manager_t) {
			.entity_manager = em,
			.clear_data = asset_manager_clear_data
	};
}
