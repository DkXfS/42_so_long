#ifndef CONTROLS_H
#define CONTROLS_H

#include "keyCodes.h"
#include <stdio.h>

struct key_states
{
    int up;
    int down;
    int left;
    int right;
    int escRelease;
};

// int key_hook(int keycode, void *param);
int key_press_hook(int keycode, struct key_states *keys);
int key_release_hook(int keycode, struct key_states *keys);
int mouse_hook(int button, int x, int y, void *param);

#endif
