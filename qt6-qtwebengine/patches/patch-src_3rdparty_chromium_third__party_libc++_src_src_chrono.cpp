$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libc++/src/src/chrono.cpp.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/libc++/src/src/chrono.cpp
@@ -31,7 +31,7 @@
 #  include <sys/time.h> // for gettimeofday and timeval
 #endif
 
-#if defined(__APPLE__) || defined(__gnu_hurd__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+#if defined(__APPLE__) || defined(__gnu_hurd__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)|| defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
