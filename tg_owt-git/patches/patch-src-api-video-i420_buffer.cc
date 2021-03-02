$NetBSD$

--- src/api/video/i420_buffer.cc.orig	2021-03-01 13:10:12.870350475 +0000
+++ src/api/video/i420_buffer.cc
@@ -16,9 +16,9 @@
 
 #include "rtc_base/checks.h"
 #include "rtc_base/ref_counted_object.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
-#include "third_party/libyuv/include/libyuv/planar_functions.h"
-#include "third_party/libyuv/include/libyuv/scale.h"
+#include <libyuv/convert.h>
+#include <libyuv/planar_functions.h>
+#include <libyuv/scale.h>
 
 // Aligning pointer to 64 bytes for improved performance, e.g. use SIMD.
 static const int kBufferAlignment = 64;
