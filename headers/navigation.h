#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "game_data.h"
#include <math.h>
#include <float.h>
#include <stdio.h>

struct node
{
    int x, y, parent_x, parent_y, closed;
    double f, g, h;
};

int aStarAlgo(int destX, int destY, int startX, int startY, char** map, struct mapStats* stats);
int manhattanDistance(int x1, int y1, int x2, int y2);
int isCompletable(char** map, struct mapStats* stats);

#endif
