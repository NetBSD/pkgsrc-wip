$NetBSD$

--- media/capture/video/linux/v4l2_capture_delegate.h.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/capture/video/linux/v4l2_capture_delegate.h
@@ -14,7 +14,7 @@
 #include "build/build_config.h"
 #include "media/capture/video/video_capture_device.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
