$NetBSD: patch-chrome_browser_shell__integration__unittest.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/shell_integration_unittest.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/shell_integration_unittest.cc
@@ -21,13 +21,13 @@
 
 #if defined(OS_WIN)
 #include "chrome/installer/util/browser_distribution.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #define FPL FILE_PATH_LITERAL
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Provides mock environment variables values based on a stored map.
