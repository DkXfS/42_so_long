#ifndef CONTROLS_H
#define CONTROLS_H

#include "keyCodes.h"
#include "game_data.h"

int key_press_hook(int keycode, struct state *game_state);
int key_release_hook(int keycode, struct state *game_state);

#endif
