#include "headers/animation.h"

void update_frames(struct animation* anim, struct timeval current_time)
{
    int i = 0;

    if (current_time.tv_sec > anim->last_frame_time.tv_sec ||
        (current_time.tv_sec == anim->last_frame_time.tv_sec &&
         current_time.tv_usec >= (anim->last_frame_time.tv_usec + 66666))) // 15FPS // 66666us
    {

        anim->last_frame_time.tv_sec = current_time.tv_sec;
        anim->last_frame_time.tv_usec = current_time.tv_usec;
        while (i < CHARACTERS_COUNT)
        {
            anim->characters[i].curr_frame++;
            if (anim->characters[i].animations[anim->characters[i].state][anim->characters[i].direction][anim->characters[i].curr_frame] == NULL)
                anim->characters[i].curr_frame = 0;
            i++;
        }
    
        i = 0;
        while (i < WORLD_ANIM_COUNT)
        {
            anim->world_elements[i].curr_frame++;
            if (anim->world_elements[i].frames[anim->world_elements[i].curr_frame] == NULL)
                anim->world_elements[i].curr_frame = 0;
            i++;
        }
    }
}
