$NetBSD$

* Import from chromium

--- src/webrtc/src/third_party/abseil-cpp/absl/base/internal/raw_logging.cc.orig	2026-11-10 15:47:31.538000000 +0000
+++ src/webrtc/src/third_party/abseil-cpp/absl/base/internal/raw_logging.cc
@@ -43,7 +43,7 @@
 // this, consider moving both to config.h instead.
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||     \
     defined(__hexagon__) || defined(__Fuchsia__) || defined(__OpenBSD__) || \
-    defined(__EMSCRIPTEN__) || defined(__ASYLO__)
+    defined(__EMSCRIPTEN__) || defined(__ASYLO__) || defined(__NetBSD__)
 
 #include <unistd.h>
 
