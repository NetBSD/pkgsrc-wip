$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/include/v8config.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ v8/include/v8config.h
@@ -207,6 +207,9 @@ path. Add it with -I<path> to the comman
   && !defined(V8_TARGET_OS_IOS) \
   && !defined(V8_TARGET_OS_TVOS) \
   && !defined(V8_TARGET_OS_LINUX) \
+  && !defined(V8_TARGET_OS_OPENBSD) \
+  && !defined(V8_TARGET_OS_FREEBSD) \
+  && !defined(V8_TARGET_OS_NETBSD) \
   && !defined(V8_TARGET_OS_MACOS) \
   && !defined(V8_TARGET_OS_WIN) \
   && !defined(V8_TARGET_OS_CHROMEOS)
@@ -220,6 +223,9 @@ path. Add it with -I<path> to the comman
   || defined(V8_TARGET_OS_IOS) \
   || defined(V8_TARGET_OS_TVOS) \
   || defined(V8_TARGET_OS_LINUX) \
+  || defined(V8_TARGET_OS_OPENBSD) \
+  || defined(V8_TARGET_OS_FREEBSD) \
+  || defined(V8_TARGET_OS_NETBSD) \
   || defined(V8_TARGET_OS_MACOS) \
   || defined(V8_TARGET_OS_WIN) \
   || defined(V8_TARGET_OS_CHROMEOS)
@@ -247,6 +253,22 @@ path. Add it with -I<path> to the comman
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
+# define V8_TARGET_OS_OPENBSD
+# define V8_TARGET_OS_NETBSD
+# define V8_TARGET_OS_BSD
+#endif
+
 #ifdef V8_OS_MACOS
 # define V8_TARGET_OS_MACOS
 #endif
@@ -395,6 +417,7 @@ path. Add it with -I<path> to the comman
 #if (defined(_M_X64) || defined(__x86_64__)            /* x64 (everywhere) */  \
      || ((defined(__AARCH64EL__) || defined(_M_ARM64)) /* arm64, but ... */    \
          && !defined(_WIN32)))                         /* not on windows */    \
+     && !defined(__OpenBSD__)                          /* not on OpenBSD */    \
      && !defined(COMPONENT_BUILD)                      /* no component build */\
      && __clang_major__ >= 17                          /* clang >= 17 */
 # define V8_HAS_ATTRIBUTE_PRESERVE_MOST (__has_attribute(preserve_most))
