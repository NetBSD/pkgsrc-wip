/* $NetBSD$ */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "glibc-compat.h"

#if defined(__cplusplus)
extern "C" {
#endif

extern char **environ;

int clearenv(void) {
    environ = (char **)calloc(1, sizeof(*environ));
    return 0;
}

int euidaccess(const char *pathname, int mode) {
    return faccessat(AT_FDCWD, pathname, mode, AT_EACCESS);
}

#if defined(__cplusplus)
}
#endif
