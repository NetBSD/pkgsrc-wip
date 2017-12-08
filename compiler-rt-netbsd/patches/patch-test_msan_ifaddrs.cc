$NetBSD$

--- test/msan/ifaddrs.cc.orig	2017-10-17 18:35:26.000000000 +0000
+++ test/msan/ifaddrs.cc
@@ -10,7 +10,7 @@
 
 #include <vector>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/socket.h>  // To define 'struct sockaddr'.
 #endif
 
