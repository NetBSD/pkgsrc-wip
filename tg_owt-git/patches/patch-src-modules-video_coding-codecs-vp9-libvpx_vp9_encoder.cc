$NetBSD$

--- src/modules/video_coding/codecs/vp9/libvpx_vp9_encoder.cc.orig	2021-03-01 17:50:39.264712191 +0000
+++ src/modules/video_coding/codecs/vp9/libvpx_vp9_encoder.cc
@@ -38,9 +38,9 @@
 #include "rtc_base/strings/string_builder.h"
 #include "rtc_base/time_utils.h"
 #include "rtc_base/trace_event.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
-#include "vpx/vp8cx.h"
-#include "vpx/vpx_encoder.h"
+#include <libyuv/convert.h>
+#include <vpx/vp8cx.h>
+#include <vpx/vpx_encoder.h>
 
 namespace webrtc {
 
