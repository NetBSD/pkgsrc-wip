$NetBSD$

--- src/runtime/sim_ether.c.orig	2026-07-28 16:34:24.007434238 +0000
+++ src/runtime/sim_ether.c
@@ -353,6 +353,7 @@
 #else
 #include <unistd.h>
 #endif
+#include <sys/ioctl.h>
 
 /* Internal routine - forward declaration */
 static int _eth_get_system_id (char *buf, size_t buf_size);
