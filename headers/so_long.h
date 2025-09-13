#ifndef SO_LONG_H
#define SO_LONG_H

#include "game_data.h"
#include "keyCodes.h"
#include "mapLoader.h"
#include "animation.h"
#include "controls.h"
#include "movement.h"
#include "../minilibx_mms_20200219/mlx.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

#define GAME_RES_X 800
#define GAME_RES_Y 600

int exit_func(void* param);
int screen_refresh(void *param);

#endif
