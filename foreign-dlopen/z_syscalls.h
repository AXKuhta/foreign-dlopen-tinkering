#ifndef Z_SYSCALLS_H
#define Z_SYSCALLS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <fcntl.h>
#include <unistd.h>

#define z_exit _exit
#define z_open open
#define z_close close
#define z_lseek lseek
#define z_read read
#define z_write write
#define z_mmap mmap
#define z_munmap munmap
#define z_mprotect mprotect

#endif /* Z_SYSCALLS_H */
