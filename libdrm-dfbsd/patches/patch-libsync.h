$NetBSD$

From FreeBSD ports x11/libdrm 2.4.84

# define ETIME as ETIMEOUT same as done in Mesa

--- libsync.h.orig	2017-11-03 16:44:27.000000000 +0000
+++ libsync.h
@@ -35,6 +35,9 @@
 #include <sys/ioctl.h>
 #include <sys/poll.h>
 #include <unistd.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 #if defined(__cplusplus)
 extern "C" {
