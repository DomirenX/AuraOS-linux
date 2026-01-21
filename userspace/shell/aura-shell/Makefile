CC ?= x86_64-linux-musl-gcc
CFLAGS = -static -O2 -Wall

TARGET = aura-shell
SRC = src/main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
	cp aura-shell ~/Documents/Projects/auraos-linux/rootfs/usr/aura/shell
	cp aura-shell ~/Documents/Projects/auraos-linux/rootfs/bin

clean:
	rm -rf $(TARGET)