$NetBSD$

--- Source/bmalloc/libpas/src/libpas/pas_random.h.orig	2025-10-29 10:34:06.335406632 +0000
+++ Source/bmalloc/libpas/src/libpas/pas_random.h
@@ -69,7 +69,7 @@ static inline unsigned pas_get_secure_ra
 
     /* Secure random is only supported on Darwin and FreeBSD at the moment due to arc4random being built into the
       stdlib. Fall back to fast behavior on other operating systems. */
-#if PAS_OS(DARWIN) || PAS_OS(FREEBSD)
+#if PAS_OS(DARWIN) || PAS_OS(FREEBSD) || PAS_OS(NETBSD)
     rand_value = arc4random_uniform(upper_bound);
 #else
     pas_fast_random_state = pas_xorshift32(pas_fast_random_state);
