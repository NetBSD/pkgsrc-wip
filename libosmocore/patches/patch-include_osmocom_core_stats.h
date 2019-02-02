$NetBSD$

--- include/osmocom/core/stats.h.orig	2019-01-21 13:50:43.000000000 +0000
+++ include/osmocom/core/stats.h
@@ -28,7 +28,7 @@
  * embedded systems.  We cannot use the autoconf-defined HAVE_... macros
  * here, as that only works at library compile time, not at application
  * compile time */
-#if defined(unix) || defined(__APPLE__)
+#if 1
 
 #include <sys/socket.h>
 #include <arpa/inet.h>
