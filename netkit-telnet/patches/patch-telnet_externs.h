$NetBSD$

--- telnet/externs.h.orig	1999-08-19 09:34:15.000000000 +0000
+++ telnet/externs.h
@@ -41,7 +41,9 @@
 #include <stdio.h>
 #include <setjmp.h>
 #include <sys/ioctl.h>
+#if defined(__linux__)
 #include <features.h>
+#endif
 #include <termios.h>
 
 #if defined(NO_CC_T)
