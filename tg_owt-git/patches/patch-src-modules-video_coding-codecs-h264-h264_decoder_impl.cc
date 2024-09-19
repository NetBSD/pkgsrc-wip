$NetBSD$

--- src/modules/video_coding/codecs/h264/h264_decoder_impl.cc.orig	2021-03-01 14:22:37.313952341 +0000
+++ src/modules/video_coding/codecs/h264/h264_decoder_impl.cc
@@ -36,7 +36,7 @@ extern "C" {
 #include "rtc_base/logging.h"
 #include "system_wrappers/include/field_trial.h"
 #include "system_wrappers/include/metrics.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
+#include <libyuv/convert.h>
 
 namespace webrtc {
 
