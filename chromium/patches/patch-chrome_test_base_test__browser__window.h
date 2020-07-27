$NetBSD$

--- chrome/test/base/test_browser_window.h.orig	2020-07-08 21:40:37.000000000 +0000
+++ chrome/test/base/test_browser_window.h
@@ -178,7 +178,7 @@ class TestBrowserWindow : public Browser
       bool is_source_keyboard) override {}
 
 #if defined(OS_CHROMEOS) || defined(OS_MACOSX) || defined(OS_WIN) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
   void ShowHatsBubble(const std::string& site_id) override {}
 #endif
 
