$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/brotli/common/platform.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ third_party/brotli/common/platform.h
@@ -28,7 +28,7 @@
 #include <brotli/port.h>
 #include <brotli/types.h>
 
-#if defined(OS_LINUX) || defined(OS_CYGWIN) || defined(__EMSCRIPTEN__)
+#if defined(OS_LINUX) || defined(OS_CYGWIN) || defined(__EMSCRIPTEN__) || defined(OS_BSD)
 #include <endian.h>
 #elif defined(OS_FREEBSD)
 #include <machine/endian.h>
