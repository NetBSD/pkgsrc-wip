$NetBSD$

--- skia/ext/platform_canvas.h.orig	2016-11-10 20:02:16.000000000 +0000
+++ skia/ext/platform_canvas.h
@@ -73,7 +73,7 @@ enum OnFailureType {
                                         uint8_t* context,
                                         OnFailureType failure_type);
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-      defined(__sun) || defined(ANDROID)
+      defined(__sun) || defined(ANDROID) || defined(__NetBSD__)
   // Linux ---------------------------------------------------------------------
 
   // Construct a canvas from the given memory region. The memory is not cleared
