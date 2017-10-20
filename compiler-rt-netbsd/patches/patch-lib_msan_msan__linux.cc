$NetBSD$

--- lib/msan/msan_linux.cc.orig	2017-10-20 10:51:37.065317095 +0000
+++ lib/msan/msan_linux.cc
@@ -9,11 +9,11 @@
 //
 // This file is a part of MemorySanitizer.
 //
-// Linux- and FreeBSD-specific code.
+// Linux-, NetBSD- and FreeBSD-specific code.
 //===----------------------------------------------------------------------===//
 
 #include "sanitizer_common/sanitizer_platform.h"
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "msan.h"
 #include "msan_thread.h"
@@ -213,4 +213,4 @@ void MsanTSDDtor(void *tsd) {
 
 } // namespace __msan
 
-#endif // SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
