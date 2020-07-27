$NetBSD$

--- net/socket/udp_socket_posix.h.orig	2020-07-15 18:56:00.000000000 +0000
+++ net/socket/udp_socket_posix.h
@@ -34,7 +34,7 @@
 
 #if defined(__ANDROID__) && defined(__aarch64__)
 #define HAVE_SENDMMSG 1
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define HAVE_SENDMMSG 1
 #else
 #define HAVE_SENDMMSG 0
