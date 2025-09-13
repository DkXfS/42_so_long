#include "headers/navigation.h"

// int findShortestCompletionLength(char** map, struct mapStats* stats)
// {
//     int totalLength = 0;
//     int coveredIdx[stats->collectibleCount];
//     int coveredCount = 0;
//     int manhattanDistances[stats->collectibleCount];
//     int lastIdx = -1;
//     struct posList* collectiblePtrs[stats->collectibleCount];

//     int i = 0;
//     while (i < stats->collectibleCount)
//     {
//         coveredIdx[i] = 0;
//         if (!i)
//             collectiblePtrs[i] = stats->collectibles;
//         else
//             collectiblePtrs[i] = collectiblePtrs[i - 1]->next;
//         manhattanDistances[i] = manhattanDistance(stats->playerX, stats->playerY, collectiblePtrs[i]->x, collectiblePtrs[i]->y);
//         i++;
//     }

//     while (coveredCount < stats->collectibleCount)
//     {
//         int i = 0;
//         while (i < stats->collectibleCount)
//         {
//             if (lastIdx == -1
//         }
//         int minManhattan = INT8_MAX;
//         int partialLength = aStarAlgo(stats->exitX, stats->exitY, stats->playerX, stats->playerY, map, stats);
//         if (partialLength == -1)
//             return partialLength;
//         totalLength += partialLength;
//         coveredCount++;
//     }

//     return totalLength;
// }

int isCompletable(char** map, struct mapStats* stats)
{
    struct posList* currentCollectible = stats->collectibles;
    while (currentCollectible)
    {
        int partialLength = aStarAlgo(currentCollectible->x, currentCollectible->y, stats->playerX, stats->playerY, map, stats);
        if (partialLength == -1)
            return 0;
        currentCollectible = currentCollectible->next;
    }
    int exitLength = aStarAlgo(stats->exitX, stats->exitY, stats->playerX, stats->playerY, map, stats);
    if (exitLength == -1)
        return 0;
    return 1;
}

int manhattanDistance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int isNavigable(int x, int y, char** map, struct mapStats* stats)
{
    // if (x < 0 || x >= stats->width || y < 0 || y >= stats->height)
    //     return 0;
    // if (map[y][x] == '1')
    //     return 0;
    // return 1;

    return (x >= 0 && x < stats->width && y > 0 && y < stats->height && map[y][x] != '1');
}

void printPath(int height, int width, struct node nodes[height][width], int destX, int destY)
{
    if (nodes[destY][destX].parent_x == destX && nodes[destY][destX].parent_y == destY)
    {
        printf("(%d, %d) -> ", destX, destY);
        return;
    }
    printPath(height, width, nodes, nodes[destY][destX].parent_x, nodes[destY][destX].parent_y);
    printf("(%d, %d) -> ", destX, destY);
}

int aStarAlgo(int destX, int destY, int startX, int startY, char** map, struct mapStats* stats)
{
    int steps = 0;
    int openListSize = 0;
    struct node* openList[stats->width * stats->height];
    struct node nodes[stats->height][stats->width];
    struct node* currentNode;
    int explorableRows[] = {-1, 0, 1, 0};
    int explorableCols[] = {0, -1, 0, 1};

    int i = 0;
    while (i < stats->height)
    {
        int j = 0;
        while (j < stats->width)
        {
            nodes[i][j].x = j;
            nodes[i][j].y = i;
            nodes[i][j].parent_x = -1;
            nodes[i][j].parent_y = -1;
            nodes[i][j].closed = 0;
            nodes[i][j].f = DBL_MAX;
            nodes[i][j].g = DBL_MAX;
            nodes[i][j].h = DBL_MAX;
            openList[i * stats->width + j] = NULL;
            j++;
        }
        i++;
    }

    openList[openListSize++] = &nodes[startY][startX];
    nodes[startY][startX].f = 0.0;
    nodes[startY][startX].g = 0.0;
    nodes[startY][startX].h = 0.0;
    nodes[startY][startX].parent_x = startX;
    nodes[startY][startX].parent_y = startY;
    
    while (openListSize > 0)
    {
        double minF = DBL_MAX;
        int currentOpenIndex = -1;

        i = 0;
        while (i < openListSize)
        {
            if (openList[i]->f < minF)
            {
                minF = openList[i]->f;
                currentOpenIndex = i;
            }
            i++;
        }

        currentNode = openList[currentOpenIndex];
        currentNode->closed = 1;
        openList[currentOpenIndex] = openList[--openListSize];

        // printf("Processing node (%d,%d) with f=%.2f\n", currentNode->x, currentNode->y, currentNode->f);

        i = 0;
        while (i < 4)
        {
            int nextX = currentNode->x + explorableRows[i];
            int nextY = currentNode->y + explorableCols[i];

            if (isNavigable(nextX, nextY, map, stats))
            {
                if (nextX == destX && nextY == destY)
                {
                    nodes[nextY][nextX].parent_x = currentNode->x;
                    nodes[nextY][nextX].parent_y = currentNode->y;
                    // printf("Path:\n");
                    // printPath(stats->height, stats->width, nodes, destX, destY);
                    steps = 1;
                    return steps;
                }
                else if (!nodes[nextY][nextX].closed)
                {
                    // printf("  Considering node (%d,%d)\n", nextX, nextY);
                    double newG = currentNode->g + 1.0;
                    double newH = manhattanDistance(nextX, nextY, destX, destY);
                    double newF = newG + newH;

                    if (nodes[nextY][nextX].f > newF)
                    {
                        openList[openListSize++] = &nodes[nextY][nextX];
                        nodes[nextY][nextX].f = newF;
                        nodes[nextY][nextX].g = newG;
                        nodes[nextY][nextX].h = newH;
                        nodes[nextY][nextX].parent_x = currentNode->x;
                        nodes[nextY][nextX].parent_y = currentNode->y;
                    }
                }
            }
            i++;
        }
    }
    return -1;
}
