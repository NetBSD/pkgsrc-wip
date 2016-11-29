$NetBSD$

--- base/test/launcher/test_launcher.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/test/launcher/test_launcher.cc
@@ -55,6 +55,10 @@
 #include "base/win/windows_version.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <signal.h>
+#endif
+
 namespace base {
 
 // See https://groups.google.com/a/chromium.org/d/msg/chromium-dev/nkdTP7sstSc/uT3FaE_sgkAJ .
