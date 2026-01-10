CC ?= x86_64-linux-musl-gcc
CFLAGS = -static -O2 -Wall

all:
	$(CC) $(CFLAGS) src/main.c -o aura-init
	cp aura-init ~/Documents/Projects/auraos-linux/rootfs/sbin

clean:
	rm -f aura-init