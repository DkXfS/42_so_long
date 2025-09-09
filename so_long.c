#include "headers/so_long.h"
#include <sys/time.h>

// struct timeval
// {
//     time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
//     suseconds_t  tv_usec;  /* and microseconds */
// };

// int load_assets(struct state *game_state)
// {
//     int assetWH;

//     // Load wall sprite
//     game_state->animation.world_elements[0].asset.type = WALL;
//     game_state->animation.world_elements[0].asset.frames = malloc(sizeof(void**) * 1); // 1 state: static
//     if (!game_state->animation.world_elements[0].asset.frames)
//     {
//         ft_printf(RED"Error\n%s\n"RESET, "Failed to allocate memory for wall state");
//         return 1;
//     }
//     game_state->animation.world_elements[0].asset.frames[STATE_IDLE] = malloc(sizeof(void*) * 2); // 1 frame + NULL terminator
//     if (!game_state->animation.world_elements[0].asset.frames[STATE_IDLE])
//     {
//         ft_printf(RED"Error\n%s\n"RESET, "Failed to allocate memory for wall asset pointer");
//         free(game_state->animation.world_elements[0].asset.frames);
//         return 1;
//     }
//     game_state->animation.world_elements[0].asset.frames[STATE_IDLE][0] = mlx_png_file_to_image(game_state->conn_id, "tex/wall.png", &assetWH, &assetWH);
//     if (!game_state->animation.world_elements[0].asset.frames[STATE_IDLE][0])
//     {
//         ft_printf(RED"Error\n%s\n"RESET, "Failed to load wall image");
//         free(game_state->animation.world_elements[0].asset.frames[STATE_IDLE]);
//         free(game_state->animation.world_elements[0].asset.frames);
//         return 1;
//     }

//     // Load player sprites
//     game_state->animation.characters[0].asset.type = MAIN_CHARACTER;
//     game_state->animation.characters[0].asset.frames = malloc(sizeof(void**) * 2); // 2 states: idle, walk
//     if (!game_state->animation.characters[0].asset.frames)
//     {
//         ft_printf(RED"Error\n%s\n"RESET, "Failed to allocate memory for player asset frames");
//         return 1;
//     }
//     game_state
//     game_state->animation.characters[0].asset.frames[STATE_WALK][0] = mlx_png_file_to_image(game_state->conn_id, "tex/rogue/rogue_w1.png", &assetWH, &assetWH);
//     game_state->animation.characters[0].asset.frames[STATE_WALK][1] = mlx_png_file_to_image(game_state->conn_id, "tex/rogue/rogue_w2.png", &assetWH, &assetWH);
//     game_state->animation.characters[0].asset.frames[STATE_WALK][2] = NULL; // End of animation frames
//     for (int i = 0; i < 2; i++)
//     {
//         if (!game_state->animation.characters[0].asset.frames[STATE_WALK][i])
//         {
//             ft_printf(RED"Error\n%s\n"RESET, "Failed to load player walk sprite");
//             return 1;
//         }
//     }
    
//     return 0;
// }

int instance_chars(struct state *game_state)
{
    // Initialize character animation state and frame counters
    for (int i = 0; i < CHARACTERS_COUNT; i++)
    {
        game_state->animation.characters[i].state = STATE_WALK; // default state
        game_state->animation.characters[i].curr_frame = 0;
        game_state->animation.characters[i].x = -1; // Example positions
        game_state->animation.characters[i].y = -1; // Example positions

        // Load player sprites
        game_state->animation.characters[i].animations[STATE_WALK][0] = game_state->assets[0];
        game_state->animation.characters[i].animations[STATE_WALK][1] = game_state->assets[1];
        game_state->animation.characters[i].animations[STATE_WALK][2] = NULL; // End of animation frames
    }
    return 1;
}

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

int exit_func(void *param)
{
    struct state *game_state = (struct state *)param;
    mlx_destroy_window(game_state->conn_id, game_state->win_id);
    free(game_state->conn_id);

    // Free the allocated memory for the map
    for (int i = 0; game_state->map[i]; i++) {
        free(game_state->map[i]);
    }
    free(game_state->map);
    exit(0);

    return 0;
}

void draw(struct state *game_state)
{
    // mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->bg, 0, 0);
    int time_diff = (game_state->current_time.tv_sec - game_state->last_update_time.tv_sec) * 1000000;
    if(time_diff > 0)
        time_diff = (time_diff - 1) + game_state->current_time.tv_usec + (1000000 - game_state->last_update_time.tv_usec);
    else  
        time_diff = game_state->current_time.tv_usec - game_state->last_update_time.tv_usec;
    game_state->last_update_time.tv_sec = game_state->current_time.tv_sec;
    game_state->last_update_time.tv_usec = game_state->current_time.tv_usec;

    // printf("Map dimensions: %dx%d\n", game_state->stats.width, game_state->stats.height);
    // return;

    /// Draw map based on game_state->map
    for (int y = 0; y < game_state->stats.height; y++)
    {
        for (int x = 0; x < game_state->stats.width; x++)
        {
            // printf("Drawing tile at (%d, %d): %c\n", x, y, game_state->map[y][x]);
            char tile = game_state->map[y][x];
            void *img = NULL;
            if (tile == '1') // Wall
                img = game_state->assets[2];
            else if (tile == '0') // Grass
                img = game_state->assets[3];
            else if (tile == 'C') // Collectible
            {
                img = game_state->assets[4];
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->assets[3], x * game_state->tileWH, y * game_state->tileWH);
            }
            else if (tile == 'E') // Exit
            {
                img = game_state->assets[5];
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->assets[3], x * game_state->tileWH, y * game_state->tileWH);
            }
            else if (tile == 'P') // Player start position
            {
                if (game_state->animation.characters[0].x == -1 && game_state->animation.characters[0].y == -1)
                {
                    game_state->animation.characters[0].x = x * game_state->tileWH;
                    game_state->animation.characters[0].y = y * game_state->tileWH;
                }
                img = game_state->assets[3]; // Draw grass under player
            }

            if (img)
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, img, x * game_state->tileWH, y * game_state->tileWH);
        }
    }

    for (int i = 0; i < WORLD_ANIM_COUNT; i++)
    {
        mlx_put_image_to_window(game_state->conn_id, game_state->win_id,
                               game_state->animation.world_elements[i].frames[game_state->animation.world_elements[i].curr_frame],
                               game_state->animation.world_elements[i].x, game_state->animation.world_elements[i].y);
    }

    for (int i = 0; i < CHARACTERS_COUNT; i++)
    {
        mlx_put_image_to_window(game_state->conn_id, game_state->win_id,
                               game_state->animation.characters[i].animations[game_state->animation.characters[i].state][game_state->animation.characters[i].curr_frame],
                               game_state->animation.characters[i].x, game_state->animation.characters[i].y);
    }

    char *fps = ft_itoa(1000000/time_diff);
    mlx_string_put(game_state->conn_id, game_state->win_id, 10, 10, 0x00F1F1, fps);
    ft_printf("FPS: %s\n", fps);
    free(fps);
}

int screen_refresh(void *param)
{
    struct state *game_state = (struct state *)param;
    gettimeofday(&game_state->current_time, NULL);
    // printf("Current time: %ld.%06d\n", game_state->current_time.tv_sec, game_state->current_time.tv_usec);

    update_character_position(&game_state->animation, &game_state->keys, game_state->map, game_state->tileWH);

    if(game_state->keys.escRelease)
    {
        ft_printf("Escape key pressed\n");
        exit_func(game_state);
    }

    update_frames(&game_state->animation, game_state->current_time);
    draw(game_state);

    return 0;
}

void init_state(struct state *game_state)
{
    game_state->conn_id = NULL;
    game_state->win_id = NULL;
    game_state->bg = NULL;
    game_state->moveCount = 0;
    game_state->tileWH = 0;
    ft_bzero(game_state->assets, sizeof(game_state->assets));
    game_state->map = NULL;
    game_state->keys = (struct key_states){0};
    game_state->stats = (struct mapStats){0};
    game_state->animation = (struct animation){0};
    gettimeofday(&game_state->current_time, NULL);
    gettimeofday(&game_state->last_update_time, NULL);
}

int main(int argc, char **argv)
{
    struct state game_state;

    init_state(&game_state);

    if (argc != 2)
    {
        ft_printf(RED"Error\nUsage: %s <map_file>\n"RESET, argv[0]);
        return 1;
    }

    game_state.map = loadMap(argv[1], &game_state.stats);
    if (!game_state.map) {
        fprintf(stderr, "Failed to load map\n");
        return 1;
    }

    // Initialize animation timing
    gettimeofday(&game_state.animation.last_frame_time, NULL);

    game_state.conn_id = mlx_init();
    if (!game_state.conn_id)
    {
        ft_printf(RED"Error\nFailed to initialize MLX\n"RESET);
        return 1;
    }

    game_state.win_id = mlx_new_window(game_state.conn_id, 800, 600, "so_long");
    if (!game_state.win_id)
    {
        ft_printf(RED"Error\nFailed to create window\n"RESET);
        return 1;
    }

    // game_state.bg = mlx_png_file_to_image(game_state.conn_id, "tex/bg.png", &(int){800}, &(int){600});
    // if (!game_state.bg)
    // {
    //     ft_printf(RED"Error\nFailed to load background image\n"RESET);
    //     return 1;
    // }

    if(!load_assets(&game_state))
    {
        ft_printf(RED"Error\nFailed to load assets\n"RESET);
        return 1;
    }

    ft_printf(GRN"tile size: %d\n"RESET, game_state.tileWH);

    if(!instance_chars(&game_state))
    {
        ft_printf(RED"Error\nFailed to instance characters\n"RESET);
        return 1;
    }

    mlx_hook(game_state.win_id, 2, 1L << 0, key_press_hook, &game_state.keys);       // Mask unused on Macos Metal
    mlx_hook(game_state.win_id, 3, 1L << 1, key_release_hook, &game_state.keys);       // Mask unused on Macos Metal
    mlx_hook(game_state.win_id, 17, 1L << 2, exit_func, &game_state);       // Mask unused on Macos Metal
    // mlx_key_hook(game_state.win_id, key_hook, &game_state);
    mlx_mouse_hook(game_state.win_id, mouse_hook, &game_state);
    mlx_loop_hook(game_state.conn_id, screen_refresh, &game_state);
    // int imgWH = 3;
    // game_state.player_sprites[0] = mlx_png_file_to_image(game_state.conn_id, "tex/rogue/rogue_w1.png", &imgWH, &imgWH);
    // game_state.player_sprites[1] = mlx_png_file_to_image(game_state.conn_id, "tex/rogue/rogue_w0.png", &imgWH, &imgWH);
    // if (img)
    //     mlx_put_image_to_window(game_state.conn_id, game_state.win_id, img, 10, 10);
    // else
    //     ft_printf(RED"Error\nFailed to load image\n"RESET);

    mlx_loop(game_state.conn_id);

    return 0;
}
