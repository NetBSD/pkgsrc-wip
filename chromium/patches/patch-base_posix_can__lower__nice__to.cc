$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/posix/can_lower_nice_to.cc.orig	2024-09-24 20:49:13.794572800 +0000
+++ base/posix/can_lower_nice_to.cc
@@ -11,8 +11,12 @@
 
 #include "build/build_config.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/param.h>
+#endif
+
 // Not defined on AIX by default.
-#if BUILDFLAG(IS_AIX)
+#if BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
 #if defined(RLIMIT_NICE)
 #error Assumption about OS_AIX is incorrect
 #endif
