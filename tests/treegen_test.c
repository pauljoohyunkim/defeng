#include <stdlib.h>
#include "../src/common.h"
#include "../src/tree.h"

int main()
{
    DefEngTreeNode nodes[] = { NULL, NULL, NULL, NULL, NULL};
    nodes[0] = createTree(NULL, 0, VOWEL);
    nodes[1] = createTree(NULL, 1, CONSONANT);
    nodes[2] = createTree(NULL, 2, CONSONANT);

    return 0;
}