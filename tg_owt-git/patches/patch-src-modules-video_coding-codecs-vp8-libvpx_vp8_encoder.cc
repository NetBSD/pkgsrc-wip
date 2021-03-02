$NetBSD$

--- src/modules/video_coding/codecs/vp8/libvpx_vp8_encoder.cc.orig	2021-03-01 17:40:25.931439319 +0000
+++ src/modules/video_coding/codecs/vp8/libvpx_vp8_encoder.cc
@@ -38,7 +38,7 @@
 #include "rtc_base/logging.h"
 #include "rtc_base/trace_event.h"
 #include "system_wrappers/include/field_trial.h"
-#include "third_party/libyuv/include/libyuv/scale.h"
+#include <libyuv/scale.h>
 #include "vpx/vp8cx.h"
 
 namespace webrtc {
