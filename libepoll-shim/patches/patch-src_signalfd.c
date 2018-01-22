$NetBSD$

--- src/signalfd.c.orig	2016-12-20 21:20:05.000000000 +0000
+++ src/signalfd.c
@@ -16,6 +16,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifndef _SIG_MAXSIG
+#define _SIG_MAXSIG _NSIG
+#endif
+
 struct signalfd_context {
 	int fd;
 	int flags;
