$NetBSD$

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -180,7 +180,7 @@
 #include "chrome/browser/ui/views/sync/one_click_signin_dialog_view.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/native_theme/native_theme_dark_aura.h"
 #endif
 
@@ -1990,7 +1990,7 @@ void BrowserView::OnThemeChanged() {
 #if defined(OS_WIN)
     ui::NativeThemeDarkWin::instance()->NotifyObservers();
     ui::NativeThemeWin::instance()->NotifyObservers();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     ui::NativeThemeDarkAura::instance()->NotifyObservers();
     ui::NativeThemeAura::instance()->NotifyObservers();
 #endif
