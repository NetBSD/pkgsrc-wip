$NetBSD$

--- content/public/common/content_switches.h.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/public/common/content_switches.h
@@ -296,7 +296,7 @@ CONTENT_EXPORT extern const char kDisabl
 CONTENT_EXPORT extern const char kDisableVaapiAcceleratedVideoEncode[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
