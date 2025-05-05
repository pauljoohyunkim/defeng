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
    char *consonant_filename = NULL;
    char *vowel_filename = NULL;
    char *output_filename = NULL;
    char *pEnd = NULL;      // For strtol
    Cluster *consonant_clusters = NULL;
    Cluster *vowel_clusters = NULL;
    size_t n_consonant_clusters = 0;
    size_t n_vowel_clusters = 0;
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
    while((opt = getopt(argc, argv, ":hc:v:m:M:o:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                showHelp();
                return EXIT_FAILURE;
            case 'c':
                consonant_filename = optarg;
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
    if (consonant_filename == NULL || vowel_filename == NULL)
    {
        fprintf(stderr, "[-] One or both of consonant cluster file or vowel cluster file is not set!\n");
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
    for (size_t i = 0; i < n_template_trees; i++)
    {
       outputSizeTree(template_trees[i], n_consonant_clusters, n_vowel_clusters, &nWords, 1);
    }
    printf("[*] About to generate %ld words ", nWords);
    printf("and writing to %s\n", fp == stdout ? "stdout" : output_filename);
    sleep(2);
    for (size_t i = 0; i < n_template_trees; i++)
    {
        generate(template_trees[i], consonant_clusters, n_consonant_clusters, vowel_clusters, n_vowel_clusters, fp, NULL);
    }
    
    // Cleanup
    if (fp != stdout)
    {
        fclose(fp);
    }
    freeClusters(consonant_clusters);
    freeClusters(vowel_clusters);
    for (size_t i = 0; i < n_template_trees; i++)
    {
        freeTree(template_trees[i]);
    }
    free(template_trees);
}

static void showHelp()
{
    printf("Usage: defeng -c [consonant_cluster file] -v [vowel_cluster file] [other options]\n"
           "Other options:\n"
           "\t-o file\t\tOutput to file\n"
           "\t-m length\tSet minimum number of spaces.\n"
           "\t-M length\tSet minimum number of spaces.\n"
            );
}
