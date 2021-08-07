$NetBSD$

Include <sys/file.h> for LOCK_* (needed for musl-libc).

--- tools/tools.h.orig	2021-05-07 21:14:09.000000000 +0000
+++ tools/tools.h
@@ -47,6 +47,7 @@
 
 #include <ctype.h>
 #include <sys/types.h>
+#include <sys/file.h>	/* LOCK_* */
 
 #define CMD_LEN 256
 #define MAX_ARGS 64
