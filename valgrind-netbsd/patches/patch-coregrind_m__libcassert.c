$NetBSD$

--- coregrind/m_libcassert.c.orig	2018-08-06 07:22:24.000000000 +0000
+++ coregrind/m_libcassert.c
@@ -68,7 +68,7 @@
         (srP)->misc.X86.r_ebp = ebp;                      \
       }
 #elif defined(VGP_amd64_linux) || defined(VGP_amd64_darwin) \
-      || defined(VGP_amd64_solaris)
+      || defined(VGP_amd64_solaris) || defined(VGP_amd64_netbsd)
 #  define GET_STARTREGS(srP)                              \
       { ULong rip, rsp, rbp;                              \
         __asm__ __volatile__(                             \
@@ -272,7 +272,7 @@ void VG_(exit_now)( Int status )
 {
 #if defined(VGO_linux)
    (void)VG_(do_syscall1)(__NR_exit_group, status );
-#elif defined(VGO_darwin) || defined(VGO_solaris)
+#elif defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
    (void)VG_(do_syscall1)(__NR_exit, status );
 #else
 #  error Unknown OS
