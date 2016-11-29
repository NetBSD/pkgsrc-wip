$NetBSD$

--- chrome/browser/ui/webui/options/browser_options_handler.h.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/webui/options/browser_options_handler.h
@@ -206,7 +206,7 @@ class BrowserOptionsHandler
 
   void ObserveThemeChanged();
   void ThemesReset(const base::ListValue* args);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_POSIX) && !defined(OS_CHROMEOS)
   void ThemesSetNative(const base::ListValue* args);
 #endif
 
