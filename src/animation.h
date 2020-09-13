#ifndef FROSTBIT_ANIMATION_H
#define FROSTBIT_ANIMATION_H

typedef struct {
	unsigned int index;
	unsigned int num_frames;
	unsigned int animation_speed;
} animation_t;

animation_t new_animation(unsigned int index, unsigned int num_frames, unsigned int animation_speed);

#endif //FROSTBIT_ANIMATION_H
