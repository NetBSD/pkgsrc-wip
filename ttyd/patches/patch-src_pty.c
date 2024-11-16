$NetBSD$

Include util.h on NetBSD.

--- src/pty.c.orig	2024-03-30 03:04:51.000000000 +0000
+++ src/pty.c
@@ -10,7 +10,7 @@
 #include <sys/ioctl.h>
 #include <sys/wait.h>
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <util.h>
 #elif defined(__FreeBSD__)
 #include <libutil.h>
