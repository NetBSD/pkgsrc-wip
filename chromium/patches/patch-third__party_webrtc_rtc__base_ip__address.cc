$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/ip_address.cc.orig	2024-08-21 22:48:15.268425200 +0000
+++ third_party/webrtc/rtc_base/ip_address.cc
@@ -13,7 +13,8 @@
 #include <sys/socket.h>
 
 #include "absl/strings/string_view.h"
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #ifndef __native_client__
