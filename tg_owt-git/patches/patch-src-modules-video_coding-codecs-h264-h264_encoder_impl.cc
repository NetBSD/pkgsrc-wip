$NetBSD$

--- src/modules/video_coding/codecs/h264/h264_encoder_impl.cc.orig	2021-03-01 14:27:20.022364654 +0000
+++ src/modules/video_coding/codecs/h264/h264_encoder_impl.cc
@@ -27,8 +27,8 @@
 #include "rtc_base/logging.h"
 #include "rtc_base/time_utils.h"
 #include "system_wrappers/include/metrics.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
-#include "third_party/libyuv/include/libyuv/scale.h"
+#include <libyuv/convert.h>
+#include <libyuv/scale.h>
 #include "third_party/openh264/src/codec/api/svc/codec_api.h"
 #include "third_party/openh264/src/codec/api/svc/codec_app_def.h"
 #include "third_party/openh264/src/codec/api/svc/codec_def.h"
