$NetBSD$

Use errno.h

--- src/net/src/net_udp.c.orig	2026-07-06 19:57:25.270167850 +0000
+++ src/net/src/net_udp.c
@@ -30,7 +30,7 @@
 #ifdef _WIN32
 #include <windows.h>
 #else
-#include <sys/errno.h>
+#include <errno.h>
 #include <sys/param.h>
 #include <unistd.h>
 #endif
