#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#define MAX_CLUSTER_LENGTH 4

typedef struct { char arr [MAX_CLUSTER_LENGTH]; } Cluster;

Cluster *createClusterList(char *str, size_t* pNItems);

#endif
