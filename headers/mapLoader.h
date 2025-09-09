#ifndef MAP_LOADER_H
#define MAP_LOADER_H

// #include <stdio.h>
#include "colors.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include <string.h> // For strerror

struct mapStats
{
    int width;
    int height;
    int playerCount;
    int collectibleCount;
};

char** loadMap(const char* filename, struct mapStats* stats);

#endif
