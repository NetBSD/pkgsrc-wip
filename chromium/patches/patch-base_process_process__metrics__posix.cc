$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_metrics_posix.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/process/process_metrics_posix.cc
@@ -21,6 +21,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -136,7 +138,7 @@ size_t ProcessMetrics::GetMallocUsage() 
   return stats.size_in_use;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   return GetMallocUsageMallinfo();
-#elif BUILDFLAG(IS_FUCHSIA)
+#elif BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // TODO(fuchsia): Not currently exposed. https://crbug.com/735087.
   return 0;
 #endif
