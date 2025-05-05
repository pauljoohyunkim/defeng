#include <stdlib.h>
#include <string.h>
#include "generator.h"
#include "tree.h"

// Set prefix = NULL when calling.
void generate(DefEngTreeNode node, ClusterList *consonant_former_clusterlist, ClusterList* consonant_latter_clusterlist, ClusterList *vowel_clusterlist, FILE *fp, Cluster *prefix)
{
    Cluster *clusters = NULL;
    size_t nClusters = 0;

    if (prefix == NULL)
    {
        size_t nSpace = node->depth + 1;
        prefix = (Cluster *) calloc(nSpace, sizeof(Cluster));
    }

    if (node->space_type == CONSONANT_FORMER)
    {
        clusters = consonant_former_clusterlist->clusters;
        nClusters = consonant_former_clusterlist->n;
    }
    else if (node->space_type == CONSONANT_LATTER)
    {
        clusters = consonant_latter_clusterlist->clusters;
        nClusters = consonant_former_clusterlist->n;
    }
    else if (node->space_type == VOWEL)
    {
        clusters = vowel_clusterlist->clusters;
        nClusters = vowel_clusterlist->n;
    }

    // When node depth is zero, output to console.
    // Otherwise, only set the prefix.
    if (node->depth == 0)
    {

        for (size_t j = 0; j < nClusters; j++)
        {
            strcpy(prefix[node->root->depth].arr, clusters[j].arr);
            for (size_t i = 0; i < node->root->depth; i++)
            {
                fprintf(fp, "%s", prefix[i].arr);
            }
            fprintf(fp, "%s\n", prefix[node->root->depth].arr);
        }
    }
    else
    {
        for (size_t j = 0; j < nClusters; j++)
        {
            strcpy(prefix[node->root->depth - node->depth].arr, clusters[j].arr);
            generate(node->children[0], consonant_former_clusterlist, consonant_latter_clusterlist, vowel_clusterlist, fp, prefix);
            if (node->nChild == 2)
            {
                generate(node->children[1], consonant_former_clusterlist, consonant_latter_clusterlist, vowel_clusterlist, fp, prefix);
            }
        }
    }

    if (node->root == node)
    {
        free(prefix);
    }
}
