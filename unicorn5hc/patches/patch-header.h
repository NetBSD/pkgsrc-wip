$NetBSD: patch-header.h,v 1.1 2015/03/03 12:45:07 thomasklausner Exp $

NetBSD does not define O_BINARY, add a compat define.

--- header.h.orig	2014-05-02 21:09:13.000000000 +0000
+++ header.h
@@ -21,6 +21,10 @@
 #include <sys/timeb.h>
 #include <fcntl.h>
 
+#ifndef O_BINARY
+#define O_BINARY 0
+#endif
+
 #ifdef LINK
 #undef LINK
 #endif
