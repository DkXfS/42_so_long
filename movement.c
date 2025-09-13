#include "headers/movement.h"

void check_collisions(struct state *game_state)
{
    int x1 = game_state->animation.characters[0].x / game_state->tileWH;
    int y1 = game_state->animation.characters[0].y / game_state->tileWH;
    int x2 = (game_state->animation.characters[0].x + game_state->tileWH) / game_state->tileWH;
    int y2 = (game_state->animation.characters[0].y + game_state->tileWH) / game_state->tileWH;

    if (game_state->map[y1][x1] == 'C' || game_state->map[y1][x2] == 'C' ||
        game_state->map[y2][x1] == 'C' || game_state->map[y2][x2] == 'C')
    {
        // Collectible found
        game_state->collected++;
        ft_printf("Collected: %d\n", game_state->collected);
        // Remove collectible from map
        if (game_state->map[y1][x1] == 'C')
            game_state->map[y1][x1] = '0';
        if (game_state->map[y1][x2] == 'C')
            game_state->map[y1][x2] = '0';
        if (game_state->map[y2][x1] == 'C')
            game_state->map[y2][x1] = '0';
        if (game_state->map[y2][x2] == 'C')
            game_state->map[y2][x2] = '0';
    }
    if (game_state->map[y1][x1] == 'E' || game_state->map[y1][x2] == 'E' ||
        game_state->map[y2][x1] == 'E' || game_state->map[y2][x2] == 'E')
    {
        if (game_state->collected >= game_state->stats.collectibleCount)
        {
            ft_printf("All collectibles gathered! You win!\n");
            exit_func(game_state);
        }
        else
        {
            ft_printf("Collect all items before exiting! (%d/%d)\n", game_state->collected, game_state->stats.collectibleCount);
        }
    }
}

void update_character_position(struct state *game_state)
{
    int mapX = game_state->animation.characters[0].x / game_state->tileWH;
    int mapY = game_state->animation.characters[0].y / game_state->tileWH;
    int mapModX = game_state->animation.characters[0].x % game_state->tileWH;
    int mapModY = game_state->animation.characters[0].y % game_state->tileWH;
    char a, b;

    if (game_state->keys.up)
    {
        a = game_state->map[mapY - 1][mapX];
        b = game_state->map[mapY - 1][mapX + (mapModX > 0)];

        if(mapModY >= MOVE_SPEED || (a != '1' && b != '1'))
            game_state->animation.characters[0].y -= MOVE_SPEED;
        
        // if (mapModY <= MOVE_SPEED && (a == 'C' || b == 'C'))
        // {
        //     game_state->map[mapY - 1][mapX + (mapModX > 0)] = '0';
        //     game_state->collected++;
        //     ft_printf("Collected: %d\n", game_state->collected);
        // }
    }
    if (game_state->keys.down)
    {
        a = game_state->map[mapY + 1][mapX];
        b = game_state->map[mapY + 1][mapX + (mapModX > 0)];

        if(a != '1' && b != '1')
            game_state->animation.characters[0].y += MOVE_SPEED;

        // if(a == 'C' || b == 'C')
        // {
        //     game_state->map[mapY + 1][mapX + (mapModX > 0)] = '0';
        //     game_state->collected++;
        //     ft_printf("Collected: %d\n", game_state->collected);
        // }
    }
    if (game_state->keys.left)
    {
        if(mapModX >= MOVE_SPEED || (game_state->map[mapY][mapX - 1] != '1' && game_state->map[mapY + (mapModY > 0)][mapX - 1] != '1'))
            game_state->animation.characters[0].x -= MOVE_SPEED;
    }
    if (game_state->keys.right)
    {
        if(game_state->map[mapY][mapX + 1] != '1' && game_state->map[mapY + (mapModY > 0)][mapX + 1] != '1')
            game_state->animation.characters[0].x += MOVE_SPEED;
    }

    return;
}
