$NetBSD$

environ is not part of unistd.h on NetBSD (Is this a NetBSD bug?)

--- runtime.c.orig	2026-07-24 05:01:51.872552840 +0000
+++ runtime.c
@@ -1,6 +1,10 @@
 #define _POSIX_C_SOURCE 200809L
 #define _GNU_SOURCE
 
+#ifdef __NetBSD__
+extern char **environ;
+#endif
+
 #include <assert.h>
 #ifdef __APPLE__
 #include <crt_externs.h>
