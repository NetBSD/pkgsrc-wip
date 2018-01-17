$NetBSD$

--- lib/hwasan/hwasan_interceptors.cc.orig	2018-01-15 06:00:16.000000000 +0000
+++ lib/hwasan/hwasan_interceptors.cc
@@ -457,6 +457,7 @@ int OnExit() {
     (void)(s);                                \
   } while (false)
 #include "sanitizer_common/sanitizer_common_syscalls.inc"
+#include "sanitizer_common/sanitizer_netbsd_syscalls.inc"
 
 
 
