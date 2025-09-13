#ifndef CONTROLS_H
#define CONTROLS_H

#include "keyCodes.h"
#include "game_data.h"
#include <stdio.h>

// int key_hook(int keycode, void *param);
int key_press_hook(int keycode, struct state *game_state);
int key_release_hook(int keycode, struct state *game_state);
int mouse_hook(int button, int x, int y, void *param);

#endif
