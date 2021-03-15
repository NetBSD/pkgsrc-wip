$NetBSD$

--- src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc.orig	2020-07-15 18:56:48.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/html/canvas/canvas_async_blob_creator.cc
@@ -43,7 +43,7 @@ constexpr base::TimeDelta kEncodeRowSlac
     base::TimeDelta::FromMicroseconds(100);
 
 /* The value is based on user statistics on Nov 2017. */
-#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN))
+#if (defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)) || defined(OS_BSD)
 const double kIdleTaskStartTimeoutDelayMs = 1000.0;
 #else
 const double kIdleTaskStartTimeoutDelayMs = 4000.0;  // For ChromeOS, Mobile
