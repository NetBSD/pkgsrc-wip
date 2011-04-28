$NetBSD: patch-chrome_gpu_x__util.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/gpu/x_util.h.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/gpu/x_util.h
@@ -12,7 +12,7 @@
 #include "build/build_config.h"
 #include "chrome/gpu/gpu_config.h"
 
-#if defined(OS_LINUX)
+#if defined(USE_X11)
 
 // Forward declares ------------------------------------------------------------
 //
@@ -42,6 +42,6 @@ class ScopedPtrXFree {
   void operator()(void* x) const;
 };
 
-#endif  // OS_LINUX
+#endif  // USE_X11
 
 #endif  // CHROME_GPU_X_UTIL_H_
