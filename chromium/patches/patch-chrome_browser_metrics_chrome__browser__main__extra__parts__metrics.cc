$NetBSD$

--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2020-07-15 18:56:45.000000000 +0000
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -50,7 +50,9 @@
 
 #if defined(OS_LINUX) && !defined(OS_CHROMEOS)
 #include <gnu/libc-version.h>
+#endif
 
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
