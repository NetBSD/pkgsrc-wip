$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-12-08 18:27:50.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -597,7 +597,7 @@ extern "C" int TSAN_INTERCEPTOR_SIGSETJM
   return 0;
 }
 
-#if !SANITIEZER_NETBSD
+#if !SANITIZER_NETBSD
 extern "C" SANITIZER_INTERFACE_ATTRIBUTE
 int __interceptor___sigsetjmp(void *env);
 extern "C" int __interceptor___sigsetjmp(void *env) {
@@ -609,13 +609,13 @@ extern "C" int __interceptor___sigsetjmp
 extern "C" int setjmp_symname(void *env);
 extern "C" int _setjmp(void *env);
 extern "C" int sigsetjmp_symname(void *env);
-#if !SANITIEZER_NETBSD
+#if !SANITIZER_NETBSD
 extern "C" int __sigsetjmp(void *env);
 #endif
 DEFINE_REAL(int, setjmp_symname, void *env)
 DEFINE_REAL(int, _setjmp, void *env)
 DEFINE_REAL(int, sigsetjmp_symname, void *env)
-#if !SANITIEZER_NETBSD
+#if !SANITIZER_NETBSD
 DEFINE_REAL(int, __sigsetjmp, void *env)
 #endif
 #endif  // SANITIZER_MAC
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
