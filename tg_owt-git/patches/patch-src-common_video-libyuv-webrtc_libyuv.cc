$NetBSD$

--- src/common_video/libyuv/webrtc_libyuv.cc.orig	2021-03-01 18:01:05.371056755 +0000
+++ src/common_video/libyuv/webrtc_libyuv.cc
@@ -16,7 +16,7 @@
 #include "common_video/include/video_frame_buffer.h"
 #include "rtc_base/bind.h"
 #include "rtc_base/checks.h"
-#include "third_party/libyuv/include/libyuv.h"
+#include <libyuv.h>
 
 namespace webrtc {
 
