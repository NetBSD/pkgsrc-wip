$NetBSD$

Treat NetBSD as OpenBSD.

--- src/frameserver/terminal/default/tsm/shl-pty.c.orig	2018-12-10 23:33:36.000000000 +0000
+++ src/frameserver/terminal/default/tsm/shl-pty.c
@@ -15,7 +15,7 @@
 
 #ifdef __APPLE__
 #include <util.h>
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 #ifndef IUTF8
 #define IUTF8 0x00004000
 #endif
