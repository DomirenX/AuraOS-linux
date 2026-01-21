#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: touch <file>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "a");
    if (!f)
    {
        perror("touch");
        return 1;
    }
    fclose(f);
    return 0;
}