#include "../src/common.h"
#include "../src/tree.h"

int main()
{
    size_t n_consonants = 2;
    size_t n_vowels = 3;
    DefEngTreeNode node = NULL;
    size_t outputSize = 0;

    node = createTree(NULL, 2, VOWEL);
    outputSizeTree(node, n_consonants, n_vowels, &outputSize, 1);

    return 0;
}
