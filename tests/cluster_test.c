#include <stdio.h>
#include "../src/cluster.h"

int main()
{
    size_t n = 0;

    Cluster* clusters = createClusterList("../data/c.txt", &n);

    return 0;
}
