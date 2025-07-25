$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/diagnostics/perf-jit.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ v8/src/diagnostics/perf-jit.h
@@ -31,7 +31,7 @@
 #include "include/v8config.h"
 
 // {PerfJitLogger} is only implemented on Linux & Darwin.
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
 
 #include "src/logging/log.h"
 
