#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "cluster.h"

// Counts lines. Only call when the file is freshly opened.
static size_t nLines(FILE *fp)
{
    size_t n = 0;
    char buffer[BUFSIZ] = { 0 };
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        n++;
    }
    
    return n;
}

char **createClusterList(FILE *str)
{
    return NULL;
}
