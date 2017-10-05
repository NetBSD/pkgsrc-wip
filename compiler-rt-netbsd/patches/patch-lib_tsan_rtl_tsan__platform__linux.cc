$NetBSD$

--- lib/tsan/rtl/tsan_platform_linux.cc.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/tsan/rtl/tsan_platform_linux.cc
@@ -14,11 +14,12 @@
 
 
 #include "sanitizer_common/sanitizer_platform.h"
-#if SANITIZER_LINUX || SANITIZER_FREEBSD
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
 
 #include "sanitizer_common/sanitizer_common.h"
 #include "sanitizer_common/sanitizer_libc.h"
 #include "sanitizer_common/sanitizer_linux.h"
+#include "sanitizer_common/sanitizer_platform_limits_netbsd.h"
 #include "sanitizer_common/sanitizer_platform_limits_posix.h"
 #include "sanitizer_common/sanitizer_posix.h"
 #include "sanitizer_common/sanitizer_procmaps.h"
@@ -401,4 +402,4 @@ void cur_thread_finalize() {
 
 }  // namespace __tsan
 
-#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD
+#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
