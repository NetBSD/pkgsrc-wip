$NetBSD$

--- src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h.orig	2020-07-15 19:01:32.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/libANGLE/renderer/driver_utils.h
@@ -139,7 +139,7 @@ inline bool IsWindows()
 
 inline bool IsLinux()
 {
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_POSIX)
     return true;
 #else
     return false;
