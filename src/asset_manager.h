#ifndef FROSTNIP_ASSET_MANAGER_H
#define FROSTNIP_ASSET_MANAGER_H

#include "entity_manager.h"

typedef struct {
	void (* clear_data)(void);

	entity_manager_t* entity_manager;
//	 <map> textures;
//	 <map> fonts;
} asset_manager_t;

asset_manager_t new_asset_manager(entity_manager_t*);
void asset_manager_clear_data(void);

//void addTexture(std::string textureId, const char* filePath);
//SDL_Texture* getTexture(std::string textureId);
//void addFont(std::string fontId, const char* filePath, int fontSize);
//TTF_Font* getFont(std::string fontId);

#endif //FROSTNIP_ASSET_MANAGER_H
