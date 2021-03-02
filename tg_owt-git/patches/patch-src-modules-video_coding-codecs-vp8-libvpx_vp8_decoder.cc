$NetBSD$

--- src/modules/video_coding/codecs/vp8/libvpx_vp8_decoder.cc.orig	2021-03-01 17:37:17.358424244 +0000
+++ src/modules/video_coding/codecs/vp8/libvpx_vp8_decoder.cc
@@ -30,7 +30,7 @@
 #include "rtc_base/time_utils.h"
 #include "system_wrappers/include/field_trial.h"
 #include "system_wrappers/include/metrics.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
+#include <libyuv/convert.h>
 #include "vpx/vp8.h"
 #include "vpx/vp8dx.h"
 #include "vpx/vpx_decoder.h"
