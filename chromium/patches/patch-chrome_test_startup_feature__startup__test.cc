$NetBSD: patch-chrome_test_startup_feature__startup__test.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/startup/feature_startup_test.cc.orig	2011-04-13 08:01:45.000000000 +0000
+++ chrome/test/startup/feature_startup_test.cc
@@ -198,7 +198,7 @@ TEST_F(NewTabUIStartupTest, FLAKY_NewTab
   RunNewTabTimingTest();
 }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
 TEST_F(NewTabUIStartupTest, GtkThemeCold) {
   RunStartupTest("tab_gtk_theme_cold", false /* cold */,
                  false /* not important */,
