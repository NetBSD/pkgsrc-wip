$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/net_helpers.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ third_party/webrtc/rtc_base/net_helpers.cc
@@ -21,6 +21,7 @@
 #endif
 #if defined(WEBRTC_POSIX) && !defined(__native_client__)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX) && !defined(__native_client__)
 
 namespace webrtc {
