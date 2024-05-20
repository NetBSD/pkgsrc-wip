$NetBSD$

--- src/bin/e_util_suid.h.orig	2023-12-23 16:08:09.000000000 +0000
+++ src/bin/e_util_suid.h
@@ -11,6 +11,10 @@
 # ifdef HAVE_ENVIRON
 #  define _GNU_SOURCE 1
 # endif
+
+#if defined(__NetBSD__)
+extern char** environ;
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
