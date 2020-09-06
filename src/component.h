#ifndef FROSTNIP_COMPONENT_H
#define FROSTNIP_COMPONENT_H

typedef struct {
	void (* init)(void);
	void (* update)(void);
	void (* render)(void);

//	entity_t* owner;
} component_t;

// The component factory optional named param struct.
typedef struct {
//	entity_t* owner;
} component_desc;

component_t new_component(const component_desc* desc);

void component_init(void);
void component_update(void);
void component_render(void);

#endif //FROSTNIP_COMPONENT_H
