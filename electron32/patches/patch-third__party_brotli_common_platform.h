$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/brotli/common/platform.h.orig	2024-10-18 12:35:04.091758500 +0000
+++ third_party/brotli/common/platform.h
@@ -28,7 +28,7 @@
 #include <brotli/port.h>
 #include <brotli/types.h>
 
-#if defined(OS_LINUX) || defined(OS_CYGWIN) || defined(__EMSCRIPTEN__)
+#if defined(OS_LINUX) || defined(OS_CYGWIN) || defined(__EMSCRIPTEN__) || defined(OS_BSD)
 #include <endian.h>
 #elif defined(OS_FREEBSD)
 #include <machine/endian.h>
