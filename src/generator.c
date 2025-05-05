#include <stdlib.h>
#include <string.h>
#include "generator.h"
#include "tree.h"

// Set prefix = NULL when calling.
void generate(DefEngTreeNode node, Cluster *consonant_clusters, size_t nConsonants, Cluster *vowel_clusters, size_t nVowels, FILE *fp, Cluster *prefix)
{
    if (prefix == NULL)
    {
        size_t nSpace = node->depth + 1;
        prefix = (Cluster *) calloc(nSpace, sizeof(Cluster));
    }

    // When node depth is zero, output to console.
    // Otherwise, only set the prefix.
    if (node->depth == 0)
    {
        if (node->space_type == CONSONANT)
        {
            for (size_t j = 0; j < nConsonants; j++)
            {
                strcpy(prefix[node->root->depth].arr, consonant_clusters[j].arr);
                for (size_t i = 0; i < node->root->depth; i++)
                {
                    fprintf(fp, "%s", prefix[i].arr);
                }
                fprintf(fp, "%s\n", prefix[node->root->depth].arr);
            }
        }
        else
        {
            for (size_t j = 0; j < nVowels; j++)
            {
                strcpy(prefix[node->root->depth].arr, vowel_clusters[j].arr);
                for (size_t i = 0; i < node->root->depth; i++)
                {
                    fprintf(fp, "%s", prefix[i].arr);
                }
                fprintf(fp, "%s\n", prefix[node->root->depth].arr);
            }
        }
    }
    else
    {
        // TODO: recursive
        if (node->space_type == CONSONANT)
        {
            for (size_t j = 0; j < nConsonants; j++)
            {
                strcpy(prefix[node->root->depth - node->depth].arr, consonant_clusters[j].arr);
                generate(node->children[0], consonant_clusters, nConsonants, vowel_clusters, nVowels, fp, prefix);
                generate(node->children[1], consonant_clusters, nConsonants, vowel_clusters, nVowels, fp, prefix);
            }
        }
        else
        {
            for (size_t j = 0; j < nVowels; j++)
            {
                strcpy(prefix[node->root->depth - node->depth].arr, vowel_clusters[j].arr);
                generate(node->children[0], consonant_clusters, nConsonants, vowel_clusters, nVowels, fp, prefix);
            }
        }

    }
}
