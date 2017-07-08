$NetBSD$

--- lib/sanitizer_common/sanitizer_syscall_generic.inc.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/sanitizer_common/sanitizer_syscall_generic.inc
@@ -11,13 +11,38 @@
 //
 //===----------------------------------------------------------------------===//
 
-#if SANITIZER_FREEBSD || SANITIZER_MAC
+#ifdef SANITIZER_NETBSD
+# define SYS_stat SYS___stat50
+# define SYS_lstat SYS___lstat50
+# define SYS_fstat SYS___fstat50
+# define SYS_gettimeofday SYS___gettimeofday50
+# define SYS_wait4 SYS___wait450
+# define SYS_getdents SYS___getdents30
+# define SYS_sigaltstack SYS___sigaltstack14
+# define SYS_sigprocmask SYS___sigprocmask14
+# define SYS_nanosleep SYS___nanosleep50
+#endif
+
+#if SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_NETBSD
 # define SYSCALL(name) SYS_ ## name
 #else
 # define SYSCALL(name) __NR_ ## name
 #endif
 
-#if (SANITIZER_FREEBSD || SANITIZER_MAC) && defined(__x86_64__)
+#if SANITIZER_NETBSD
+// We use 3 kinds of internal_syscall's for different types of retval in order
+// to address problems related to the byte order.
+//   - internal_syscall     for 32-bit length (int, pid_t)
+//   - internal_syscall64   for 64-bit length (off_t)
+//   - internal_syscall_ptr for pointer and (s)size_t
+# define  internal_syscall      syscall
+# define  internal_syscall64    __syscall
+# if SANITIZER_WORDSIZE == 64
+#  define internal_syscall_ptr  __syscall
+# else
+#  define internal_syscall_ptr  syscall
+# endif
+#elif defined(__x86_64__) && (SANITIZER_FREEBSD || SANITIZER_MAC)
 # define internal_syscall __syscall
 # else
 # define internal_syscall syscall
