#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "animation.h"
#include "controls.h"
#include "game_data.h"
#include "so_long.h"
#include "navigation.h"

#define MOVE_SPEED 2

void update_character_position(struct state *game_state);
void update_enemy_position(struct state *game_state);
void check_collisions(struct state *game_state);

#endif
