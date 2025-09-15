#include "headers/mapLoader.h"

void free_map(char** map)
{
    char** tmp = map;

    if (!map)
        return;

    while (*map)
    {
        free(*map);
        map++;
    }
    free(tmp);
}

int validateMap(char* buffer, struct mapStats* stats)
{
    int firstLineLength = 0;  // Length of the first line to compare against
    int currentLineLength = 0; // Length of the current line being processed
    int wallCount = 0;        // Count of wall characters in current line
    int height = 0;           // Total number of lines (height of the map)
    int playerCount = 0;
    int exitCount = 0;
    int collectibleCount = 0;
    struct posList* lastCollectible = NULL;
    struct posList* newCollectible = NULL;
    int hasClosedPlayableArea = 0;
    int i = 0;
    
    if (!buffer)
    {
        ft_printf(RED"Error\n%s\n"RESET, "Null map data pointer");
        return 0;
    }

    while(buffer[i] == '\n')
        i++;

    // First pass: Calculate the length of the first line
    while (buffer[i] && buffer[i] != '\n')
    {
        if (buffer[i] != '1') // First line should be all walls
        {
            ft_printf(RED"Error\n%s\n"RESET, "Map must be enclosed by walls");
            return 0;
        }
        firstLineLength++;
        i++;
    }
    
    // Skip the newline character
    if (buffer[i] == '\n')
    {
        height++;
        i++;
    }
    
    // Continue validating the rest of the map
    while (buffer[i])
    {
        if (buffer[i] != '\n')
        {
            hasClosedPlayableArea = 0; // Reset for each new line
            // Start of a new line
            currentLineLength = 0;
            wallCount = 0;
            
            // First character of each line must be a wall
            if (buffer[i] != '1')
            {
                ft_printf(RED"Error\n%s\n"RESET, "Walls must enclose the map (left side)");
                return 0;
            }
            wallCount++;
            currentLineLength++;
            i++;

            // Process the middle of the current line
            while (buffer[i] && buffer[i] != '\n')
            {
                // Validate character
                if (buffer[i] != '1' && buffer[i] != '0' && buffer[i] != 'C' && 
                    buffer[i] != 'E' && buffer[i] != 'P' && buffer[i] != 'V')
                {
                    ft_printf(RED"Error\n%s\n"RESET, "Invalid character in map");
                    return 0;
                }

                if (buffer[i] == '1')
                    wallCount++;
                else if (buffer[i] == 'P')
                {
                    playerCount++;
                    stats->playerX = currentLineLength;
                    stats->playerY = height;
                }
                else if (buffer[i] == 'E')
                {
                    exitCount++;
                    stats->exitX = currentLineLength;
                    stats->exitY = height;
                }
                else if (buffer[i] == 'V')
                {
                    stats->villainX = currentLineLength;
                    stats->villainY = height;
                }
                else if (buffer[i] == 'C')
                {
                    collectibleCount++;
                    newCollectible = (struct posList*)malloc(sizeof(struct posList));
                    if (!newCollectible)
                    {
                        perror("Failed to allocate memory for collectible position");
                        return 0;
                    }

                    newCollectible->x = currentLineLength;
                    newCollectible->y = height;
                    newCollectible->next = NULL;

                    // Add to the collectibles list
                    if (!stats->collectibles)
                        stats->collectibles = newCollectible;
                    else
                        lastCollectible->next = newCollectible;
                    lastCollectible = newCollectible;
                }

                currentLineLength++;
                i++;
            }
            height++;

            // Verify the line length matches the first line
            if (currentLineLength && currentLineLength != firstLineLength)
            {
                ft_printf(RED"Error\n%s\n"RESET, "Map must be rectangular");
                ft_printf(GRN"Expected length: %d, Got: %d\n"RESET, firstLineLength, currentLineLength);
                return 0;
            }

            // Last character of the line should be a wall
            if (buffer[i-1] != '1')
            {
                ft_printf(RED"Error\n%s\n"RESET, "Walls must enclose the map (right side)");
                return 0;
            }

            if (playerCount > 1)
            {
                ft_printf(RED"Error\n%s\n"RESET, "Map must contain exactly one player start position");
                return 0;
            }

            if (exitCount > 1)
            {
                ft_printf(RED"Error\n%s\n"RESET, "Map must contain exactly one exit");
                return 0;
            }

            // Check if this is the last line (all walls)
            if (wallCount == firstLineLength && playerCount == 1 && exitCount == 1 && collectibleCount)
            {
                hasClosedPlayableArea = 1; // Valid map
            }
        }
        else if (!hasClosedPlayableArea)
        {
            ft_printf(RED"Error\n%s\n"RESET, "Map must have a closed playable area");
            return 0;
        }
        
        if (buffer[i] == '\n')
            i++;
    }

    stats->width = firstLineLength;
    stats->height = height;
    stats->collectibleCount = collectibleCount;

    if (!hasClosedPlayableArea)
    {
        ft_printf(RED"Error\n%s\n"RESET, "Incomplete map");
    }
    return hasClosedPlayableArea;
}

char** loadMap(const char* filename, struct mapStats* stats)
{
    int fd;
    long totalRead = 0;
    char* mapStr;
    char* trimmedMapStr;
    char** mapArr;
    char buffer[1024];
    ssize_t bytesRead;

    fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
        perror(RED"Error\n%s\n"RESET);
		return NULL;
	}

    bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    while(bytesRead)
    {
        totalRead += bytesRead;
        bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    }
    close(fd);

    mapStr = (char*)malloc(totalRead + 1);
    if (!mapStr)
    {
        perror("Failed to allocate memory for map");
        return NULL;
    }

    fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
        perror(RED"Error\n%s\n"RESET);
        free(mapStr);
		return NULL;
	}

    bytesRead = read(fd, mapStr, totalRead);
    mapStr[totalRead] = '\0';
    close(fd);

    if (!validateMap(mapStr, stats))
    {
        free(mapStr);
        return NULL;
    }

    trimmedMapStr = ft_strtrim(mapStr, "\n");
    free(mapStr);
    if (!trimmedMapStr)
    {
        ft_printf(RED"Error\n%s\n"RESET, "Failed to trim map string");
        return NULL;
    }

    mapArr = ft_split(trimmedMapStr, '\n');
    free(trimmedMapStr);
    if (!mapArr)
    {
        ft_printf(RED"Error\n%s\n"RESET, "Failed to split map string into array");
        return NULL;
    }

    if (!isCompletable(mapArr, stats))
    {
        ft_printf(RED"Error\n%s\n"RESET, "No valid completion path in map");
        free_map(mapArr);
        return NULL;
    }

    return mapArr;
}
