#include <getopt.h>
#include <stdio.h>
#include "cluster.h"

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

    consonant_clusters = createClusterList(consonant_filename, &n_consonant_clusters);
    vowel_clusters = createClusterList(vowel_filename, &n_vowel_clusters);

}
