#include <unistd.h>
#include <sys/mount.h>
#include <sys/stat.h>

int main(void)
{
    mkdir("/proc", 0555);
    mkdir("/sys", 0555);
    mkdir("/dev", 0555);

    mount("proc", "/proc", "proc", 0, 0);
    mount("sysfs", "/sys", "sysfs", 0, 0);
    mount("devtmpfs", "/dev", "devtmpfs", 0, 0);

    write(1, "AuraOS init started\n", 20);

    execl("/usr/aura/shell/aura-shell", "aura-shell", NULL);

    for (;;) sleep(1);
}