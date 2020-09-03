#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include "asset_manager.h"
#include "entity_manager.h"

typedef struct {
	entity_manager_t entity_manager;
	asset_manager_t asset_manager;
} game_t;

game_t new_game(void);

#endif //PLATFORMER_GAME_H
