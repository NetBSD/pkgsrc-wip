$NetBSD$

--- third_party/webrtc/base/linux.cc.orig	2017-02-02 02:03:57.000000000 +0000
+++ third_party/webrtc/base/linux.cc
@@ -8,7 +8,7 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 #include "webrtc/base/linux.h"
 
 #include <ctype.h>
@@ -261,4 +261,4 @@ int ReadCpuMaxFreq() {
 
 }  // namespace rtc
 
-#endif  // defined(WEBRTC_LINUX)
+#endif  // defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
