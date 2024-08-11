$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/include/v8config.h.orig	2024-07-24 02:47:45.475072600 +0000
+++ v8/include/v8config.h
@@ -193,6 +193,9 @@ path. Add it with -I<path> to the comman
   && !defined(V8_TARGET_OS_FUCHSIA) \
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_LINUX) \
+  && !defined(V8_TARGET_OS_OPENBSD) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
+  && !defined(V8_TARGET_OS_NETBSD) \
   && !defined(V8_TARGET_OS_MACOS) \
   && !defined(V8_TARGET_OS_WIN) \
   && !defined(V8_TARGET_OS_CHROMEOS)
@@ -205,6 +208,9 @@ path. Add it with -I<path> to the comman
   || defined(V8_TARGET_OS_FUCHSIA) \
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_LINUX) \
+  || defined(V8_TARGET_OS_OPENBSD) \
+  || defined(V8_TARGET_OS_FREEBSD) \
+  || defined(V8_TARGET_OS_NETBSD) \
   || defined(V8_TARGET_OS_MACOS) \
   || defined(V8_TARGET_OS_WIN) \
   || defined(V8_TARGET_OS_CHROMEOS)
@@ -228,6 +234,21 @@ path. Add it with -I<path> to the comman
 # define V8_TARGET_OS_LINUX
 #endif
 
+#ifdef V8_OS_OPENBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
+#ifdef V8_OS_FREEBSD
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_BSD
+#endif
+
+#ifdef V8_OS_NETBSD
+# define V8_TARGET_OS_NETBSD
+# define V8_TARGET_OS_BSD
+#endif
+
 #ifdef V8_OS_MACOS
 # define V8_TARGET_OS_MACOS
 #endif
