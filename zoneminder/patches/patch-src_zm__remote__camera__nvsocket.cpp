$NetBSD$

--- src/zm_remote_camera_nvsocket.cpp.orig	2026-07-26 00:42:57.983592814 +0000
+++ src/zm_remote_camera_nvsocket.cpp
@@ -32,6 +32,9 @@
 #ifdef __FreeBSD__
 #include <netinet/in.h>
 #endif
+#ifdef __NetBSD__
+#include <netinet/in.h>
+#endif
 
 RemoteCameraNVSocket::RemoteCameraNVSocket(
   const Monitor *monitor,
