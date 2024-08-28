$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libc++/src/src/filesystem/filesystem_clock.cpp.orig	2024-08-21 22:47:01.370845300 +0000
+++ third_party/libc++/src/src/filesystem/filesystem_clock.cpp
@@ -29,7 +29,8 @@
 #  include <sys/time.h> // for gettimeofday and timeval
 #endif
 
-#if defined(__APPLE__) || defined(__gnu_hurd__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+#if defined(__APPLE__) || defined(__gnu_hurd__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || defined(__OpenBSD__) || \
+    defined(__FreeBSD__) || defined(__NetBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
