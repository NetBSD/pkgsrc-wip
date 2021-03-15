$NetBSD$

--- src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.h.orig	2020-07-15 18:55:59.000000000 +0000
+++ src/3rdparty/chromium/media/capture/video/linux/v4l2_capture_delegate.h
@@ -20,7 +20,7 @@
 #include "media/capture/video/linux/v4l2_capture_device_impl.h"
 #include "media/capture/video/video_capture_device.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
