$NetBSD$

--- third_party/webrtc/base/linux.h.orig	2016-06-24 01:04:14.000000000 +0000
+++ third_party/webrtc/base/linux.h
@@ -11,7 +11,7 @@
 #ifndef WEBRTC_BASE_LINUX_H_
 #define WEBRTC_BASE_LINUX_H_
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include <string>
 #include <map>
 #include <vector>
@@ -114,5 +114,5 @@ int ReadCpuMaxFreq();
 
 }  // namespace rtc
 
-#endif  // defined(WEBRTC_LINUX)
+#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #endif  // WEBRTC_BASE_LINUX_H_
