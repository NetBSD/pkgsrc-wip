$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -35,7 +35,8 @@
 #if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
     !defined(__native_client__) && !defined(__asmjs__) &&             \
     !defined(__wasm__) && !defined(__HAIKU__) && !defined(__sun) &&   \
-    !defined(__VXWORKS__) && !defined(__hexagon__) && !defined(__XTENSA__)
+    !defined(__VXWORKS__) && !defined(__hexagon__) && !defined(__XTENSA__) && \
+    !defined(__FreeBSD__) && !defined(__NetBSD__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
 
