$NetBSD$

--- spa/tests/stress-ringbuffer.c.orig	2024-10-21 16:52:33.198030042 +0000
+++ spa/tests/stress-ringbuffer.c
@@ -11,7 +11,7 @@
 #define ARRAY_SIZE 63
 #define MAX_VALUE 0x10000
 
-#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined (__GNU__)
+#if defined(__FreeBSD__) || defined(__MidnightBSD__) || defined (__GNU__) || defined(__NetBSD__)
 #include <sys/param.h>
 #if (__FreeBSD_version >= 1400000 && __FreeBSD_version < 1400043) \
     || (__FreeBSD_version < 1300523) || defined(__MidnightBSD__) \
