$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/diagnostics/perf-jit.h.orig	2024-07-24 02:47:46.027126000 +0000
+++ v8/src/diagnostics/perf-jit.h
@@ -31,7 +31,7 @@
 #include "include/v8config.h"
 
 // {LinuxPerfJitLogger} is only implemented on Linux.
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_BSD)
 
 #include "src/logging/log.h"
 
