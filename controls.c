#include "headers/controls.h"

// int key_hook(int keycode, void *param)
// {
//     struct state *game_state = (struct state *)param;
//     if (keycode == ESC_KEY)
//     {
//         ft_printf("Escape key pressed\n");
//         exit_func(game_state);
//     }
//     if (keycode == W_KEY || keycode == ARROW_UP_KEY)
//     {
//         ft_printf("W/UP key pressed\n");
//         game_state->characters[0].y -= 10; // Move up by 10 pixels
//         game_state->characters[0].state = STATE_WALK; // Change state to walking
//     }
//     if (keycode == A_KEY || keycode == ARROW_SX_KEY)
//     {
//         ft_printf("A/LEFT key pressed\n");
//         game_state->characters[0].x -= 10; // Move left by 10 pixels
//         game_state->characters[0].state = STATE_WALK; // Change state to walking
//     }
//     if (keycode == S_KEY || keycode == ARROW_DOWN_KEY)
//     {
//         ft_printf("S/DOWN key pressed\n");
//         game_state->characters[0].y += 10; // Move down by 10 pixels
//         game_state->characters[0].state = STATE_WALK; // Change state to walking
//     }
//     if (keycode == D_KEY || keycode == ARROW_DX_KEY)
//     {
//         ft_printf("D/RIGHT key pressed\n");
//         game_state->characters[0].x += 10; // Move right by 10 pixels
//         game_state->characters[0].state = STATE_WALK; // Change state to walking
//     }
//     return 0;
// }

int key_press_hook(int keycode, struct key_states *keys)
{
    // if (keycode == W_KEY || keycode == ARROW_UP_KEY ||
    //     keycode == A_KEY || keycode == ARROW_SX_KEY ||
    //     keycode == S_KEY || keycode == ARROW_DOWN_KEY ||
    //     keycode == D_KEY || keycode == ARROW_DX_KEY)
    // {
    //     game_state->characters[0].state = STATE_WALK;
    // }
    if (keycode == W_KEY || keycode == ARROW_UP_KEY)
    {
        // ft_printf("W/UP key pressed\n");
        keys->up = 1;
    }
    if (keycode == A_KEY || keycode == ARROW_SX_KEY)
    {
        // ft_printf("A/LEFT key pressed\n");
        keys->left = 1;
    }
    if (keycode == S_KEY || keycode == ARROW_DOWN_KEY)
    {
        // ft_printf("S/DOWN key pressed\n");
        keys->down = 1;
    }
    if (keycode == D_KEY || keycode == ARROW_DX_KEY)
    {
        // ft_printf("D/RIGHT key pressed\n");
        keys->right = 1;
    }
    if (keycode == ESC_KEY)
    {
        keys->escRelease = 0;
    }

    // screen_refresh(game_state);
    return 0;
}

int key_release_hook(int keycode, struct key_states *keys)
{
    if (keycode == ESC_KEY)
    {
        keys->escRelease = 1;
    }
    if (keycode == W_KEY || keycode == ARROW_UP_KEY)
    {
        // ft_printf("W/UP key pressed\n");
        keys->up = 0;
    }
    if (keycode == A_KEY || keycode == ARROW_SX_KEY)
    {
        // ft_printf("A/LEFT key pressed\n");
        keys->left = 0;
    }
    if (keycode == S_KEY || keycode == ARROW_DOWN_KEY)
    {
        // ft_printf("S/DOWN key pressed\n");
        keys->down = 0;
    }
    if (keycode == D_KEY || keycode == ARROW_DX_KEY)
    {
        // ft_printf("D/RIGHT key pressed\n");
        keys->right = 0;
    }
    return 0;
}

int mouse_hook(int button, int x, int y, void *param)
{
    (void)param;    // Unused parameter

    printf("Mouse button %d pressed at (%d, %d)\n", button, x, y);
    return 0;
}
