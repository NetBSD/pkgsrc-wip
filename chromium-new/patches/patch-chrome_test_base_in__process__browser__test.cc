$NetBSD$

--- chrome/test/base/in_process_browser_test.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/test/base/in_process_browser_test.cc
@@ -88,6 +88,10 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 const char kBrowserTestType[] = "browser";
 
