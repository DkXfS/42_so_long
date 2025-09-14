#ifndef GAME_DATA_H
#define GAME_DATA_H

// #include "gameState.h"
#include "../minilibx_mms_20200219/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "colors.h"
#include "animation.h"

#define ASSET_COUNT 134

static char* assetFiles[ASSET_COUNT] = {
    "tex/wall0.png",
    "tex/grass0.png",
    "tex/pouch.png",
    "tex/trapDoor.png",
    "tex/trapDoor1.png",
    "tex/text_bg.png",
    // Player sprites
    "tex/rogue/walk/rogue_D01.png",
    "tex/rogue/walk/rogue_D03.png",
    "tex/rogue/walk/rogue_D05.png",
    "tex/rogue/walk/rogue_D07.png",
    "tex/rogue/walk/rogue_D09.png",
    "tex/rogue/walk/rogue_D11.png",
    "tex/rogue/walk/rogue_D13.png",
    "tex/rogue/walk/rogue_D15.png",
    "tex/rogue/walk/rogue_D17.png",
    "tex/rogue/walk/rogue_D19.png",
    "tex/rogue/walk/rogue_D21.png",
    "tex/rogue/walk/rogue_D23.png",
    "tex/rogue/walk/rogue_D25.png",
    "tex/rogue/walk/rogue_D27.png",
    "tex/rogue/walk/rogue_D29.png",
    "tex/rogue/walk/rogue_U01.png",
    "tex/rogue/walk/rogue_U02.png",
    "tex/rogue/walk/rogue_U03.png",
    "tex/rogue/walk/rogue_U04.png",
    "tex/rogue/walk/rogue_U05.png",
    "tex/rogue/walk/rogue_U06.png",
    "tex/rogue/walk/rogue_U07.png",
    "tex/rogue/walk/rogue_U08.png",
    "tex/rogue/walk/rogue_U09.png",
    "tex/rogue/walk/rogue_U10.png",
    "tex/rogue/walk/rogue_U11.png",
    "tex/rogue/walk/rogue_U12.png",
    "tex/rogue/walk/rogue_U13.png",
    "tex/rogue/walk/rogue_U14.png",
    "tex/rogue/walk/rogue_U15.png",
    "tex/rogue/walk/rogue_L01.png",
    "tex/rogue/walk/rogue_L02.png",
    "tex/rogue/walk/rogue_L03.png",
    "tex/rogue/walk/rogue_L04.png",
    "tex/rogue/walk/rogue_L05.png",
    "tex/rogue/walk/rogue_L06.png",
    "tex/rogue/walk/rogue_L07.png",
    "tex/rogue/walk/rogue_L08.png",
    "tex/rogue/walk/rogue_L09.png",
    "tex/rogue/walk/rogue_L10.png",
    "tex/rogue/walk/rogue_L11.png",
    "tex/rogue/walk/rogue_L12.png",
    "tex/rogue/walk/rogue_L13.png",
    "tex/rogue/walk/rogue_L14.png",
    "tex/rogue/walk/rogue_L15.png",
    "tex/rogue/walk/rogue_R01.png",
    "tex/rogue/walk/rogue_R02.png",
    "tex/rogue/walk/rogue_R03.png",
    "tex/rogue/walk/rogue_R04.png",
    "tex/rogue/walk/rogue_R05.png",
    "tex/rogue/walk/rogue_R06.png",
    "tex/rogue/walk/rogue_R07.png",
    "tex/rogue/walk/rogue_R08.png",
    "tex/rogue/walk/rogue_R09.png",
    "tex/rogue/walk/rogue_R10.png",
    "tex/rogue/walk/rogue_R11.png",
    "tex/rogue/walk/rogue_R12.png",
    "tex/rogue/walk/rogue_R13.png",
    "tex/rogue/walk/rogue_R14.png",
    "tex/rogue/walk/rogue_R15.png",
    "tex/rogue/idle/rogue_D01.png",
    "tex/rogue/idle/rogue_U01.png",
    "tex/rogue/idle/rogue_L01.png",
    "tex/rogue/idle/rogue_R01.png",
    // Enemy sprites
    "tex/enemy/walk/D01.png",
    "tex/enemy/walk/D03.png",
    "tex/enemy/walk/D05.png",
    "tex/enemy/walk/D07.png",
    "tex/enemy/walk/D09.png",
    "tex/enemy/walk/D11.png",
    "tex/enemy/walk/D13.png",
    "tex/enemy/walk/D15.png",
    "tex/enemy/walk/D17.png",
    "tex/enemy/walk/D19.png",
    "tex/enemy/walk/D21.png",
    "tex/enemy/walk/D23.png",
    "tex/enemy/walk/D25.png",
    "tex/enemy/walk/D27.png",
    "tex/enemy/walk/D29.png",
    "tex/enemy/walk/U01.png",
    "tex/enemy/walk/U03.png",
    "tex/enemy/walk/U05.png",
    "tex/enemy/walk/U07.png",
    "tex/enemy/walk/U09.png",
    "tex/enemy/walk/U11.png",
    "tex/enemy/walk/U13.png",
    "tex/enemy/walk/U15.png",
    "tex/enemy/walk/U17.png",
    "tex/enemy/walk/U19.png",
    "tex/enemy/walk/U21.png",
    "tex/enemy/walk/U23.png",
    "tex/enemy/walk/U25.png",
    "tex/enemy/walk/U27.png",
    "tex/enemy/walk/U29.png",
    "tex/enemy/walk/L01.png",
    "tex/enemy/walk/L03.png",
    "tex/enemy/walk/L05.png",
    "tex/enemy/walk/L07.png",
    "tex/enemy/walk/L09.png",
    "tex/enemy/walk/L11.png",
    "tex/enemy/walk/L13.png",
    "tex/enemy/walk/L15.png",
    "tex/enemy/walk/L17.png",
    "tex/enemy/walk/L19.png",
    "tex/enemy/walk/L21.png",
    "tex/enemy/walk/L23.png",
    "tex/enemy/walk/L25.png",
    "tex/enemy/walk/L27.png",
    "tex/enemy/walk/L29.png",
    "tex/enemy/walk/R01.png",
    "tex/enemy/walk/R03.png",
    "tex/enemy/walk/R05.png",
    "tex/enemy/walk/R07.png",
    "tex/enemy/walk/R09.png",
    "tex/enemy/walk/R11.png",
    "tex/enemy/walk/R13.png",
    "tex/enemy/walk/R15.png",
    "tex/enemy/walk/R17.png",
    "tex/enemy/walk/R19.png",
    "tex/enemy/walk/R21.png",
    "tex/enemy/walk/R23.png",
    "tex/enemy/walk/R25.png",
    "tex/enemy/walk/R27.png",
    "tex/enemy/walk/R29.png",
    "tex/enemy/idle/D01.png",
    "tex/enemy/idle/U01.png",
    "tex/enemy/idle/L01.png",
    "tex/enemy/idle/R01.png",
};

struct key_states
{
    int up;
    int down;
    int left;
    int right;
    int escRelease;
};

struct posList
{
    int x;
    int y;
    struct posList* next;
};

struct mapStats
{
    int width;
    int height;
    int playerX;
    int playerY;
    int villainX;
    int villainY;
    int exitX;
    int exitY;
    int shortestRouteLength;
    int collectibleCount;
    struct posList* collectibles;
};

struct state
{
    void* conn_id;
    void* win_id;
    void* bg;
    float moveCount;
    int tileWH;
    void* assets[ASSET_COUNT];
    char** map;
    int collected;
    struct key_states keys;
    struct mapStats stats;
    struct animation animation;
    struct timeval current_time;
    struct timeval last_update_time;
};

int load_assets(struct state *game_state);

#endif
