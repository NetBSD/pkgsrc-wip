$NetBSD$

--- src/modules/desktop_capture/desktop_frame_rotation.cc.orig	2021-03-01 21:03:58.539561377 +0000
+++ src/modules/desktop_capture/desktop_frame_rotation.cc
@@ -11,7 +11,7 @@
 #include "modules/desktop_capture/desktop_frame_rotation.h"
 
 #include "rtc_base/checks.h"
-#include "third_party/libyuv/include/libyuv/rotate_argb.h"
+#include <libyuv/rotate_argb.h>
 
 namespace webrtc {
 
