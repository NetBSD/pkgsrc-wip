$NetBSD$

--- lib/asan/asan_malloc_linux.cc.orig	2017-08-05 14:29:08.000000000 +0000
+++ lib/asan/asan_malloc_linux.cc
@@ -15,7 +15,7 @@
 //===----------------------------------------------------------------------===//
 
 #include "sanitizer_common/sanitizer_platform.h"
-#if SANITIZER_FREEBSD || SANITIZER_FUCHSIA || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_FUCHSIA || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "sanitizer_common/sanitizer_tls_get_addr.h"
 #include "asan_allocator.h"
@@ -234,4 +234,4 @@ void ReplaceSystemMalloc() {
 }  // namespace __asan
 #endif  // SANITIZER_ANDROID
 
-#endif  // SANITIZER_FREEBSD || SANITIZER_FUCHSIA || SANITIZER_LINUX
+#endif  // SANITIZER_FREEBSD || SANITIZER_FUCHSIA || SANITIZER_LINUX || SANITIZER_NETBSD
