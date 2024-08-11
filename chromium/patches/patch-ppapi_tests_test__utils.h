$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ppapi/tests/test_utils.h.orig	2024-07-24 02:44:43.309427700 +0000
+++ ppapi/tests/test_utils.h
@@ -314,6 +314,8 @@ do { \
 #define PPAPI_OS_FREEBSD 1
 #elif defined(__OpenBSD__)
 #define PPAPI_OS_OPENBSD 1
+#elif defined(__NetBSD__)
+#define PPAPI_OS_NETBSD 1
 #elif defined(__sun)
 #define PPAPI_OS_SOLARIS 1
 #else
@@ -322,7 +324,8 @@ do { \
 
 /* These are used to determine POSIX-like implementations vs Windows. */
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
-    defined(__OpenBSD__) || defined(__sun) || defined(__native_client__)
+    defined(__OpenBSD__) || defined(__sun) || defined(__native_client__) \
+    defined(__NetBSD__)
 #define PPAPI_POSIX 1
 #endif
 
