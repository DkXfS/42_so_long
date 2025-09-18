#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include "game_data.h"
#include "navigation.h"
#include "colors.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char** loadMap(const char* filename, struct mapStats* stats);
void free_map(char** map);

#endif
