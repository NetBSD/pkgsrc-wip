$NetBSD: patch-chrome_test_ui_sunspider__uitest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/ui/sunspider_uitest.cc.orig	2011-04-13 08:01:56.000000000 +0000
+++ chrome/test/ui/sunspider_uitest.cc
@@ -129,7 +129,7 @@ class SunSpiderReferenceTest : public Su
     dir = dir.AppendASCII("reference_build");
 #if defined(OS_WIN)
     dir = dir.AppendASCII("chrome");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     dir = dir.AppendASCII("chrome_linux");
 #elif defined(OS_MACOSX)
     dir = dir.AppendASCII("chrome_mac");
