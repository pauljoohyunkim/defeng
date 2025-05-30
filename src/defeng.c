#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cluster.h"
#include "generator.h"
#include "tree.h"

static void showHelp();

int main(int argc, char** argv)
{
    int opt;
    char *consonant_former_filename = NULL;
    char *consonant_latter_filename = NULL;
    char *vowel_filename = NULL;
    char *output_filename = NULL;
    char *pEnd = NULL;      // For strtol
    ClusterList *consonant_former_clusterlist = NULL;
    ClusterList *consonant_latter_clusterlist = NULL;
    ClusterList *vowel_clusterlist = NULL;
    DefEngTreeNode *template_trees = NULL;
    size_t n_template_trees = 0;
    size_t tree_index = 0;
    size_t min = 2;
    size_t max = 3;
    size_t nWords = 0;
    FILE *fp = stdout;

    // Parsing arguments
    // c: consonant filename
    // v: vowel filename
    // m: minimum length
    // M: maximum length
    while((opt = getopt(argc, argv, ":hc:C:v:m:M:o:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                showHelp();
                return EXIT_FAILURE;
            case 'c':
                consonant_former_filename = optarg;
                break;
            case 'C':
                consonant_latter_filename = optarg;
                break;
            case 'v':
                vowel_filename = optarg;
                break;
            case 'o':
                output_filename = optarg;
                fp = fopen(output_filename, "w");
                if (fp == NULL)
                {
                    fprintf(stderr, "[-] Could not open output file for writing.\n");
                    return EXIT_FAILURE;
                }
                break;
            case 'm':
                min = strtol(optarg, &pEnd, 10);
                if (min <= 0)
                {
                    fprintf(stderr, "[-] Minimum number of space could not be read.\n");
                    return EXIT_FAILURE;
                }
                break;
            case 'M':
                max = strtol(optarg, &pEnd, 10);
                if (max <= 0)
                {
                    fprintf(stderr, "[-] Maximum number of space could not be read.\n");
                    return EXIT_FAILURE;
                }
                break;
            case ':':
                printf("[-] Argument needed for -%c\n", optopt);
                return EXIT_FAILURE;
            case '?':
                printf("[-] Unknown option: -%c\n", optopt);
                break;
        }
    }
    if (consonant_former_filename == NULL || consonant_latter_filename == NULL || vowel_filename == NULL)
    {
        fprintf(stderr, "[-] One or more of cluster files are not set!\n");
        return EXIT_FAILURE;
    }
    if (min > max)
    {
        fprintf(stderr, "[-] The minimum number of spaces exceeds the maximum number of spaces!\n");
        return EXIT_FAILURE;
    }

    // Length is one more than depth, and rest of the code uses "depth".
    min -= 1;
    max -= 1;

    // Create a list of clusters
    consonant_former_clusterlist = createClusterList(consonant_former_filename);
    consonant_latter_clusterlist = createClusterList(consonant_latter_filename);
    vowel_clusterlist = createClusterList(vowel_filename);

    // Create the template tree and analyze them.
    // There will be (max - min + 1) * 2 trees. (Multiplication by 2 for consonant-start and vowel-start)
    n_template_trees = (max - min + 1) * 2;
    template_trees = calloc(n_template_trees, sizeof(DefEngTreeNode));
    for (size_t depth = min; depth < max + 1; depth++)
    {
        template_trees[tree_index++] = createTree(NULL, depth, CONSONANT_FORMER);
        template_trees[tree_index++] = createTree(NULL, depth, VOWEL);
    }
    for (size_t i = 0; i < n_template_trees; i++)
    {
        outputSizeTree(template_trees[i], consonant_former_clusterlist->n, consonant_latter_clusterlist->n, vowel_clusterlist->n, &nWords, 1);
    }
    printf("[*] About to generate %ld words ", nWords);
    printf("and writing to %s\n", fp == stdout ? "stdout" : output_filename);
    sleep(2);
    for (size_t i = 0; i < n_template_trees; i++)
    {
        generate(template_trees[i], consonant_former_clusterlist, consonant_latter_clusterlist, vowel_clusterlist, fp, NULL);
    }
    
    // Cleanup
    if (fp != stdout)
    {
        fclose(fp);
    }
    freeClusterList(consonant_former_clusterlist);
    freeClusterList(consonant_latter_clusterlist);
    freeClusterList(vowel_clusterlist);
    for (size_t i = 0; i < n_template_trees; i++)
    {
        freeTree(template_trees[i]);
    }
    free(template_trees);
}

static void showHelp()
{
    printf("Usage: defeng -c [consonant_former_cluster file] -C [consonant_latter_cluster file] -v [vowel_cluster file] [other options]\n"
           "Other options:\n"
           "\t-o file\t\tOutput to file\n"
           "\t-m length\tSet minimum number of spaces. (Default: 2)\n"
           "\t-M length\tSet minimum number of spaces. (Default: 3)\n"
            );
}
