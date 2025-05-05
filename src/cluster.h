#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#define MAX_CLUSTER_LENGTH 5

#include <stddef.h>

typedef struct { 
    char arr [MAX_CLUSTER_LENGTH];
} Cluster;

typedef struct {
    Cluster *clusters;
    size_t n;
} ClusterList;

ClusterList *createClusterList(char *str);
void freeClusterList(ClusterList * clusterlist);

#endif
