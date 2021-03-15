$NetBSD$

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc.orig	2020-07-15 19:01:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/ip_address.cc
@@ -11,6 +11,9 @@
 #if defined(WEBRTC_POSIX)
 #include <netinet/in.h>
 #include <sys/socket.h>
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
 #ifdef OPENBSD
 #include <netinet/in_systm.h>
 #endif
