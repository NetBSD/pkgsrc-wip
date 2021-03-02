$NetBSD$

--- src/modules/video_processing/video_denoiser.cc.orig	2021-03-01 17:55:04.495980510 +0000
+++ src/modules/video_processing/video_denoiser.cc
@@ -14,7 +14,7 @@
 #include <string.h>
 
 #include "api/video/i420_buffer.h"
-#include "third_party/libyuv/include/libyuv/planar_functions.h"
+#include <libyuv/planar_functions.h>
 
 namespace webrtc {
 
