$NetBSD$

--- content/public/common/content_switches.h.orig	2016-06-24 01:02:21.000000000 +0000
+++ content/public/common/content_switches.h
@@ -277,7 +277,7 @@ CONTENT_EXPORT extern const char kDisabl
 CONTENT_EXPORT extern const char kDisableVaapiAcceleratedVideoEncode[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 CONTENT_EXPORT extern const char kEnableSpeechDispatcher[];
 #endif
 
