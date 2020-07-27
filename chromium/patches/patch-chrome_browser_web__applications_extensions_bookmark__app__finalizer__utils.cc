$NetBSD$

--- chrome/browser/web_applications/extensions/bookmark_app_finalizer_utils.cc.orig	2020-07-08 21:40:36.000000000 +0000
+++ chrome/browser/web_applications/extensions/bookmark_app_finalizer_utils.cc
@@ -15,7 +15,7 @@ namespace {
 
 #if !defined(OS_CHROMEOS)
 bool CanOsAddDesktopShortcuts() {
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   return true;
 #else
   return false;
