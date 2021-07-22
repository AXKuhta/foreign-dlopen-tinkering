#include "foreign_dlopen.h"
#include "elf_loader.h"
#include <stdint.h>
#include <setjmp.h>
#include <stdio.h>

jmp_buf jmpbuf;
char addrbuf[17];
void *(*z_dlopen)(const char *filename, int flags);
void *(*z_dlsym)(void *handle, const char *symbol);
int (*z_dlclose)(void *handle);
char *(*z_dlerror)(void);

uint64_t read_tpidr_el0(void);
void write_tpidr_el0(uint64_t value);

// TPIDR_EL0 values for different worlds
uint64_t glibc_tpidr_el0;
uint64_t bionic_tpidr_el0;

// World switching
void enter_glibc_world() { write_tpidr_el0(glibc_tpidr_el0); };
void enter_bionic_world() { write_tpidr_el0(bionic_tpidr_el0); };

void do_jump(void **p)
{
	// Populate the functions that we oh so want
	z_dlopen = p[0];
	z_dlsym = p[1];
	z_dlclose = p[2];
	z_dlerror = p[3];

	// Store bionic TPIDR_EL0
	bionic_tpidr_el0 = read_tpidr_el0();

	// Restore our world for now
	enter_glibc_world();

	longjmp(jmpbuf, 1);
}

void init_foreign_dlopen(const char *file)
{
	char *argv[2];

	// Almost at the point of no return
	// Save our TPIDR_EL0
	glibc_tpidr_el0 = read_tpidr_el0();

	snprintf(addrbuf, 16, "%lx", (unsigned long)do_jump);

	argv[0] = (char *)file;
	argv[1] = addrbuf;

	if (!setjmp(jmpbuf)) {
		exec_elf(file, 2, argv);
	} else {
		return;
	}
}
