$NetBSD$

Use dprintf(3) specified in POSIX.1-2008

--- src/tty/tty.c.orig	2026-08-01 09:45:59.975307960 +0000
+++ src/tty/tty.c
@@ -1,6 +1,9 @@
 #ifndef _XOPEN_SOURCE
 #define _XOPEN_SOURCE 700
 #endif
+#ifndef _POSIX_C_SOURCE
+#define _POSIX_C_SOURCE 200809L
+#endif
 
 #include <errno.h>
 #include <string.h>
