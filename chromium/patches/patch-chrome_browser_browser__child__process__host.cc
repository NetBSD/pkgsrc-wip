$NetBSD: patch-chrome_browser_browser__child__process__host.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/browser_child_process_host.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/browser_child_process_host.cc
@@ -25,9 +25,9 @@
 #include "chrome/common/result_codes.h"
 #include "chrome/installer/util/google_update_settings.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 
 namespace {
 
