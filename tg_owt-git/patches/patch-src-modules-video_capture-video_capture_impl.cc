$NetBSD$

--- src/modules/video_capture/video_capture_impl.cc.orig	2021-03-01 13:53:07.534581269 +0000
+++ src/modules/video_capture/video_capture_impl.cc
@@ -21,7 +21,7 @@
 #include "rtc_base/ref_counted_object.h"
 #include "rtc_base/time_utils.h"
 #include "rtc_base/trace_event.h"
-#include "third_party/libyuv/include/libyuv.h"
+#include <libyuv.h>
 
 namespace webrtc {
 namespace videocapturemodule {
