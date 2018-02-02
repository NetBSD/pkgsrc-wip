$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2018-02-01 23:46:00.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -2426,7 +2426,7 @@ struct ScopedSyscall {
   }
 };
 
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC
 static void syscall_access_range(uptr pc, uptr p, uptr s, bool write) {
   TSAN_SYSCALL();
   MemoryAccessRange(thr, pc, p, s, write);
@@ -2519,6 +2519,7 @@ static void syscall_post_fork(uptr pc, i
   syscall_post_fork(GET_CALLER_PC(), res)
 
 #include "sanitizer_common/sanitizer_common_syscalls.inc"
+#include "sanitizer_common/sanitizer_netbsd_syscalls.inc"
 
 #ifdef NEED_TLS_GET_ADDR
 // Define own interceptor instead of sanitizer_common's for three reasons:
