$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/diagnostics/perf-jit.cc.orig	2024-12-03 23:33:17.335840700 +0000
+++ v8/src/diagnostics/perf-jit.cc
@@ -31,7 +31,7 @@
 #include "src/flags/flags.h"
 
 // Only compile the {LinuxPerfJitLogger} on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_BSD)
 
 #include <fcntl.h>
 #include <sys/mman.h>
