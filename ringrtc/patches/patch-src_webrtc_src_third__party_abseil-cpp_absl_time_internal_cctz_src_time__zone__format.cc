$NetBSD$

* Import from chromium

--- src/webrtc/src/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc.orig	2026-11-10 15:47:33.460000000 +0000
+++ src/webrtc/src/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc
@@ -21,7 +21,7 @@
 #endif
 
 #if HAS_STRPTIME
-#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(_XOPEN_SOURCE) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #define _XOPEN_SOURCE 500  // Exposes definitions for SUSv2 (UNIX 98).
 #endif
 #endif
