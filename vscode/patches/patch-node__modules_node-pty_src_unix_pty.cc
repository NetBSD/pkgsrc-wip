$NetBSD$

* Add support to NetBSD and FreeBSD

--- node_modules/node-pty/src/unix/pty.cc.orig	2026-10-24 14:36:35.000000000 +0000
+++ node_modules/node-pty/src/unix/pty.cc
@@ -44,7 +44,7 @@
 #elif defined(__FreeBSD__)
 #include <libutil.h>
 #include <termios.h>
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 #include <util.h>
 #include <termios.h>
 #endif
@@ -112,7 +112,7 @@ struct ExitEvent {
   int exit_code = 0, signal_code = 0;
 };
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 static int
 SetCloseOnExec(int fd) {
