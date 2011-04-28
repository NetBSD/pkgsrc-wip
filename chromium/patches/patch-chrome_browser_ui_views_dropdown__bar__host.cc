$NetBSD: patch-chrome_browser_ui_views_dropdown__bar__host.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/dropdown_bar_host.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/dropdown_bar_host.cc
@@ -19,7 +19,7 @@
 
 #if defined(OS_WIN)
 #include "base/win/scoped_gdi_object.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/base/gtk/scoped_handle_gtk.h"
 #endif
 
@@ -27,7 +27,7 @@ namespace {
 
 #if defined(OS_WIN)
 typedef base::win::ScopedRegion ScopedPlatformRegion;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 typedef ui::ScopedRegion ScopedPlatformRegion;
 #endif
 
