CC = gcc
CFLAGS = -Wall -Wextra -O2 -fpic -Wno-unused-parameter -Wno-return-type

libvulkan.so: libvulkan.o
	$(CC) -shared $(CFLAGS) libvulkan.o -o libvulkan.so.1

libvulkan.o: libvulkan.c
	$(CC) $(CFLAGS) -c libvulkan.c -o libvulkan.o

clean:
	rm -rf *.so.1
	rm -rf *.o

test:
	LD_LIBRARY_PATH=$(PWD) gdb vulkaninfo

all: libvulkan.so

