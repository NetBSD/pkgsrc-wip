$NetBSD$

Use POSIX CLOCK_MONOTONIC on NetBSD as well.

--- src/tmr/tmr.c.orig	2021-04-21 22:05:17.000000000 +0000
+++ src/tmr/tmr.c
@@ -142,7 +142,7 @@ uint64_t tmr_jiffies_usec(void)
 #else
 	struct timespec now;
 
-#if defined(FREEBSD) || defined(OPENBSD)
+#if defined(FREEBSD) || defined(OPENBSD) || defined(NETBSD)
 	if (0 != clock_gettime(CLOCK_MONOTONIC, &now)) {
 #else
 	if (0 != clock_gettime(CLOCK_MONOTONIC_RAW, &now)) {
