#include "headers/controls.h"

int key_press_hook(int keycode, struct state *game_state)
{
    if (keycode == W_KEY || keycode == ARROW_UP_KEY)
    {
        // ft_printf("W/UP key pressed\n");
        game_state->keys.up = 1;
    }
    if (keycode == A_KEY || keycode == ARROW_SX_KEY)
    {
        // ft_printf("A/LEFT key pressed\n");
        game_state->keys.left = 1;
    }
    if (keycode == S_KEY || keycode == ARROW_DOWN_KEY)
    {
        // ft_printf("S/DOWN key pressed\n");
        game_state->keys.down = 1;
    }
    if (keycode == D_KEY || keycode == ARROW_DX_KEY)
    {
        // ft_printf("D/RIGHT key pressed\n");
        game_state->keys.right = 1;
    }
    if (keycode == ESC_KEY)
    {
        game_state->keys.escRelease = 0;
    }

    return 0;
}

int key_release_hook(int keycode, struct state *game_state)
{
    if (keycode == ESC_KEY)
    {
        game_state->keys.escRelease = 1;
    }
    if (keycode == W_KEY || keycode == ARROW_UP_KEY)
    {
        // ft_printf("W/UP key pressed\n");
        game_state->animation.characters[0].state = STATE_IDLE;
        game_state->animation.characters[0].curr_frame = 0;
        game_state->keys.up = 0;
    }
    if (keycode == A_KEY || keycode == ARROW_SX_KEY)
    {
        // ft_printf("A/LEFT key pressed\n");
        game_state->animation.characters[0].state = STATE_IDLE;
        game_state->animation.characters[0].curr_frame = 0;
        game_state->keys.left = 0;
    }
    if (keycode == S_KEY || keycode == ARROW_DOWN_KEY)
    {
        // ft_printf("S/DOWN key pressed\n");
        game_state->animation.characters[0].state = STATE_IDLE;
        game_state->animation.characters[0].curr_frame = 0;
        game_state->keys.down = 0;
    }
    if (keycode == D_KEY || keycode == ARROW_DX_KEY)
    {
        // ft_printf("D/RIGHT key pressed\n");
        game_state->animation.characters[0].state = STATE_IDLE;
        game_state->animation.characters[0].curr_frame = 0;
        game_state->keys.right = 0;
    }
    return 0;
}
