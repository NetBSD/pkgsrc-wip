$NetBSD$

Add DragonFly.

--- ppi.c.orig	2022-05-07 20:29:58.000000000 +0000
+++ ppi.c
@@ -32,7 +32,7 @@
 #include <unistd.h>
 #include <errno.h>
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 # include "freebsd_ppi.h"
 #elif defined(__linux__)
 # include "linux_ppdev.h"
