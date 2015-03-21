#define _GNU_SOURCE
#include <sys/syscall.h>
#include <dlfcn.h>
#include <errno.h>
#include <unistd.h>

#ifndef PR_SET_NAME
#define PR_SET_NAME 15
#endif

/*
 * This library override some problematic Linux syscalls while debootstrap runs.
 *
 * To build:
 * gcc -O2 -fPIC -shared -m64 -o libfakesyscall-amd64.so libfakesyscall.c
 * gcc -O2 -fPIC -shared -m32 -o libfakesyscall-i386.so libfakesyscall.c
 */

/*
 * NetBSD does not emulate prctl(2), pretend it works for PR_SET_NAME.
 * Needed by some of the Debian base tools.
 */
int prctl(int option, unsigned long arg2, unsigned long arg3,
	  unsigned long arg4, unsigned long arg5) {
	if (option == PR_SET_NAME) {
		return 0;
	}
	return syscall(SYS_prctl, option, arg2, arg3, arg4, arg5);
}


/*
 * NetBSD does not emulate this and we don't want the chroot to mess
 * with mounts anyway.
 */
int mount(const char *source, const char *target,
	  const char *filesystemtype, unsigned long mountflags,
	  const void *data) {
	return 0;
}
