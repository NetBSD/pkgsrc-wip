$NetBSD$

Avoid calling arc4random_uniform() with a too small argument,
to avoid the mis-handled 0 argument on NetBSD (SIGFPE core dump,
due to "mod 0" being attempted).

--- lib/isc/include/isc/random.h.orig	2025-10-23 19:53:03.005527744 +0000
+++ lib/isc/include/isc/random.h
@@ -30,7 +30,7 @@ ISC_LANG_BEGINDECLS
 #if HAVE_ARC4RANDOM && !defined(__linux__)
 #define isc_random32()			arc4random()
 #define isc_random_buf(buf, buflen)	arc4random_buf(buf, buflen)
-#define isc_random_uniform(upper_bound) arc4random_uniform(upper_bound)
+#define isc_random_uniform(upper_bound) ((upper_bound) < 2 ? arc4random() & (upper_bound) : arc4random_uniform(upper_bound))
 #else /* HAVE_ARC4RANDOM && !defined(__linux__) */
 uint32_t
 isc_random32(void);
