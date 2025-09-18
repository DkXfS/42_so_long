#include "headers/so_long.h"
#include <sys/time.h>

void draw_ui(struct state* game_state, int time_diff, int window_width, int viewport_height)
{
    char *moves_num = NULL;
    char* moves_ui = NULL;
    char* collected_num = NULL;
    char* collected_ui1 = NULL;
    char* collected_ui2 = NULL;
    char* collected_ui = NULL;
    char* total = NULL;
    char *fps = NULL, *fps_ui = NULL;

    int x = 0;
    while (x <= window_width)
    {
        mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->assets[5], x, viewport_height);
        x += game_state->tileWH;
    }
    if ((moves_num = ft_itoa(game_state->moveCount/2)) && (moves_ui = ft_strjoin("Moves: ", moves_num)))
        mlx_string_put(game_state->conn_id, game_state->win_id, 10, viewport_height + (UI_OFFSET/2), 0x00F1F1, moves_ui);
    if ((collected_num = ft_itoa(game_state->collected)) && (total = ft_itoa(game_state->stats.collectibleCount)))
        if ((collected_ui1 = ft_strjoin("Collected: ", collected_num)) && (collected_ui2 = ft_strjoin("/", total)))
            if ((collected_ui = ft_strjoin(collected_ui1, collected_ui2)))
                mlx_string_put(game_state->conn_id, game_state->win_id, 150, viewport_height + (UI_OFFSET/2), 0x00F1F1, collected_ui);
    if ((fps = ft_itoa(1000000/time_diff)) && (fps_ui = ft_strjoin("Inst. FPS: ", fps)))
        mlx_string_put(game_state->conn_id, game_state->win_id, 340, viewport_height + (UI_OFFSET/2), 0x00F1F1, fps_ui);
    // ft_printf("FPS: %s\n", fps);
    free(fps);
    free(fps_ui);
    free(moves_num);
    free(moves_ui);
    free(collected_num);
    free(collected_ui1);
    free(collected_ui2);
    free(collected_ui);
    free(total);
}

int instance_chars(struct state *game_state)
{
    int i = 0;
    while (i < CHARACTERS_COUNT)
    {
        game_state->animation.characters[i].state = STATE_IDLE;
        game_state->animation.characters[i].direction = ANIM_UP;
        game_state->animation.characters[i].curr_frame = 0;
        if(i)
        {
            game_state->animation.characters[i].x = game_state->stats.villainX * game_state->tileWH;
            game_state->animation.characters[i].y = game_state->stats.villainY * game_state->tileWH;
        }
        else
        {
            game_state->animation.characters[i].x = game_state->stats.playerX * game_state->tileWH;
            game_state->animation.characters[i].y = game_state->stats.playerY * game_state->tileWH;
        }

        int j = 0;
        while (j < 15)
        {
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_DOWN][j] = game_state->assets[j + (i * 64) + 6];
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_UP][j] = game_state->assets[j + 15 + (i * 64) + 6];
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_LEFT][j] = game_state->assets[j + 30 + (i * 64) + 6];
            game_state->animation.characters[i].animations[STATE_WALK][ANIM_RIGHT][j] = game_state->assets[j + 45 + (i * 64) + 6];
            j++;
        }
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_DOWN][j] = NULL;
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_UP][j] = NULL;
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_LEFT][j] = NULL;
        game_state->animation.characters[i].animations[STATE_WALK][ANIM_RIGHT][j] = NULL;

        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_DOWN][0] = game_state->assets[66 + (i * 64)];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_DOWN][1] = NULL;
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_UP][0] = game_state->assets[67 + (i * 64)];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_UP][1] = NULL;
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_LEFT][0] = game_state->assets[68 + (i * 64)];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_LEFT][1] = NULL;
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_RIGHT][0] = game_state->assets[69 + (i * 64)];
        game_state->animation.characters[i].animations[STATE_IDLE][ANIM_RIGHT][1] = NULL;

        i++;
    }
    return 1;
}

int exit_func(void *param)
{
    ft_printf(GRN"Exiting game...\n"RESET);
    struct state *game_state = (struct state *)param;
    free_assets(game_state, ASSET_COUNT);
    mlx_destroy_window(game_state->conn_id, game_state->win_id);
    free(game_state->conn_id);
    free_map(game_state->map);
    exit(0);

    return 0;
}

void draw(struct state *game_state)
{
    mlx_clear_window(game_state->conn_id, game_state->win_id);
    int time_diff = game_state->current_time.tv_sec - game_state->last_refresh_time.tv_sec;
    if(time_diff > 0)
        time_diff = time_diff * 1000000 + game_state->current_time.tv_usec + (1000000 - game_state->last_refresh_time.tv_usec);
    else
        time_diff = game_state->current_time.tv_usec - game_state->last_refresh_time.tv_usec;
    game_state->last_refresh_time.tv_sec = game_state->current_time.tv_sec;
    game_state->last_refresh_time.tv_usec = game_state->current_time.tv_usec;

    int draw_offset_x = 0;
    int draw_offset_y = 0;
    int viewport_height = game_state->stats.height * game_state->tileWH;
    int window_width = game_state->stats.width * game_state->tileWH;
    if (game_state->stats.width * game_state->tileWH > NUM_TILES_WIDTH * game_state->tileWH)
    {
        int window_center = NUM_TILES_WIDTH * game_state->tileWH / 2;
        int player_x = game_state->animation.characters[0].x;
        int map_width = game_state->stats.width * game_state->tileWH;
        window_width = NUM_TILES_WIDTH * game_state->tileWH;
        
        draw_offset_x = window_center - player_x;
        
        if (draw_offset_x > 0)
            draw_offset_x = 0;
        else if (draw_offset_x < -(map_width - window_width))
            draw_offset_x = -(map_width - window_width);
    }
    if (game_state->stats.height * game_state->tileWH > NUM_TILES_HEIGHT * game_state->tileWH)
    {
        int viewport_center = NUM_TILES_HEIGHT * game_state->tileWH / 2;
        int player_y = game_state->animation.characters[0].y;
        int map_height = game_state->stats.height * game_state->tileWH;
        viewport_height = NUM_TILES_HEIGHT * game_state->tileWH;

        draw_offset_y = viewport_center - player_y;

        if (draw_offset_y > 0)
            draw_offset_y = 0;
        else if (draw_offset_y < -(map_height - viewport_height))
            draw_offset_y = -(map_height - viewport_height);
    }
    
    int x = 0;
    int y = 0;
    int draw_x, draw_y;
    while (y < game_state->stats.height)
    {
        draw_y = y * game_state->tileWH + draw_offset_y;
        if (draw_y < -game_state->tileWH || draw_y >= viewport_height)
        {
            y++;
            continue;
        }
        
        x = 0;
        while (x < game_state->stats.width)
        {
            draw_x = x * game_state->tileWH + draw_offset_x;
            if (draw_x < -game_state->tileWH || draw_x >= window_width)
            {
                x++;
                continue;
            }

            char tile = game_state->map[y][x];
            void *img = NULL;
            if (tile == '1') // Wall
                img = game_state->assets[0];
            else if (tile == '0') // Grass
                img = game_state->assets[1];
            else if (tile == 'C') // Collectible
            {
                img = game_state->assets[2];
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->assets[1], x * game_state->tileWH + draw_offset_x, y * game_state->tileWH + draw_offset_y);
            }
            else if (tile == 'E') // Exit
            {
                if (game_state->collected >= game_state->stats.collectibleCount)
                    img = game_state->assets[4];
                else
                    img = game_state->assets[3];
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, game_state->assets[1], x * game_state->tileWH + draw_offset_x, y * game_state->tileWH + draw_offset_y);
            }
            else if (tile == 'P' || tile == 'V')
                img = game_state->assets[1];

            if (img)
                mlx_put_image_to_window(game_state->conn_id, game_state->win_id, img, x * game_state->tileWH + draw_offset_x, y * game_state->tileWH + draw_offset_y);

            x++;
        }
        y++;
    }

    x = 0;
    while (x < WORLD_ANIM_COUNT)
    {
        mlx_put_image_to_window(game_state->conn_id, game_state->win_id,
                               game_state->animation.world_elements[x].frames[game_state->animation.world_elements[x].curr_frame],
                               game_state->animation.world_elements[x].x + draw_offset_x, game_state->animation.world_elements[x].y + draw_offset_y);
        x++;
    }

    x = 0;
    while (x < CHARACTERS_COUNT)
    {
        mlx_put_image_to_window(game_state->conn_id, game_state->win_id,
                               game_state->animation.characters[x].animations[game_state->animation.characters[x].state][game_state->animation.characters[x].direction][game_state->animation.characters[x].curr_frame],
                               game_state->animation.characters[x].x + draw_offset_x, game_state->animation.characters[x].y + draw_offset_y);
        x++;
    }

    draw_ui(game_state, time_diff, window_width, viewport_height);
}

int screen_refresh(void *param)
{
    struct state *game_state = (struct state *)param;

    if(game_state->keys.escRelease)
    {
        ft_printf(YEL"Escape key pressed\n"RESET);
        exit_func(game_state);
    }

    gettimeofday(&game_state->current_time, NULL);
    update_positions(game_state);

    update_frames(&game_state->animation, game_state->current_time);
    draw(game_state);

    return 0;
}

int isBerFile(const char* filename)
{
    char* dot = ft_strrchr(filename, '.');
    return (dot && !ft_strcmp(dot, ".ber"));
}

int main(int argc, char **argv)
{
    struct state game_state;
    int window_width = NUM_TILES_WIDTH;
    int window_height = NUM_TILES_HEIGHT;

    init_state(&game_state);

    if (argc != 2)
    {
        ft_printf(RED"Error\nUsage: %s <map_file.ber>\n"RESET, argv[0]);
        return 1;
    }

    if (!isBerFile(argv[1]))
    {
        ft_printf(RED"Error\nInvalid map file. Please provide a .ber file.\n"RESET);
        return 1;
    }

    ft_printf(GRN"Loading map...");
    game_state.map = loadMap(argv[1], &game_state.stats);
    if (!game_state.map) {
        ft_printf(RED"Error\nFailed to load map\n"RESET);
        return 1;
    }
    ft_printf("   Success\n"RESET);

    // Initialize animation timing
    gettimeofday(&game_state.animation.last_frame_time, NULL);

    ft_printf(GRN"Initializing MLX...");
    game_state.conn_id = mlx_init();
    if (!game_state.conn_id)
    {
        ft_printf(RED"Error\nFailed to initialize MLX\n"RESET);
        return 1;
    }
    ft_printf("   Success\n"RESET);

    ft_printf(GRN"Loading assets...");
    if(!load_assets(&game_state))
    {
        ft_printf(RED"Error\nFailed to load assets\n"RESET);
        return 1;
    }
    ft_printf("   Success\n"RESET);

    if (game_state.stats.width < window_width)
        window_width = game_state.stats.width;
    if (game_state.stats.height < window_height)
        window_height = game_state.stats.height;
    window_width = window_width * game_state.tileWH;
    window_height = window_height * game_state.tileWH + UI_OFFSET;

    ft_printf(GRN"Creating window...");
    game_state.win_id = mlx_new_window(game_state.conn_id, window_width, window_height, "so_long");
    if (!game_state.win_id)
    {
        ft_printf(RED"Error\nFailed to create window\n"RESET);
        return 1;
    }
    ft_printf("   Success\n"RESET);

    ft_printf(GRN"Instancing characters...");
    if(!instance_chars(&game_state))
    {
        ft_printf(RED"Error\nFailed to instance characters\n"RESET);
        return 1;
    }
    ft_printf("   Success\n"RESET);

    mlx_hook(game_state.win_id, 2, 1L << 0, key_press_hook, &game_state);       // Mask unused on Macos Metal
    mlx_hook(game_state.win_id, 3, 1L << 1, key_release_hook, &game_state);       // Mask unused on Macos Metal
    mlx_hook(game_state.win_id, 17, 1L << 2, exit_func, &game_state);       // Mask unused on Macos Metal
    mlx_loop_hook(game_state.conn_id, screen_refresh, &game_state);

    ft_printf(GRN"Starting game loop...\n"RESET);
    // ft_printf(WHTB"\n"RESET);
    ft_printf("\n");
    ft_printf(BBLU"Use arrow keys or WASD to move. To exit press ESC or click the close button.\n"RESET);
    mlx_loop(game_state.conn_id);

    return 0;
}
