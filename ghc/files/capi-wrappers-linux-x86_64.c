#include "HsFFI.h"
#include <assert.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <utime.h>

/* A quick and dirty hack to resurrect -fvia-C from bitrot.
 *
 * The newest CapiFFI extension doesn't play nice with -fvia-C,
 * generating function wrappers without saving them into the .hc
 * files.
 */

int ghc_wrapper_d2kC_fcntl(int fd, int cmd);
int ghc_wrapper_d2kq_fcntl(int filedes, int cmd, long arg);
int ghc_wrapper_d2kb_fcntl(int filedes, int cmd, struct flock* arg);
int ghc_wrapper_d1lS_gettimeofday(struct timeval* tp, struct timezone* tzp);
int ghc_wrapper_d2ir_utime(const char *path, const struct utimbuf *times);
HsInt32 SystemziConsoleziTerminfoziBase_d2dS(StgStablePtr the_stableptr, HsInt32 a1);

/* c_fcntl_read */
int ghc_wrapper_d2kC_fcntl(int fd, int cmd) {
    return fcntl(fd, cmd);
}

/* c_fcntl_write */
int ghc_wrapper_d2kq_fcntl(int fd, int cmd, long arg) {
    return fcntl(fd, cmd, arg);
}

/* c_fcntl_lock */
int ghc_wrapper_d2kb_fcntl(int fd, int cmd, struct flock* arg) {
    return fcntl(fd, cmd, arg);
}

int ghc_wrapper_d1lS_gettimeofday(struct timeval* tp, struct timezone* tzp) {
    return gettimeofday(tp, tzp);
}

int ghc_wrapper_d2ir_utime(const char *path, const struct utimbuf *times) {
    return utime(path, times);
}

HsInt32 SystemziConsoleziTerminfoziBase_d2dS(StgStablePtr the_stableptr, HsInt32 a1) {
    /* The recipe to create this function is somewhere in
     * compiler/deSugar/DsForeign.lhs, but... I don't want to bother
     * replicating that here.
     */
    assert("DO NOT CALL THIS FUNCTION" == NULL);
    return -1;
}
