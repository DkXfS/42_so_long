#ifndef ANIMATION_H
#define ANIMATION_H

#include <sys/time.h>

#define CHARACTERS_COUNT 2
#define WORLD_ANIM_COUNT 0

// Animation states
#define STATE_IDLE 0
#define STATE_WALK 1

#define ANIM_LEFT 0
#define ANIM_RIGHT 1
#define ANIM_UP 2
#define ANIM_DOWN 3

struct character
{
    int x;
    int y;
    int state;
    int direction;
    int curr_frame;
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
