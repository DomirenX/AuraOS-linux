#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    const char *path = ".";

    if (argc > 1)
        path = argv[1];

    DIR *dir = opendir(path);
    if (!dir)
    {
        perror("ls");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry -> d_name[0] == '.')
            continue;
        printf("%s ", entry -> d_name);
    }

    printf("\n");
    closedir(dir);
    return 0;
}