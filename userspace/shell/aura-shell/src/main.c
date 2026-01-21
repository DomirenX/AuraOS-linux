#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

#define MAX_LINE 256
#define MAX_ARGS 16

int main(void)
{
    char line[MAX_LINE];
    char *argv[MAX_ARGS];

    while (1)
    {
        write(1, "> ", 2);

        int n = read(0, line, MAX_LINE - 1);
        if (n <= 0)
            continue;

        line[n - 1] = 0;

        if (line[0] == 0)
            continue;

        if (strcmp(line, "exit") == 0)
            return 0;

        if (strcmp(line, "pwd") == 0)
        {
            char buf[256];
            getcwd(buf, sizeof(buf));
            write(1, buf, strlen(buf));
            write(1, "\n", 1);
            continue;
        }

        if (strncmp(line, "cd ", 3) == 0)
        {
            if (chdir(line + 3) < 0)
                perror("cd");
            continue;
        }

        int argc = 0;
        char *p = strtok(line, " ");
        while (p && argc < MAX_ARGS - 1)
        {
            argv[argc++] = p;
            p = strtok(NULL, " ");
        }
        argv[argc] = NULL;

        pid_t pid = fork();
        if (pid == 0)
        {
            int fd = open("/dev/null", O_RDONLY);
            dup2(fd, 0);
            close(fd);
            
            execvp(argv[0], argv);
            perror("exec");
            _exit(1);
        } else
        {
            waitpid(pid, NULL, 0);
        }
    }
    
}