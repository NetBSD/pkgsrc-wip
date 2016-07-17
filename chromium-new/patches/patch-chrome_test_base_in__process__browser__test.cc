$NetBSD$

--- chrome/test/base/in_process_browser_test.cc.orig	2016-06-24 01:02:15.000000000 +0000
+++ chrome/test/base/in_process_browser_test.cc
@@ -89,6 +89,10 @@
 
 namespace {
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 // Passed as value of kTestType.
 const char kBrowserTestType[] = "browser";
 
