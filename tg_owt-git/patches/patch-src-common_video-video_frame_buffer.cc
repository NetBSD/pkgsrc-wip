$NetBSD$

--- src/common_video/video_frame_buffer.cc.orig	2021-03-01 18:05:07.829012577 +0000
+++ src/common_video/video_frame_buffer.cc
@@ -12,7 +12,7 @@
 #include "api/video/i420_buffer.h"
 #include "rtc_base/checks.h"
 #include "rtc_base/ref_counted_object.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
+#include <libyuv/convert.h>
 
 namespace webrtc {
 
