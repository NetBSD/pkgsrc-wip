$NetBSD$

--- lib/lsan/lsan_interceptors.cc.orig	2017-08-21 23:23:37.000000000 +0000
+++ lib/lsan/lsan_interceptors.cc
@@ -20,7 +20,11 @@
 #include "sanitizer_common/sanitizer_internal_defs.h"
 #include "sanitizer_common/sanitizer_linux.h"
 #include "sanitizer_common/sanitizer_platform_interceptors.h"
+#if SANITIZER_NETBSD
+#include "sanitizer_common/sanitizer_platform_limits_netbsd.h"
+#else
 #include "sanitizer_common/sanitizer_platform_limits_posix.h"
+#endif
 #include "sanitizer_common/sanitizer_posix.h"
 #include "sanitizer_common/sanitizer_tls_get_addr.h"
 #include "lsan.h"
