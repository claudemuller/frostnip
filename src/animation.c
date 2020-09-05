#include "animation.h"

animation_t new_animation(unsigned int index, unsigned int num_frames, unsigned int animation_speed) {
	return (animation_t){
			.index = index,
			.num_frames = num_frames,
			.animation_speed = animation_speed
	};
}
