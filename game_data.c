#include "headers/game_data.h"

int load_assets(struct state *game_state)
{
    for(int i = 0; i < ASSET_COUNT; i++)
        game_state->assets[i] = NULL;

    for(int i = 0; i < ASSET_COUNT; i++)
    {
        game_state->assets[i] = mlx_png_file_to_image(game_state->conn_id, assetFiles[i], &game_state->tileWH, &game_state->tileWH);
        if (!game_state->assets[i])
        {
            ft_printf(RED"Error\nFailed to load asset: %s\n"RESET, assetFiles[i]);
            for(int j = 0; j < i; j++)
            {
                if (game_state->assets[j])
                    mlx_destroy_image(game_state->conn_id, game_state->assets[j]);
            }
            return 0;
        }
    }

    return 1;
}

void free_assets(struct state *game_state)
{
    int i = 0;
    while(i < ASSET_COUNT)
    {
        if (game_state->assets[i])
            mlx_destroy_image(game_state->conn_id, game_state->assets[i]);
        i++;
    }
}

void init_state(struct state *game_state)
{
    game_state->conn_id = NULL;
    game_state->win_id = NULL;
    game_state->moveCount = 0;
    game_state->tileWH = 0;
    ft_bzero(game_state->assets, sizeof(game_state->assets));
    game_state->collected = 0;
    game_state->map = NULL;
    ft_bzero(&game_state->keys, sizeof(game_state->keys));
    game_state->stats.collectibleCount = 0;
    game_state->stats.width = 0;
    game_state->stats.height = 0;
    game_state->stats.playerX = -1;
    game_state->stats.playerY = -1;
    game_state->stats.villainX = -1;
    game_state->stats.villainY = -1;
    game_state->stats.exitX = -1;
    game_state->stats.exitY = -1;
    game_state->stats.shortestRouteLength = 0;
    game_state->stats.collectibles = NULL;
    ft_bzero(&game_state->animation, sizeof(game_state->animation));
    gettimeofday(&game_state->current_time, NULL);
    gettimeofday(&game_state->last_refresh_time, NULL);
    gettimeofday(&game_state->last_movement_time, NULL);
}

int time_diff_usec(struct timeval* end, struct timeval* start)
{
    return (end->tv_sec - start->tv_sec) * 1000000 + (end->tv_usec - start->tv_usec);
}
