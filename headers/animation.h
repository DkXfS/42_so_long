#ifndef ANIMATION_H
#define ANIMATION_H

#include <sys/time.h>

#define CHARACTERS_COUNT 1
#define WORLD_ANIM_COUNT 0

// Animation states
#define STATE_IDLE 0
#define STATE_WALK 1

#define MAIN_CHARACTER 0
#define ENEMY_CHARACTER 1
#define COLLECTIBLE 2
#define EXIT 3
#define BACKGROUND 4
#define WALL 5

struct character
{
    int x;
    int y;
    int state; // e.g., idle, walking, jumping
    int curr_frame; // current frame in animation
    void* animations[2][3];
};

struct element
{
    int x;
    int y;
    int curr_frame;
    void* frames[3];
};

struct animation
{
    struct timeval last_frame_time;
    struct element world_elements[WORLD_ANIM_COUNT];
    struct character characters[CHARACTERS_COUNT];
};

// Update animation frames for all characters and world elements.
// Arrays decay to pointers here; the sizes are governed by the
// CHARACTERS_COUNT and WORLD_ANIM_COUNT macros.
void update_frames(struct animation* anim, struct timeval current_time);

#endif