#include <getopt.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    int opt;

    // Parsing arguments
    while((opt = getopt(argc, argv, ":hc:v:o:")) != -1)
    {
        switch (opt)
        {
            case 'h':
            case 'c':
            case 'v':
            case 'o':
            case '?':
                printf("Unknown option: %c\n", optopt);
                break;
        }
    }
}
