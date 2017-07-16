$NetBSD$

--- lib/sanitizer_common/sanitizer_platform.h.orig	2017-07-04 05:53:23.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform.h
@@ -13,8 +13,8 @@
 #ifndef SANITIZER_PLATFORM_H
 #define SANITIZER_PLATFORM_H
 
-#if !defined(__linux__) && !defined(__FreeBSD__) && \
-  !defined(__APPLE__) && !defined(_WIN32)
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && \
+    !defined(__APPLE__) && !defined(_WIN32)
 # error "This operating system is not supported"
 #endif
 
@@ -30,6 +30,12 @@
 # define SANITIZER_FREEBSD 0
 #endif
 
+#if defined(__NetBSD__)
+#define SANITIZER_NETBSD 1
+#else
+#define SANITIZER_NETBSD 0
+#endif
+
 #if defined(__APPLE__)
 # define SANITIZER_MAC     1
 # include <TargetConditionals.h>
@@ -79,7 +85,8 @@
 # define SANITIZER_ANDROID 0
 #endif
 
-#define SANITIZER_POSIX (SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_MAC)
+#define SANITIZER_POSIX \
+  (SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD || SANITIZER_MAC)
 
 #if __LP64__ || defined(_WIN64)
 #  define SANITIZER_WORDSIZE 64
