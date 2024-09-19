$NetBSD$

--- src/modules/video_coding/codecs/vp9/libvpx_vp9_decoder.cc.orig	2021-03-01 17:43:35.321419217 +0000
+++ src/modules/video_coding/codecs/vp9/libvpx_vp9_decoder.cc
@@ -24,9 +24,9 @@
 #include "rtc_base/checks.h"
 #include "rtc_base/keep_ref_until_done.h"
 #include "rtc_base/logging.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
-#include "vpx/vp8dx.h"
-#include "vpx/vpx_decoder.h"
+#include <libyuv/convert.h>
+#include <vpx/vp8dx.h>
+#include <vpx/vpx_decoder.h>
 
 namespace webrtc {
 namespace {
