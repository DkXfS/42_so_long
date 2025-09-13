#include "headers/animation.h"

void update_frames(struct animation* anim, struct timeval current_time)
{
    if (current_time.tv_sec > anim->last_frame_time.tv_sec ||
        (current_time.tv_sec == anim->last_frame_time.tv_sec &&
         current_time.tv_usec >= (anim->last_frame_time.tv_usec + 66666))) // 15FPS // 66666us
    {

        anim->last_frame_time.tv_sec = current_time.tv_sec;
        anim->last_frame_time.tv_usec = current_time.tv_usec;
        for (int i = 0; i < CHARACTERS_COUNT; i++)
        {
            anim->characters[i].curr_frame++;
            if (anim->characters[i].animations[anim->characters[i].state][anim->characters[i].direction][anim->characters[i].curr_frame] == NULL)
                anim->characters[i].curr_frame = 0;
        }
    
        for (int i = 0; i < WORLD_ANIM_COUNT; i++)
        {
            anim->world_elements[i].curr_frame++;
            if (anim->world_elements[i].frames[anim->world_elements[i].curr_frame] == NULL)
                anim->world_elements[i].curr_frame = 0;
        }
    }
}

// void draw(struct character characters[], struct element world_elements[])
// {
//     for (int i = 0; i < WORLD_ANIM_COUNT; i++)
//     {
//         mlx_put_image_to_window(/* connection id */, /* window id */,
//                                world_elements[i].frames[world_elements[i].curr_frame],
//                                world_elements[i].x, world_elements[i].y);
//     }

//     for (int i = 0; i < CHARACTERS_COUNT; i++)
//     {
//         // Draw character[i] at (characters[i].x, characters[i].y)
//         // using characters[i].animations[characters[i].state][characters[i].curr_frame]
//     }
// };
