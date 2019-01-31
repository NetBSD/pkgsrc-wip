$NetBSD$

Recognize NetBSD.

--- spectro/hidio.c.orig	2018-07-09 02:57:13.000000000 +0000
+++ spectro/hidio.c
@@ -89,7 +89,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/types.h> 
 #include <usbhid.h> 
 #else	/* assume Linux */ 
