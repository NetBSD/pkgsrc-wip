$NetBSD$

--- third_party/webrtc/base/ifaddrs_converter.h.orig	2016-06-24 01:04:14.000000000 +0000
+++ third_party/webrtc/base/ifaddrs_converter.h
@@ -14,6 +14,8 @@
 #if defined(WEBRTC_ANDROID)
 #include "webrtc/base/ifaddrs-android.h"
 #else
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <ifaddrs.h>
 #endif  // WEBRTC_ANDROID
 
