$NetBSD$

--- toolkit/components/perfmonitoring/nsPerformanceStats.cpp.orig	2015-10-22 11:46:58.000000000 +0000
+++ toolkit/components/perfmonitoring/nsPerformanceStats.cpp
@@ -43,9 +43,11 @@
 #include <mach/thread_info.h>
 #endif // defined(XP_MACOSX)
 
+#if defined(XP_UNIX)
+#include <sys/resource.h>
+#endif // defined(XP_UNIX)
 #if defined(XP_LINUX)
 #include <sys/time.h>
-#include <sys/resource.h>
 #endif // defined(XP_LINUX)
 /* ------------------------------------------------------
  *
