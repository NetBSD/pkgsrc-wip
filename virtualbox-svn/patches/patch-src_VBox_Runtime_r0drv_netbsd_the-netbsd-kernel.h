$NetBSD$

--- src/VBox/Runtime/r0drv/netbsd/the-netbsd-kernel.h.orig	2016-08-12 18:06:15.000000000 +0000
+++ src/VBox/Runtime/r0drv/netbsd/the-netbsd-kernel.h
@@ -36,8 +36,8 @@
 /* Deal with conflicts first. */
 #include <sys/param.h>
 #undef PVM
-#include <sys/bus.h>
 #include <sys/types.h>
+#include <sys/bus.h>
 #include <sys/errno.h>
 #include <sys/kernel.h>
 #include <sys/uio.h>
