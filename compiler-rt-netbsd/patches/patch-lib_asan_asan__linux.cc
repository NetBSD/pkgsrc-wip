$NetBSD$

--- lib/asan/asan_linux.cc.orig	2017-06-03 23:53:58.000000000 +0000
+++ lib/asan/asan_linux.cc
@@ -13,13 +13,14 @@
 //===----------------------------------------------------------------------===//
 
 #include "sanitizer_common/sanitizer_platform.h"
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "asan_interceptors.h"
 #include "asan_internal.h"
 #include "asan_thread.h"
 #include "sanitizer_common/sanitizer_flags.h"
 #include "sanitizer_common/sanitizer_freebsd.h"
+#include "sanitizer_common/sanitizer_netbsd.h"
 #include "sanitizer_common/sanitizer_libc.h"
 #include "sanitizer_common/sanitizer_procmaps.h"
 
@@ -174,4 +175,4 @@ void *AsanDlSymNext(const char *sym) {
 
 } // namespace __asan
 
-#endif // SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
