$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/trap-handler/trap-handler.h.orig	2024-07-24 02:47:46.359158300 +0000
+++ v8/src/trap-handler/trap-handler.h
@@ -20,7 +20,7 @@ namespace trap_handler {
 // X64 on Linux, Windows, MacOS, FreeBSD.
 #if V8_HOST_ARCH_X64 && V8_TARGET_ARCH_X64 &&                        \
     ((V8_OS_LINUX && !V8_OS_ANDROID) || V8_OS_WIN || V8_OS_DARWIN || \
-     V8_OS_FREEBSD)
+     V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD)
 #define V8_TRAP_HANDLER_SUPPORTED true
 // Arm64 (non-simulator) on Mac and Linux.
 #elif V8_TARGET_ARCH_ARM64 && V8_HOST_ARCH_ARM64 && \
