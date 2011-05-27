$NetBSD: patch-chrome_test_testing__browser__process.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- chrome/test/testing_browser_process.cc.orig	2011-05-24 08:01:56.000000000 +0000
+++ chrome/test/testing_browser_process.cc
@@ -40,7 +40,7 @@ IOThread* TestingBrowserProcess::io_thre
   return NULL;
 }
 
-#if defined(OS_LINUX)
+#if defined(USE_X11)
 base::Thread* TestingBrowserProcess::background_x11_thread() {
   return NULL;
 }
