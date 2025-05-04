#include <stdlib.h>
#include <string.h>
#include "generator.h"
#include "tree.h"

// Set prefix = NULL, length = 0 when calling.
void generate(DefEngTreeNode node, Cluster *consonant_clusters, size_t nConsonants, Cluster *vowel_clusters, size_t nVowels, FILE *fp, Cluster *prefix, size_t nSpace)
{
    if (prefix == NULL)
    {
        nSpace = node->depth + 2;
        prefix = (Cluster *) calloc(nSpace, sizeof(Cluster));
    }

    if (node->depth == 0)
    {
        if (node->space_type == CONSONANT)
        {
            for (size_t i = 0; i < nConsonants; i++)
            {
                strcpy(prefix[nSpace - node->depth - 2].arr, consonant_clusters[i].arr);
                // TODO: Output!!!!!!!!!!!!!!
                for (size_t j = 0; j < nSpace - node->depth - 1; j++)
                {
                    fprintf(fp, "%s\n", prefix[nSpace - j - 2].arr);
                }
            }
        }
        else
        {
            for (size_t i = 0; i < nVowels; i++)
            {
                strcpy(prefix[nSpace - node->depth - 2].arr, vowel_clusters[i].arr);
                // TODO: Output!!!!!!!!!!!!!!
            }

        }
    }
}
