/* $NetBSD$
 *
 * Shims to functions that can only be found in glibc. These are weak
 * symbols so that they won't conflict with native ones.
 */

#if defined(__cplusplus)
extern "C" {
#endif

int clearenv(void) __attribute__((__weak__));
int euidaccess(const char *pathname, int mode) __attribute__((__weak__));

#if defined(__cplusplus)
}
#endif
