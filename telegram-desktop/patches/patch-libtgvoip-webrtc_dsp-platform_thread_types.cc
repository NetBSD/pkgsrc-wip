$NetBSD$

--- Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/platform_thread_types.cc.orig	2020-01-21 12:16:27.000000000 +0000
+++ Telegram/ThirdParty/libtgvoip/webrtc_dsp/rtc_base/platform_thread_types.cc
@@ -11,7 +11,12 @@
 #include "rtc_base/platform_thread_types.h"
 
 #if defined(WEBRTC_LINUX)
+#if !defined(__NetBSD__)
 #include <sys/prctl.h>
+#endif //!NetBSD
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif //NetBSD
 #include <sys/syscall.h>
 #endif
 
@@ -27,6 +32,8 @@ PlatformThreadId CurrentThreadId() {
   return gettid();
 #elif defined(WEBRTC_FUCHSIA)
   return zx_thread_self();
+#elif defined(__NetBSD__)
+  return _lwp_self();
 #elif defined(WEBRTC_LINUX)
   return syscall(__NR_gettid);
 #else
