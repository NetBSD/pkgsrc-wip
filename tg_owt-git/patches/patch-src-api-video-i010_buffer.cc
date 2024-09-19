$NetBSD$

--- src/api/video/i010_buffer.cc.orig	2021-02-03 11:42:41.000000000 +0000
+++ src/api/video/i010_buffer.cc
@@ -14,8 +14,8 @@
 #include "api/video/i420_buffer.h"
 #include "rtc_base/checks.h"
 #include "rtc_base/ref_counted_object.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
-#include "third_party/libyuv/include/libyuv/scale.h"
+#include <libyuv/convert.h>
+#include <libyuv/scale.h>
 
 // Aligning pointer to 64 bytes for improved performance, e.g. use SIMD.
 static const int kBufferAlignment = 64;
