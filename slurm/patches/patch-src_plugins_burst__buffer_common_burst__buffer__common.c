$NetBSD$

# Linux compat

--- src/plugins/burst_buffer/common/burst_buffer_common.c.orig	2016-05-14 18:55:22.000000000 +0000
+++ src/plugins/burst_buffer/common/burst_buffer_common.c
@@ -52,7 +52,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define POLLRDHUP POLLHUP
 #include <signal.h>
 #endif
