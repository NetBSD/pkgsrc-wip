$NetBSD: patch-build_build__config.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- build/build_config.h.orig	2011-04-13 08:01:33.000000000 +0000
+++ build/build_config.h
@@ -28,9 +28,15 @@
 #elif defined(_WIN32)
 #define OS_WIN 1
 #define TOOLKIT_VIEWS 1
+#elif defined(__DragonFly__)
+#define OS_DRAGONFLY 1
+#define TOOLKIT_GTK
 #elif defined(__FreeBSD__)
 #define OS_FREEBSD 1
 #define TOOLKIT_GTK
+#elif defined(__NetBSD__)
+#define OS_NETBSD 1
+#define TOOLKIT_GTK
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
 #define TOOLKIT_GTK
@@ -47,8 +53,8 @@
 #define TOOLKIT_USES_GTK 1
 #endif
 
-#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_OPENBSD) || \
-    defined(OS_SOLARIS)
+#if defined(OS_LINUX) || defined(OS_DRAGONFLY) || defined(OS_FREEBSD) || \
+    defined(OS_NETBSD) || defined(OS_OPENBSD) || defined(OS_SOLARIS)
 #if !defined(USE_OPENSSL)
 #define USE_NSS 1  // Default to use NSS for crypto, unless OpenSSL is chosen.
 #endif
@@ -61,13 +67,19 @@
 
 // For access to standard POSIXish features, use OS_POSIX instead of a
 // more specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FREEBSD) || \
-    defined(OS_OPENBSD) || defined(OS_SOLARIS) || defined(OS_NACL)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_DRAGONFLY) || \
+    defined(OS_FREEBSD) || defined(OS_NETBSD) || defined(OS_OPENBSD) || \
+    defined(OS_SOLARIS) || defined(OS_NACL)
 #define OS_POSIX 1
 // Use base::DataPack for name/value pairs.
 #define USE_BASE_DATA_PACK 1
 #endif
 
+#if defined(OS_DRAGONFLY) || defined(OS_FREEBSD) || defined(OS_NETBSD) || \
+    defined(OS_OPENBSD)
+#define OS_BSD 1
+#endif
+
 // Use tcmalloc
 #if (defined(OS_WIN) || defined(OS_LINUX)) && !defined(NO_TCMALLOC)
 #define USE_TCMALLOC 1
