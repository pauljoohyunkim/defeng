#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "cluster.h"

// Counts lines. Only call when the file is freshly opened.
static size_t countLines(FILE *fp)
{
    size_t n = 0;
    char buffer[BUFSIZ] = { 0 };

    if (fp == NULL)
    {
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        n++;
    }

    // File pointer to start.
    fseek(fp, 0, SEEK_SET);
    
    return n;
}

Cluster *createClusterList(char *str, size_t* pNItems)
{
    Cluster *clusters = NULL;
    FILE * fp = NULL;
    size_t nLines = 0;

    fp = fopen(str, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    nLines = countLines(fp);

    // Create cluster list.
    clusters = calloc(nLines, sizeof(Cluster)); 
    for (size_t i = 0; i < nLines; i++)
    {
        fgets(clusters[i].arr, MAX_CLUSTER_LENGTH, fp);
        clusters[i].arr[strcspn(clusters[i].arr, "\r\n")] = 0;  // Get rid of trailing newline.
    }

    fclose(fp);

    if (pNItems != NULL)
    {
        *pNItems = nLines;
    }
    return clusters;
}
