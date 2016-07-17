$NetBSD$

--- chrome/browser/extensions/window_open_apitest.cc.orig	2016-06-24 01:02:12.000000000 +0000
+++ chrome/browser/extensions/window_open_apitest.cc
@@ -294,7 +294,7 @@ IN_PROC_BROWSER_TEST_F(WindowOpenPanelDi
       << message_;
 }
 
-#if defined(USE_ASH_PANELS) || defined(OS_LINUX)
+#if defined(USE_ASH_PANELS) || defined(OS_LINUX) || defined(OS_FREEBSD)
 // On Ash, this currently fails because we're currently opening new panel
 // windows as popup windows instead.
 // We're also failing on Linux-aura due to the panel is not opened in the
