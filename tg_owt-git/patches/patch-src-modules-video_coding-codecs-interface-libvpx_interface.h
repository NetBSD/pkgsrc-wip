$NetBSD$

--- src/modules/video_coding/codecs/interface/libvpx_interface.h.orig	2021-03-01 14:35:01.569551745 +0000
+++ src/modules/video_coding/codecs/interface/libvpx_interface.h
@@ -15,10 +15,10 @@
 
 #include <memory>
 
-#include "vpx/vp8cx.h"
-#include "vpx/vpx_codec.h"
-#include "vpx/vpx_encoder.h"
-#include "vpx/vpx_image.h"
+#include <vpx/vp8cx.h>
+#include <vpx/vpx_codec.h>
+#include <vpx/vpx_encoder.h>
+#include <vpx/vpx_image.h>
 
 namespace webrtc {
 
