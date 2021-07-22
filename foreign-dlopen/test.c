#include <unistd.h>
#include "foreign_dlopen.h"
#include <stdint.h>
#include <stdio.h>

#define RTLD_NOW 0x0002

int main(int argc, char *argv[])
{
	(void)argc;

	if (getuid() != 0) {
		printf("Need to be run as root\n");
		exit(-1);
	}

	(void) chroot("/proc/1/root");
	(void) chdir("/");

	init_exec_elf(argv);

	init_foreign_dlopen("/data/data/com.termux/files/home/fdlhelper");

	// The fun section
	// =================================================
	enter_bionic_world();

	void *h = z_dlopen("libc.so", RTLD_NOW);

	void *p = z_dlsym(h, "printf");
	int (*_printf)(const char *fmt, ...) = p;

	_printf("Hello from the other side!\n");
	_printf("TPIDR_EL0: %lu\n", read_tpidr_el0());

	void * libvk = z_dlopen("libvulkan.so", RTLD_NOW);
	void * vkinst = z_dlsym(libvk, "vkCreateInstance");

	_printf("Vulkan vkCreateInstance: %p\n", vkinst);

	enter_glibc_world();
	// =================================================

	printf("Rewrite TPIDR_EL0!\n");
	printf("TPIDR_EL0: %lu\n", read_tpidr_el0());

	exit(0);
}
