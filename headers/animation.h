#ifndef ANIMATION_H
#define ANIMATION_H

#include <sys/time.h>

#define CHARACTERS_COUNT 1
#define WORLD_ANIM_COUNT 0

// Animation states
#define STATE_IDLE 0
#define STATE_WALK 1

#define ANIM_LEFT 0
#define ANIM_RIGHT 1
#define ANIM_UP 2
#define ANIM_DOWN 3

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
    int direction; // e.g., left, right, up, down
    int curr_frame; // current frame in animation
    void* animations[2][4][16];
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

void update_frames(struct animation* anim, struct timeval current_time);

#endif
