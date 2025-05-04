#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "cluster.h"
#include "tree.h"

int main(int argc, char** argv)
{
    int opt;
    char *consonant_filename = NULL;
    char *vowel_filename = NULL;
    char *output_filename = NULL;
    Cluster *consonant_clusters = NULL;
    Cluster *vowel_clusters = NULL;
    size_t n_consonant_clusters = 0;
    size_t n_vowel_clusters = 0;
    DefEngTreeNode *template_trees = NULL;
    size_t n_template_trees = 0;
    size_t tree_index = 0;
    size_t min = 2;
    size_t max = 4;

    // Parsing arguments
    // c: consonant filename
    // v: vowel filename
    // m: minimum length
    // M: maximum length
    while((opt = getopt(argc, argv, ":hc:v:o:")) != -1)
    {
        switch (opt)
        {
            case 'h':
            case 'c':
                consonant_filename = optarg;
                break;
            case 'v':
                vowel_filename = optarg;
                break;
            case 'o':
                output_filename = optarg;
                break;
            case ':':
                printf("Argument needed for %c\n", optopt);
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
                break;
        }
    }

    // Create a list of clusters
    consonant_clusters = createClusterList(consonant_filename, &n_consonant_clusters);
    vowel_clusters = createClusterList(vowel_filename, &n_vowel_clusters);

    // Create the template tree and analyze them.
    // There will be (max - min + 1) * 2 trees. (Multiplication by 2 for consonant-start and vowel-start)
    n_template_trees = (max - min + 1) * 2;
    template_trees = calloc(n_template_trees, sizeof(DefEngTreeNode));
    for (size_t depth = min; depth < max + 1; depth++)
    {
        template_trees[tree_index++] = createTree(NULL, depth, CONSONANT);
        template_trees[tree_index++] = createTree(NULL, depth, VOWEL);
    }
    
    freeClusters(consonant_clusters);
    freeClusters(vowel_clusters);
    for (size_t i = 0; i < n_template_trees; i++)
    {
        freeTree(template_trees[i]);
    }
    free(template_trees);
}
