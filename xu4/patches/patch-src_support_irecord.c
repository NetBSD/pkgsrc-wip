$NetBSD$

Add NetBSD support.

--- src/support/irecord.c.orig	2025-01-04 21:38:58.000000000 +0000
+++ src/support/irecord.c
@@ -31,6 +31,10 @@ void irec_init(InputRecorder* rec)
 #define write   _write
 #else
 #include <unistd.h>
+#if defined(__NetBSD__)
+#include <sys/stat.h>
+#include <fcntl.h>
+#endif
 #endif
 
 #if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
