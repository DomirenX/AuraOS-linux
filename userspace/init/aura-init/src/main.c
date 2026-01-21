#define _GNU_SOURCE

#include <unistd.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static void panic(const char *msg)
{
    write(2, "aura-init panic: ", 17);
    write(2, msg, strlen(msg));
    write(2, "\n", 1);
    
    for (;;) pause();
}

int main(void)
{
    if (getpid() != 1)
    {
        fprintf(stderr, "aura-init must be PID 1\n");
        return 1;
    }

    mkdir("/proc", 0555);
    mkdir("/sys", 0555);
    mkdir("/dev", 0755);

    if (mount("proc", "/proc", "proc", 0, NULL) < 0)
        perror("mount /proc");

    if (mount("sysfs", "/sys", "sysfs", 0, NULL) < 0)
        perror("mount /sys");

    if (mount("devtmpfs", "/dev", "devtmpfs", 0, "mode=0755") < 0)
        perror("mount /dev");

    int fd = open("/dev/console", O_RDWR);
    if (fd < 0)
        panic("cannot open /dev/console");

    dup2(fd, 0);
    dup2(fd, 1);
    dup2(fd, 2);
    if (fd > 2)
        close(fd);

    printf("AuraOS init started\n");

    setenv("PATH", "/bin:/sbin", 1);
    setenv("HOME", "/root", 1);
    setenv("TERM", "linux", 1);

    for (;;)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork");
            sleep(1);
            continue;
        }

        if (pid == 0)
        {
            execl("/bin/aura-shell", "aura-shell", NULL);
            perror("exec aura-shell");
            _exit(1);
        }

        int status;
        waitpid(pid, &status, 0);
        printf("aura-shell exited, restarting...\n");
    }
}