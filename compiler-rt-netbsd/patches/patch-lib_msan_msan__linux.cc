$NetBSD$

--- lib/msan/msan_linux.cc.orig	2017-06-03 23:53:56.000000000 +0000
+++ lib/msan/msan_linux.cc
@@ -13,7 +13,7 @@
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
