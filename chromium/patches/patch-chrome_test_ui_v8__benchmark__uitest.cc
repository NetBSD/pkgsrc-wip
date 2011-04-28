$NetBSD: patch-chrome_test_ui_v8__benchmark__uitest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/ui/v8_benchmark_uitest.cc.orig	2011-04-13 08:01:56.000000000 +0000
+++ chrome/test/ui/v8_benchmark_uitest.cc
@@ -131,7 +131,7 @@ class V8BenchmarkReferenceTest : public 
     dir = dir.AppendASCII("reference_build");
 #if defined(OS_WIN)
     dir = dir.AppendASCII("chrome");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     dir = dir.AppendASCII("chrome_linux");
 #elif defined(OS_MACOSX)
     dir = dir.AppendASCII("chrome_mac");
