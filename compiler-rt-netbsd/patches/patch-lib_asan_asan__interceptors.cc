$NetBSD$

--- lib/asan/asan_interceptors.cc.orig	2017-10-17 18:35:47.000000000 +0000
+++ lib/asan/asan_interceptors.cc
@@ -178,6 +178,7 @@ DECLARE_REAL_AND_INTERCEPTOR(void, free,
     (void)(s);                                \
   } while (false)
 #include "sanitizer_common/sanitizer_common_syscalls.inc"
+#include "sanitizer_common/sanitizer_netbsd_syscalls.inc"
 
 struct ThreadStartParam {
   atomic_uintptr_t t;
