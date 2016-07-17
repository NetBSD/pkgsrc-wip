$NetBSD$

--- build/build_config.h.orig	2016-06-24 01:02:09.000000000 +0000
+++ build/build_config.h
@@ -53,6 +53,8 @@
 #define OS_FREEBSD 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
+#elif defined(__NetBSD__)
+#define OS_NETBSD 1
 #elif defined(__sun)
 #define OS_SOLARIS 1
 #elif defined(__QNXNTO__)
@@ -67,7 +69,7 @@
 
 // For access to standard BSD features, use OS_BSD instead of a
 // more specific macro.
-#if defined(OS_FREEBSD) || defined(OS_OPENBSD)
+#if defined(OS_FREEBSD) || defined(OS_OPENBSD) || defined(OS_NETBSD)
 #define OS_BSD 1
 #endif
 
@@ -75,7 +77,7 @@
 // more specific macro.
 #if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD) ||     \
     defined(OS_OPENBSD) || defined(OS_SOLARIS) || defined(OS_ANDROID) ||  \
-    defined(OS_NACL) || defined(OS_QNX)
+    defined(OS_NACL) || defined(OS_QNX) || defined(OS_NETBSD)
 #define OS_POSIX 1
 #endif
 
