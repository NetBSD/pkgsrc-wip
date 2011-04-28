$NetBSD: patch-chrome_test_ui_ui__test.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/ui/ui_test.cc.orig	2011-04-13 08:01:56.000000000 +0000
+++ chrome/test/ui/ui_test.cc
@@ -66,7 +66,7 @@ const wchar_t UITestBase::kFailedNoCrash
     L"NOTE: This test is expected to fail if crash_service.exe is not "
     L"running. Start it manually before running this test (see the build "
     L"output directory).";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     L"NOTE: This test is expected to fail if breakpad is not built in "
     L"or if chromium is not running headless (try CHROME_HEADLESS=1).";
 #else
