$NetBSD$

--- lib/sanitizer_common/sanitizer_posix_libcdep.cc.orig	2017-07-07 06:32:45.000000000 +0000
+++ lib/sanitizer_common/sanitizer_posix_libcdep.cc
@@ -18,7 +18,13 @@
 
 #include "sanitizer_common.h"
 #include "sanitizer_flags.h"
+
+#if SANITIZER_NETBSD
+#include "sanitizer_platform_limits_netbsd.h"
+#else
 #include "sanitizer_platform_limits_posix.h"
+#endif
+
 #include "sanitizer_posix.h"
 #include "sanitizer_procmaps.h"
 #include "sanitizer_stacktrace.h"
