$NetBSD: patch-content_browser_browser__child__process__host.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/browser/browser_child_process_host.cc.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/browser/browser_child_process_host.cc
@@ -25,9 +25,9 @@
 #include "chrome/installer/util/google_update_settings.h"
 #include "content/browser/browser_thread.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/linux_util.h"
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 
 namespace {
 
