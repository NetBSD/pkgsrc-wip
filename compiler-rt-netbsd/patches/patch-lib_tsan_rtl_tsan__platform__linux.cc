$NetBSD$

--- lib/tsan/rtl/tsan_platform_linux.cc.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/tsan/rtl/tsan_platform_linux.cc
@@ -14,7 +14,7 @@
 
 
 #include "sanitizer_common/sanitizer_platform.h"
-#if SANITIZER_LINUX || SANITIZER_FREEBSD
+#if SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
 
 #include "sanitizer_common/sanitizer_common.h"
 #include "sanitizer_common/sanitizer_libc.h"
@@ -62,7 +62,7 @@
 # undef sa_sigaction
 #endif
 
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
 extern "C" void *__libc_stack_end;
 void *__libc_stack_end = 0;
 #endif
@@ -401,4 +401,4 @@ void cur_thread_finalize() {
 
 }  // namespace __tsan
 
-#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD
+#endif  // SANITIZER_LINUX || SANITIZER_FREEBSD || SANITIZER_NETBSD
