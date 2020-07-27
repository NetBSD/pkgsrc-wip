$NetBSD$

--- chrome/browser/ui/webui/settings/appearance_handler.h.orig	2020-07-08 21:40:36.000000000 +0000
+++ chrome/browser/ui/webui/settings/appearance_handler.h
@@ -36,7 +36,7 @@ class AppearanceHandler : public Setting
   // Changes the UI theme of the browser to the default theme.
   void HandleUseDefaultTheme(const base::ListValue* args);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Changes the UI theme of the browser to the system (GTK+) theme.
   void HandleUseSystemTheme(const base::ListValue* args);
 #endif
