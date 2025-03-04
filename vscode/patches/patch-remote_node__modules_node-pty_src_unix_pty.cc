$NetBSD$

* Fix build on NetBSD

--- remote/node_modules/node-pty/src/unix/pty.cc.orig	2025-03-01 10:11:06.000000000 +0000
+++ remote/node_modules/node-pty/src/unix/pty.cc
@@ -42,6 +42,9 @@
 #elif defined(__FreeBSD__)
 #include <libutil.h>
 #include <termios.h>
+#elif defined(__NetBSD__)
+#include <util.h>
+#include <termios.h>
 #endif
 
 /* Some platforms name VWERASE and VDISCARD differently */
