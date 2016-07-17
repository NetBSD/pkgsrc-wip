$NetBSD$

--- base/test/launcher/test_launcher.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/test/launcher/test_launcher.cc
@@ -53,6 +53,10 @@
 #include "base/win/windows_version.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
