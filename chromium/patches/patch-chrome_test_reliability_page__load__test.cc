$NetBSD: patch-chrome_test_reliability_page__load__test.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/reliability/page_load_test.cc.orig	2011-04-13 08:01:56.000000000 +0000
+++ chrome/test/reliability/page_load_test.cc
@@ -186,7 +186,7 @@ class PageLoadTest : public UITest {
     file_info.reset(
         FileVersionInfo::CreateFileVersionInfo(FilePath(kChromeDll)));
     last_change = WideToASCII(file_info->last_change());
-#elif defined(OS_LINUX) || defined(OS_MACOSX)
+#elif defined(OS_LINUX) || defined(OS_BSD) || defined(OS_MACOSX)
     // TODO(fmeawad): On Mac, the version retrieved here belongs to the test
     // module and not the chrome binary, need to be changed to chrome binary
     // instead.
