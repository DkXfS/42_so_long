#include "headers/so_long.h"
#include <sys/time.h>

// struct timeval
// {
//     time_t       tv_sec;   /* seconds since Jan. 1, 1970 */
//     suseconds_t  tv_usec;  /* and microseconds */
// };

int instance_chars(struct state *game_state)
{
    // Initialize character animation state and frame counters
    for (int i = 0; i < CHARACTERS_COUNT; i++)
    {
        game_state->animation.characters[i].state = STATE_IDLE; // default state
        game_state->animation.characters[i].direction = ANIM_UP; // default direction
        game_state->animation.characters[i].curr_frame = 0;
        game_state->animation.characters[i].x = -1; // Example positions
        game_state->animation.characters[i].y = -1; // Example positions

        // Load player walk sprites
        int j = 0;
        while (j < 15)
        {
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_DOWN][j] = game_state->assets[j + 5];
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_UP][j] = game_state->assets[j + 20];
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_LEFT][j] = game_state->assets[j + 35];
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_RIGHT][j] = game_state->assets[j + 50];
            j++;
        }
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_DOWN][j] = NULL;
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_UP][j] = NULL;
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_LEFT][j] = NULL;
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_RIGHT][j] = NULL;

        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_DOWN][0] = game_state->assets[65];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_DOWN][1] = NULL;
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_UP][0] = game_state->assets[66];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_UP][1] = NULL;
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_LEFT][0] = game_state->assets[67];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_LEFT][1] = NULL;
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_RIGHT][0] = game_state->assets[68];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_RIGHT][1] = NULL;
    }
    return 1;
}

int exit_func(void *param)
{
    struct state *game_state = (struct state *)param;
    mlx_destroy_window(game_state->conn_id, game_state->win_id);
    free(game_state->conn_id);

    // Free the allocated memory for the map
    for (int i = 0; game_state->map[i]; i++)
    {
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
                img = game_state->assets[0];
            else if (tile == '0') // Grass
                img = game_state->assets[1];
            else if (tile == 'C') // Collectible
            {
                img = game_state->assets[2];
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->assets[1], x * game_state->tileWH, y * game_state->tileWH);
            }
            else if (tile == 'E') // Exit
            {
                if (game_state->collected >= game_state->stats.collectibleCount)
                    img = game_state->assets[4];
                else
                    img = game_state->assets[3];
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->assets[1], x * game_state->tileWH, y * game_state->tileWH);
            }
            else if (tile == 'P') // Player start position
            {
                if (game_state->animation.characters[0].x == -1 && game_state->animation.characters[0].y == -1)
                {
                    game_state->animation.characters[0].x = x * game_state->tileWH;
                    game_state->animation.characters[0].y = y * game_state->tileWH;
                }
                img = game_state->assets[1]; // Draw grass under player
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
                               game_state->animation.characters[i].animations[game_state->animation.characters[i].state][game_state->animation.characters[i].direction][game_state->animation.characters[i].curr_frame],
                               game_state->animation.characters[i].x, game_state->animation.characters[i].y);
    }

    char *fps = ft_itoa(1000000/time_diff);
    mlx_string_put(game_state->conn_id, game_state->win_id, 10, 10, 0x00F1F1, fps);
    // ft_printf("FPS: %s\n", fps);
    free(fps);
}

int screen_refresh(void *param)
{
    struct state *game_state = (struct state *)param;

    if(game_state->keys.escRelease)
    {
        ft_printf("Escape key pressed\n");
        exit_func(game_state);
    }

    gettimeofday(&game_state->current_time, NULL);
    // printf("Current time: %ld.%06d\n", game_state->current_time.tv_sec, game_state->current_time.tv_usec);

    update_character_position(game_state);
    check_collisions(game_state);

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
    game_state->collected = 0;
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

    ft_printf(GRN"Map loaded successfully!\n"RESET);

    // Initialize animation timing
    gettimeofday(&game_state.animation.last_frame_time, NULL);

    game_state.conn_id = mlx_init();
    if (!game_state.conn_id)
    {
        ft_printf(RED"Error\nFailed to initialize MLX\n"RESET);
        return 1;
    }

    game_state.win_id = mlx_new_window(game_state.conn_id, GAME_RES_X, GAME_RES_Y, "so_long");
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

    mlx_hook(game_state.win_id, 2, 1L << 0, key_press_hook, &game_state);       // Mask unused on Macos Metal
    mlx_hook(game_state.win_id, 3, 1L << 1, key_release_hook, &game_state);       // Mask unused on Macos Metal
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
