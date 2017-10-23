$NetBSD$

--- lib/sanitizer_common/sanitizer_syscall_generic.inc.orig	2017-08-05 14:29:08.000000000 +0000
+++ lib/sanitizer_common/sanitizer_syscall_generic.inc
@@ -43,8 +43,12 @@
 # endif
 #elif defined(__x86_64__) && (SANITIZER_FREEBSD || SANITIZER_MAC)
 # define internal_syscall __syscall
+# define internal_syscall64 __syscall
+# define internal_syscall_ptr __syscall
 # else
 # define internal_syscall syscall
+# define internal_syscall64 syscall
+# define internal_syscall_ptr syscall
 #endif
 
 bool internal_iserror(uptr retval, int *rverrno) {
