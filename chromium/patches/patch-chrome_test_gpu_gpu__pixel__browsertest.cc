$NetBSD: patch-chrome_test_gpu_gpu__pixel__browsertest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/gpu/gpu_pixel_browsertest.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/test/gpu/gpu_pixel_browsertest.cc
@@ -206,7 +206,7 @@ class GpuPixelBrowserTest : public InPro
       const char* os_label = "win";
 #elif defined(OS_MACOSX)
       const char* os_label = "mac";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       const char* os_label = "linux";
 #else
 #error "Not implemented for this platform"
