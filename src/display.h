#ifndef FROSTBIT_DISPLAY_H
#define FROSTBIT_DISPLAY_H

#include <stdbool.h>
#include "game.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

bool init_window();

#endif //FROSTBIT_DISPLAY_H
