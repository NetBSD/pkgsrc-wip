$NetBSD$

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.h.orig	2020-07-15 19:01:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.h
@@ -27,6 +27,10 @@
 #include "rtc_base/third_party/sigslot/sigslot.h"
 
 #if defined(WEBRTC_POSIX)
+#include <sys/types.h>
+#endif
+
+#if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
 
