$NetBSD$

--- src/3rdparty/chromium/chrome/common/chrome_features.h.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_features.h
@@ -63,7 +63,7 @@ extern const base::Feature kAppServiceAd
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
 #endif  // defined(OS_WIN) || defined(OS_LINUX)
