$NetBSD$

--- lib/hwasan/hwasan_interceptors.cc.orig	2017-12-21 18:53:10.000000000 +0000
+++ lib/hwasan/hwasan_interceptors.cc
@@ -448,6 +448,7 @@ int OnExit() {
     (void)(s);                                \
   } while (false)
 #include "sanitizer_common/sanitizer_common_syscalls.inc"
+#include "sanitizer_common/sanitizer_netbsd_syscalls.inc"
 
 
 
