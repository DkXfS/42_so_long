#ifndef SO_LONG_H
#define SO_LONG_H

#include "keyCodes.h"
#include "mapLoader.h"
#include "animation.h"
#include "controls.h"
#include "movement.h"
#include "../minilibx_mms_20200219/mlx.h"
#include "../libft/libft.h"


#define GAME_RES_X 800
#define GAME_RES_Y 600
#define ASSET_COUNT 6

static char* assetFiles[ASSET_COUNT] = {
    "tex/rogue/rogue_w1.png",
    "tex/rogue/rogue_w2.png",
    "tex/wall0.png",
    "tex/grass0.png",
    "tex/pouch.png",
    "tex/door.png"
};

struct state
{
    void* conn_id;
    void* win_id;
    void* bg;
    int moveCount;
    int tileWH;
    void* assets[ASSET_COUNT];
    char** map;
    struct key_states keys;
    struct mapStats stats;
    struct animation animation;
    struct timeval current_time;
    struct timeval last_update_time;
};

int exit_func(void* param);
int screen_refresh(void *param);

#endif
