#ifndef Z_UTILS_H
#define Z_UTILS_H

#include <stdlib.h>
#include <stdarg.h>
#include <alloca.h>
#include <string.h>
#include <stdio.h>
#include <err.h>

#define z_alloca	__builtin_alloca

#define z_memset memset
#define z_memcpy memcpy
#define z_printf printf
#define z_errx errx

#endif /* Z_UTILS_H */

