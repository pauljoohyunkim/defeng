#include <stdio.h>
#include "../src/tree.h"
#include "../src/cluster.h"
#include "../src/generator.h"

int main()
{
    size_t nc = 0;
    Cluster *cs = createClusterList("../data/c.txt", &nc);
    size_t nv = 0;
    Cluster *vs = createClusterList("../data/v.txt", &nv);

    // Tree Generation
    DefEngTreeNode node = createTree(NULL, 0, CONSONANT);
    generate(node, cs, nc, vs, nv, stdout, NULL, 0);

    freeClusters(cs);
    freeClusters(vs);
}
