$NetBSD$

--- chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc
@@ -10,7 +10,7 @@ bool OpaqueBrowserFrameViewPlatformSpeci
   return false;
 }
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 
 // static
 OpaqueBrowserFrameViewPlatformSpecific*
