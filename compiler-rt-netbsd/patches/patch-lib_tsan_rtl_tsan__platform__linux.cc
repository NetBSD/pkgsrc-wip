$NetBSD$

--- lib/tsan/rtl/tsan_platform_linux.cc.orig	2017-06-03 23:53:57.000000000 +0000
+++ lib/tsan/rtl/tsan_platform_linux.cc
@@ -9,12 +9,12 @@
 //
 // This file is a part of ThreadSanitizer (TSan), a race detector.
 //
-// Linux- and FreeBSD-specific code.
+// Linux-, FreeBSD- and NetBSD-specific code.
 //===----------------------------------------------------------------------===//
 
 
 #include "sanitizer_common/sanitizer_platform.h"
-#if SANITIZER_LINUX || SANITIZER_FREEBSD
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
 
 #include "sanitizer_common/sanitizer_common.h"
 #include "sanitizer_common/sanitizer_libc.h"
@@ -404,4 +404,4 @@ void cur_thread_finalize() {
 
 }  // namespace __tsan
 
-#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD
+#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
