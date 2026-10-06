$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/time/time_now_posix.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ base/time/time_now_posix.cc
@@ -27,7 +27,7 @@
 #endif
 
 // NaCl doesn't support CLOCK_MONOTONIC_COARSE.
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
 #define TIMETICKS_LOW_RESOLUTION_CLOCK CLOCK_MONOTONIC
 #else
 #define TIMETICKS_LOW_RESOLUTION_CLOCK CLOCK_MONOTONIC_COARSE
