$NetBSD: patch-chrome_test_automation_proxy__launcher.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/test/automation/proxy_launcher.cc.orig	2011-04-13 08:01:56.000000000 +0000
+++ chrome/test/automation/proxy_launcher.cc
@@ -4,6 +4,10 @@
 
 #include "chrome/test/automation/proxy_launcher.h"
 
+#if defined(OS_POSIX)
+#include <signal.h>
+#endif
+
 #include "app/sql/connection.h"
 #include "base/file_util.h"
 #include "base/string_number_conversions.h"
