#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "animation.h"
#include "controls.h"

#define MOVE_SPEED 2

void update_character_position(struct animation *anim, struct key_states *keys, char **map, int tileWH);

#endif
