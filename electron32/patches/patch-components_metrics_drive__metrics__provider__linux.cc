$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/metrics/drive_metrics_provider_linux.cc.orig	2024-10-18 12:34:06.874353600 +0000
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
 
