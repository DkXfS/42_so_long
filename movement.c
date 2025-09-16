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
        game_state->collected++;
        ft_printf("Collected: %d\n", game_state->collected);
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
            ft_printf(GRN"Level Completed!"RESET"\n Moves: %d\n", game_state->moveCount/2);
            exit_func(game_state);
        }
    }

    int enemyX1 = game_state->animation.characters[1].x;
    int enemyY1 = game_state->animation.characters[1].y;
    int enemyX2 = (game_state->animation.characters[1].x + game_state->tileWH);
    int enemyY2 = (game_state->animation.characters[1].y + game_state->tileWH);
    x1 = game_state->animation.characters[0].x;
    y1 = game_state->animation.characters[0].y;
    x2 = (game_state->animation.characters[0].x + game_state->tileWH);
    y2 = (game_state->animation.characters[0].y + game_state->tileWH);

    if (x2 > enemyX1 && enemyX2 > x1 && y2 > enemyY1 && enemyY2 > y1)
    {
        ft_printf(RED"Game Over!\n"RESET"Caught by the enemy!\n");
        printf("Player 1(%d, %d), 2(%d, %d)\n", x1, y1, x2, y2);
        printf("Enemy 1(%d, %d), 2(%d, %d)\n", enemyX1, enemyY1, enemyX2, enemyY2);
        exit_func(game_state);
    }
}

void update_character_position(struct state *game_state, int mult)
{
    int mapX = game_state->animation.characters[0].x / game_state->tileWH;
    int mapY = game_state->animation.characters[0].y / game_state->tileWH;
    int mapModX = game_state->animation.characters[0].x % game_state->tileWH;
    int mapModY = game_state->animation.characters[0].y % game_state->tileWH;
    char a, b;

    ft_printf("mapX: %d", mapX);
    ft_printf(", mapY: %d\n", mapY);
    while (mult--)
    {
        if (game_state->keys.up)
        {
            a = game_state->map[mapY - 1][mapX];
            b = game_state->map[mapY - 1][mapX + (mapModX > 0)];
            game_state->animation.characters[0].direction = ANIM_UP;
            game_state->animation.characters[0].state = STATE_WALK;
        
            if(mapModY >= MOVE_SPEED || (a != '1' && b != '1'))
            {
                game_state->animation.characters[0].y -= MOVE_SPEED;
                game_state->moveCount++;
                mapY = game_state->animation.characters[0].y / game_state->tileWH;
                mapModY = game_state->animation.characters[0].y % game_state->tileWH;
            }
        }
        if (game_state->keys.down)
        {
            a = game_state->map[mapY + 1][mapX];
            b = game_state->map[mapY + 1][mapX + (mapModX > 0)];
            game_state->animation.characters[0].direction = ANIM_DOWN;
            game_state->animation.characters[0].state = STATE_WALK;
        
            if(a != '1' && b != '1') // && mapModY < (game_state->tileWH - MOVE_SPEED)
            {
                game_state->animation.characters[0].y += MOVE_SPEED;
                game_state->moveCount++;
                mapY = game_state->animation.characters[0].y / game_state->tileWH;
                mapModY = game_state->animation.characters[0].y % game_state->tileWH;
            }
        }
        if (game_state->keys.left)
        {
            game_state->animation.characters[0].direction = ANIM_LEFT;
            game_state->animation.characters[0].state = STATE_WALK;
            a = game_state->map[mapY][mapX - 1];
            b = game_state->map[mapY + (mapModY > 0)][mapX - 1];
        
            if(mapModX >= MOVE_SPEED || (a != '1' && b != '1'))
            {
                game_state->animation.characters[0].x -= MOVE_SPEED;
                game_state->moveCount++;
                mapX = game_state->animation.characters[0].x / game_state->tileWH;
                mapModX = game_state->animation.characters[0].x % game_state->tileWH;
            }
        }
        if (game_state->keys.right)
        {
            game_state->animation.characters[0].direction = ANIM_RIGHT;
            game_state->animation.characters[0].state = STATE_WALK;
            a = game_state->map[mapY][mapX + 1];
            b = game_state->map[mapY + (mapModY > 0)][mapX + 1];
        
            if(a != '1' && b != '1') // && mapModX < (game_state->tileWH - MOVE_SPEED)
            {
                game_state->animation.characters[0].x += MOVE_SPEED;
                game_state->moveCount++;
                mapX = game_state->animation.characters[0].x / game_state->tileWH;
                mapModX = game_state->animation.characters[0].x % game_state->tileWH;
            }
        }
    }

    return;
}

void update_enemy_position(struct state *game_state, int mult)
{
    int enemyX = game_state->animation.characters[1].x / game_state->tileWH;
    int enemyY = game_state->animation.characters[1].y / game_state->tileWH;
    int enemyModX = game_state->animation.characters[1].x % game_state->tileWH;
    int enemyModY = game_state->animation.characters[1].y % game_state->tileWH;
    int playerX = game_state->animation.characters[0].x / game_state->tileWH;
    int playerY = game_state->animation.characters[0].y / game_state->tileWH;

    // enemyX += (enemyModX >= MOVE_SPEED);
    // enemyY += (enemyModY >= MOVE_SPEED);
    int tempEnemyX = enemyX;
    int tempEnemyY = enemyY;
    if (enemyX > playerX)
        tempEnemyX += (enemyModX >= MOVE_SPEED);

    if (enemyY > playerY)
        tempEnemyY += (enemyModY >= MOVE_SPEED);

    printf("enemyX: %d, enemyY: %d, tempEnemyX: %d, tempEnemyY: %d\n", enemyX, enemyY, tempEnemyX, tempEnemyY);

    struct posList* path = NULL;
    aStarAlgo(playerX, playerY, tempEnemyX, tempEnemyY, game_state->map, &game_state->stats, &path);
    printf("Calculated path from (%d, %d) to (%d, %d)\n", tempEnemyX, tempEnemyY, playerX, playerY);
    struct posList* temp = path;
    if (temp && temp->next)
    {
        temp = temp->next;
        printf("Enemy at (%d, %d)\n", enemyX, enemyY);
        printf("Enemy moving to (%d, %d)\n", temp->x, temp->y);

        if (temp->x > enemyX)
        {
            if (game_state->map[enemyY][enemyX + 1] != '1' && game_state->map[enemyY + (enemyModY > 0)][enemyX + 1] != '1')
            {
                game_state->animation.characters[1].x += MOVE_SPEED * mult;
                game_state->animation.characters[1].direction = ANIM_RIGHT;
                game_state->animation.characters[1].state = STATE_WALK;
            }
        }
        if (temp->x < enemyX || (temp->x == enemyX && enemyModX >= MOVE_SPEED))
        {
            if (game_state->map[enemyY][enemyX - 1] != '1' && game_state->map[enemyY + (enemyModY > 0)][enemyX - 1] != '1')
            {
                game_state->animation.characters[1].x -= MOVE_SPEED * mult;
                game_state->animation.characters[1].direction = ANIM_LEFT;
                game_state->animation.characters[1].state = STATE_WALK;
            }
        }
        if (temp->y > enemyY)
        {
            if (game_state->map[enemyY + 1][enemyX] != '1' && game_state->map[enemyY + 1][enemyX + (enemyModX > 0)] != '1')
            {
                game_state->animation.characters[1].y += MOVE_SPEED * mult;
                game_state->animation.characters[1].direction = ANIM_DOWN;
                game_state->animation.characters[1].state = STATE_WALK;
            }
        }
        if (temp->y < enemyY || (temp->y == enemyY && enemyModY >= MOVE_SPEED))
        {
            if (game_state->map[enemyY - 1][enemyX] != '1' && game_state->map[enemyY - 1][enemyX + (enemyModX > 0)] != '1')
            {
                game_state->animation.characters[1].y -= MOVE_SPEED * mult;
                game_state->animation.characters[1].direction = ANIM_UP;
                game_state->animation.characters[1].state = STATE_WALK;
            }
        }
    }
    else
    {
        game_state->animation.characters[1].state = STATE_IDLE;
        game_state->animation.characters[1].curr_frame = 0;
    }
    
    if (path)
        free_pos_list(path);

    // if (enemyX < playerX)
    // {
    //     if (game_state->map[enemyY][enemyX + 1] != '1')
    //     {
    //         game_state->animation.characters[1].x += MOVE_SPEED;
    //         game_state->animation.characters[1].direction = ANIM_RIGHT;
    //         game_state->animation.characters[1].state = STATE_WALK;
    //     }
    // }
    // else if (enemyX > playerX)
    // {
    //     if (game_state->map[enemyY][enemyX - 1] != '1')
    //     {
    //         game_state->animation.characters[1].x -= MOVE_SPEED;
    //         game_state->animation.characters[1].direction = ANIM_LEFT;
    //         game_state->animation.characters[1].state = STATE_WALK;
    //     }
    // }
    // else if (enemyY < playerY)
    // {
    //     if (game_state->map[enemyY + 1][enemyX] != '1')
    //     {
    //         game_state->animation.characters[1].y += MOVE_SPEED;
    //         game_state->animation.characters[1].direction = ANIM_DOWN;
    //         game_state->animation.characters[1].state = STATE_WALK;
    //     }
    // }
    // else if (enemyY > playerY)
    // {
    //     if (game_state->map[enemyY - 1][enemyX] != '1')
    //     {
    //         game_state->animation.characters[1].y -= MOVE_SPEED;
    //         game_state->animation.characters[1].direction = ANIM_UP;
    //         game_state->animation.characters[1].state = STATE_WALK;
    //     }
    // }
    // else
    // {
    //     game_state->animation.characters[1].state = STATE_IDLE;
    //     game_state->animation.characters[1].curr_frame = 0;
    // }
}

void update_positions(struct state *game_state)
{
    int updates = time_diff_usec(&game_state->current_time, &game_state->last_movement_time) / 16666; // Approx frametime of 60 FPS
    if (updates > 0)
    {
        game_state->last_movement_time.tv_sec = game_state->current_time.tv_sec;
        game_state->last_movement_time.tv_usec = game_state->current_time.tv_usec;
        
        update_character_position(game_state, updates);
        update_enemy_position(game_state, updates);
        check_collisions(game_state);
    }
}
