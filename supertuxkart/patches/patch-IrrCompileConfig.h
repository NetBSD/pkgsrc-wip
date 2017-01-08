$NetBSD$
Already upstream
--- lib/irrlicht/include/IrrCompileConfig.h.orig	2017-01-06 15:41:37.112464903 +0000
+++ lib/irrlicht/include/IrrCompileConfig.h	2017-01-06 15:42:06.901625718 +0000
@@ -99,7 +99,7 @@
 
 #if !defined(_IRR_WINDOWS_API_) && !defined(_IRR_OSX_PLATFORM_)
 #ifndef _IRR_SOLARIS_PLATFORM_
-#if !defined(__linux__) && !defined(__FreeBSD__)
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #define _IRR_LINUX_PLATFORM_
 #endif
 #endif
