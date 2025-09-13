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
