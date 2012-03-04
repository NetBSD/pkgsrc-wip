#include <assert.h>
#include <fcntl.h>
#include <sys/time.h>
#include <utime.h>

/* A quick and dirty hack to resurrect -fvia-C from bitrot.
 *
 * The newest CapiFFI extension doesn't play nice with -fvia-C,
 * generating function wrappers without saving them into the .hc
 * files.
 */

int ghc_wrapper_d2lP_fcntl(int filedes, int cmd);
int ghc_wrapper_d2lD_fcntl(int filedes, int cmd, long arg);
int ghc_wrapper_d2lo_fcntl(int filedes, int cmd, struct flock* arg);
int ghc_wrapper_d1mz_gettimeofday(struct timeval* tp, void* tzp);
int ghc_wrapper_d2jE_utime(const char *path, const struct utimbuf *times);
void SystemziConsoleziTerminfoziBase_d2eD(void *cif, void* resp, void** args, void* the_stableptr);

/* c_fcntl_read */
int ghc_wrapper_d2lP_fcntl(int filedes, int cmd) {
    return fcntl(filedes, cmd);
}

/* c_fcntl_write */
int ghc_wrapper_d2lD_fcntl(int filedes, int cmd, long arg) {
    return fcntl(filedes, cmd, arg);
}

/* c_fcntl_lock */
int ghc_wrapper_d2lo_fcntl(int filedes, int cmd, struct flock* arg) {
    return fcntl(filedes, cmd, arg);
}

int ghc_wrapper_d1mz_gettimeofday(struct timeval* tp, void* tzp) {
    return gettimeofday(tp, tzp);
}

int ghc_wrapper_d2jE_utime(const char *path, const struct utimbuf *times) {
    return utime(path, times);
}

void SystemziConsoleziTerminfoziBase_d2eD(void *cif, void* resp, void** args, void* the_stableptr) {
    /* The recipe to create this function is somewhere in
     * compiler/deSugar/DsForeign.lhs, but... I don't want to bother
     * replicating that here.
     */
    assert("DO NOT CALL THIS FUNCTION" == NULL);
}
