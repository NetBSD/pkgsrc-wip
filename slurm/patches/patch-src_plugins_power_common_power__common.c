$NetBSD$

--- ./src/plugins/power/common/power_common.c.orig	2016-05-03 22:35:12.000000000 +0000
+++ ./src/plugins/power/common/power_common.c
@@ -50,7 +50,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define POLLRDHUP POLLHUP
 #include <signal.h>
 #endif
