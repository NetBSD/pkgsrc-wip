$NetBSD$

--- chrome/test/chromedriver/chrome_launcher.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/test/chromedriver/chrome_launcher.cc
@@ -69,6 +69,10 @@
 #include "chrome/test/chromedriver/keycode_text_conversion.h"
 #endif
 
+#if defined(OS_BSD)
+#include <sys/wait.h>
+#endif
+
 namespace {
 
 const char* const kCommonSwitches[] = {
