$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/base/platform/semaphore.cc.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/v8/src/base/platform/semaphore.cc
@@ -12,6 +12,10 @@
 
 #include <errno.h>
 
+#if V8_OS_NETBSD
+#include <sys/param.h>	// for __NetBSD_Version__
+#endif
+
 #include "src/base/logging.h"
 #include "src/base/platform/elapsed-timer.h"
 #include "src/base/platform/time.h"
