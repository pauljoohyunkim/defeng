#include <getopt.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int opt;
    char* consonant_filename = NULL;
    char* vowel_filename = NULL;
    char* output_filename = NULL;

    // Parsing arguments
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


}
