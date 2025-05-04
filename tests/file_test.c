#include <stdio.h>
#include "../src/cluster.h"

int main()
{
    size_t n = 0;
    FILE *fp = fopen("../data/c.txt", "r");
    n = nLines(fp);
    fclose(fp);
    printf("%ld\n", n);

    return 0;
}
