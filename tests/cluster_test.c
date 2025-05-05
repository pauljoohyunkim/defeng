#include <stdio.h>
#include "../src/cluster.h"

int main()
{
    size_t n = 0;

    ClusterList* clusterlist = createClusterList("../data/c.txt");

    freeClusterList(clusterlist);

    return 0;
}
