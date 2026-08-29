$NetBSD$

Merged upstream: https://git.enlightenment.org/enlightenment/enlightenment/pulls/139

--- src/bin/e_util_suid.h.orig	2025-03-17 17:18:54.000000000 +0000
+++ src/bin/e_util_suid.h
@@ -11,6 +11,7 @@
 # ifdef HAVE_ENVIRON
 #  define _GNU_SOURCE 1
 # endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -33,6 +34,9 @@
 # include <sys/procctl.h>
 #endif

+#ifdef HAVE_ENVIRON
+extern char **environ;
+#endif

 #define E_UTIL_SUID_ERR(args...) do { fprintf(stderr, "E_SUID_ERR: "); fprintf(stderr, ##args); } while (0)
