$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/capture/video/linux/video_capture_device_linux.cc.orig	2024-12-03 23:30:23.089044800 +0000
+++ media/capture/video/linux/video_capture_device_linux.cc
@@ -15,7 +15,7 @@
 #include "build/build_config.h"
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
-#if BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
