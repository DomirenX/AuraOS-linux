#include <unistd.h>

int main(void)
{
    write(1, "\nWelcome to AuraOS\n", 20);
    write(1, "Aura Shell starting...\n", 25);

    for (;;) pause();
}