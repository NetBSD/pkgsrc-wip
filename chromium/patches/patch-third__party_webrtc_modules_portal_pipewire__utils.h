$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/modules/portal/pipewire_utils.h.orig	2025-09-29 17:05:47.000000000 +0000
+++ third_party/webrtc/modules/portal/pipewire_utils.h
@@ -11,7 +11,9 @@
 #ifndef MODULES_PORTAL_PIPEWIRE_UTILS_H_
 #define MODULES_PORTAL_PIPEWIRE_UTILS_H_
 
+#if defined(__linux__)
 #include <asm-generic/ioctl.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 
