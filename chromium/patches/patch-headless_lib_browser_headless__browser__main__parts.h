$NetBSD$

--- headless/lib/browser/headless_browser_main_parts.h.orig	2020-07-15 18:55:58.000000000 +0000
+++ headless/lib/browser/headless_browser_main_parts.h
@@ -32,7 +32,7 @@ class HeadlessBrowserMainParts : public 
 #if defined(OS_MACOSX)
   void PreMainMessageLoopStart() override;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void PostMainMessageLoopStart() override;
 #endif
   void QuitMainMessageLoop();
