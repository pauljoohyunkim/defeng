#include <stdio.h>
#include "../src/tree.h"
#include "../src/cluster.h"
#include "../src/generator.h"

int main()
{
    ClusterList *cs = createClusterList("../data/c.txt");
    ClusterList *vs = createClusterList("../data/v.txt");

    // Tree Generation
    DefEngTreeNode node = createTree(NULL, 2, CONSONANT_FORMER);
    generate(node, cs, cs, vs, stdout, NULL);

    freeTree(node);
    freeClusterList(cs);
    freeClusterList(vs);
}
