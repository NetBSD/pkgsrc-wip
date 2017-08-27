$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.h.orig	2017-08-08 20:43:41.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.h
@@ -18,7 +18,11 @@
 #include "sanitizer_common.h"
 #include "sanitizer_internal_defs.h"
 #include "sanitizer_posix.h"
+#if SANITIZER_NETBSD
+#include "sanitizer_platform_limits_netbsd.h"
+#else
 #include "sanitizer_platform_limits_posix.h"
+#endif
 
 struct link_map;  // Opaque type returned by dlopen().
 
