#include <stdlib.h>
#include "../src/common.h"
#include "../src/tree.h"

int main()
{
    DefEngTreeNode nodes[] = { NULL, NULL, NULL, NULL, NULL};
    nodes[0] = createTree(NULL, 0, VOWEL);
    nodes[1] = createTree(NULL, 1, CONSONANT_FORMER);
    nodes[2] = createTree(NULL, 2, CONSONANT_LATTER);

    freeTree(nodes[0]);
    freeTree(nodes[1]);
    freeTree(nodes[2]);

    return 0;
}