$NetBSD$

--- skia/ext/platform_canvas.h.orig	2016-06-24 01:02:27.000000000 +0000
+++ skia/ext/platform_canvas.h
@@ -71,7 +71,7 @@ enum OnFailureType {
                                         uint8_t* context,
                                         OnFailureType failure_type);
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-      defined(__sun) || defined(ANDROID)
+      defined(__sun) || defined(ANDROID) || defined(OS_NETBSD)
   // Linux ---------------------------------------------------------------------
 
   // Construct a canvas from the given memory region. The memory is not cleared
