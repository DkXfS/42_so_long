#include "headers/movement.h"

void update_character_position(struct animation *anim, struct key_states *keys, char **map, int tileWH)
{
    int mapX = anim->characters[0].x / tileWH;
    int mapY = anim->characters[0].y / tileWH;
    int mapModX = anim->characters[0].x % tileWH;
    int mapModY = anim->characters[0].y % tileWH;


    if (keys->up)
    {
        if(mapModY >= MOVE_SPEED || (map[mapY - 1][mapX] != '1' && map[mapY - 1][mapX + (mapModX > 0)] != '1'))
            anim->characters[0].y -= MOVE_SPEED;
    }
    if (keys->down)
    {
        if(map[mapY + 1][mapX] != '1' && map[mapY + 1][mapX + (mapModX > 0)] != '1')
            anim->characters[0].y += MOVE_SPEED;
    }
    if (keys->left)
    {
        if(mapModX >= MOVE_SPEED || (map[mapY][mapX - 1] != '1' && map[mapY + (mapModY > 0)][mapX - 1] != '1'))
            anim->characters[0].x -= MOVE_SPEED;
    }
    if (keys->right)
    {
        if(map[mapY][mapX + 1] != '1' && map[mapY + (mapModY > 0)][mapX + 1] != '1')
            anim->characters[0].x += MOVE_SPEED;
    }

    return;
}
