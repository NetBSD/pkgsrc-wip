$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/drive_metrics_provider_linux.cc.orig	2024-10-26 07:00:07.545185300 +0000
+++ components/metrics/drive_metrics_provider_linux.cc
@@ -4,7 +4,13 @@
 
 #include "components/metrics/drive_metrics_provider.h"
 
+#if BUILDFLAG(IS_BSD)
+#include <sys/types.h>
+#define MAJOR(dev) major(dev)
+#define MINOR(dev) minor(dev)
+#else
 #include <linux/kdev_t.h>  // For MAJOR()/MINOR().
+#endif
 #include <sys/stat.h>
 #include <string>
 
