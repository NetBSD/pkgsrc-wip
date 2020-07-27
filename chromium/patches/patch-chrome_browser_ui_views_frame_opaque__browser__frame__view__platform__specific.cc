$NetBSD$

--- chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc.orig	2020-07-08 21:40:36.000000000 +0000
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 
 // static
 std::unique_ptr<OpaqueBrowserFrameViewPlatformSpecific>
