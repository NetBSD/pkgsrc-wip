$NetBSD$

--- lib/esan/esan_interceptors.cpp.orig	2018-02-01 23:46:06.000000000 +0000
+++ lib/esan/esan_interceptors.cpp
@@ -232,6 +232,7 @@ DECLARE_REAL_AND_INTERCEPTOR(void *, mal
   } while (false)
 
 #include "sanitizer_common/sanitizer_common_syscalls.inc"
+#include "sanitizer_common/sanitizer_netbsd_syscalls.inc"
 
 //===----------------------------------------------------------------------===//
 // Custom interceptors
