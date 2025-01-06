$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/win/titlebar_config.cc.orig	2024-10-18 12:34:03.776040300 +0000
+++ chrome/browser/win/titlebar_config.cc
@@ -12,8 +12,10 @@
 
 bool ShouldBrowserCustomDrawTitlebar(BrowserView* browser_view) {
   return !ShouldDefaultThemeUseMicaTitlebar() ||
+#if 0
          !ThemeServiceFactory::GetForProfile(browser_view->GetProfile())
               ->UsingSystemTheme() ||
+#endif
          (!browser_view->browser()->is_type_normal() &&
           !browser_view->browser()->is_type_popup() &&
           !browser_view->browser()->is_type_devtools());
