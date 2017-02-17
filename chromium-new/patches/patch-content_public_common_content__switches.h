$NetBSD$

--- content/public/common/content_switches.h.orig	2017-02-02 02:02:54.000000000 +0000
+++ content/public/common/content_switches.h
@@ -293,7 +293,7 @@ CONTENT_EXPORT extern const char kDisabl
 CONTENT_EXPORT extern const char kDisableVaapiAcceleratedVideoEncode[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
