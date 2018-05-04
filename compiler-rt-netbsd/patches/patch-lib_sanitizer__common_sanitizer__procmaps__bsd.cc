$NetBSD$

--- lib/sanitizer_common/sanitizer_procmaps_bsd.cc.orig	2018-05-04 08:00:15.481287563 +0000
+++ lib/sanitizer_common/sanitizer_procmaps_bsd.cc
@@ -19,6 +19,10 @@
 #endif
 #include "sanitizer_procmaps.h"
 
+#if SANITIZER_NETBSD
+#define sysctl _sysctl // Use an internal symbol to bypass the interceptor
+#endif
+
 // clang-format off
 #include <sys/types.h>
 #include <sys/sysctl.h>
