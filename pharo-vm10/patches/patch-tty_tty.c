$NetBSD$

Use dprintf(3) specified in POSIX.1-2008

--- tty/tty.c.orig	2024-07-02 15:02:45.000000000 +0000
+++ tty/tty.c
@@ -1,6 +1,9 @@
 #ifndef _XOPEN_SOURCE
 #define _XOPEN_SOURCE 700
 #endif
+#ifndef _POSIX_C_SOURCE
+#define _POSIX_C_SOURCE 200809L
+#endif
 
 #include <errno.h>
 #include <string.h>
