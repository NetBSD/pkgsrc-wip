$NetBSD$

--- src/api/video/nv12_buffer.cc.orig	2021-03-01 13:24:35.081902127 +0000
+++ src/api/video/nv12_buffer.cc
@@ -13,8 +13,8 @@
 #include "api/video/i420_buffer.h"
 #include "rtc_base/checks.h"
 #include "rtc_base/ref_counted_object.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
-#include "third_party/libyuv/include/libyuv/scale.h"
+#include <libyuv/convert.h>
+#include <libyuv/scale.h>
 
 namespace webrtc {
 
