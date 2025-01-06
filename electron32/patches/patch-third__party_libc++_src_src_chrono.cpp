$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/libc++/src/src/chrono.cpp.orig	2024-10-18 12:38:47.538477700 +0000
+++ third_party/libc++/src/src/chrono.cpp
@@ -33,7 +33,8 @@
 
 // OpenBSD does not have a fully conformant suite of POSIX timers, but
 // it does have clock_gettime and CLOCK_MONOTONIC which is all we need.
-#if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__OpenBSD__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
+#if defined(__APPLE__) || defined(__gnu_hurd__) || defined(__OpenBSD__) || (defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0) || \
+      defined(__FreeBSD__) || defined(__NetBSD__)
 #  define _LIBCPP_HAS_CLOCK_GETTIME
 #endif
 
