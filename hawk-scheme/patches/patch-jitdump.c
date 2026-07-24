$NetBSD$

Include <sys/stat.h> for S_IRUSR and S_IWUSR.

--- jitdump.c.orig	2026-07-24 19:08:54.366963710 +0000
+++ jitdump.c
@@ -12,6 +12,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 #if defined(__linux__)
 #include <sys/syscall.h>
 #endif
