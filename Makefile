CC = gcc
CFLAGS += -Wall -Wextra -O2 -fpic -Wno-unused-parameter -Wno-return-type

OBJS := foreign-dlopen/loader.o foreign-dlopen/foreign_dlopen.o foreign-dlopen/read_tpidr_el0.o foreign-dlopen/aarch64_trampo.o




.PHONY: all clean foreign-dlopen

all: libvulkan.so

foreign-dlopen:
	$(MAKE) -C foreign-dlopen

libvulkan.o: libvulkan.c
	$(CC) $(CFLAGS) -c libvulkan.c -o libvulkan.o

libvulkan.so: libvulkan.o foreign-dlopen
	$(CC) -shared $(CFLAGS) libvulkan.o $(OBJS) -o libvulkan.so.1

test:
	LD_LIBRARY_PATH=$(PWD) gdb vulkaninfo


clean:
	rm -rf *.so.1
	rm -rf *.o
