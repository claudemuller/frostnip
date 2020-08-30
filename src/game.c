#include "game.h"
#include <stdio.h>
#include "asset_manager.h"
#include "entity_manager.h"

game_t new_game() {
	entity_manager_t em = new_entity_manager();
	asset_manager_t am = new_asset_manager(&em);

	return (game_t) {
			.entity_manager = em,
			.asset_manager = am
	};
}

