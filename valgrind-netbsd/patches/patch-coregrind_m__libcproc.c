$NetBSD$

--- coregrind/m_libcproc.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_libcproc.c
@@ -67,7 +67,7 @@ HChar** VG_(client_envp) = NULL;
 const HChar *VG_(libdir) = VG_LIBDIR;
 
 const HChar *VG_(LD_PRELOAD_var_name) =
-#if defined(VGO_linux) || defined(VGO_solaris)
+#if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    "LD_PRELOAD";
 #elif defined(VGO_darwin)
    "DYLD_INSERT_LIBRARIES";
@@ -348,8 +348,12 @@ void VG_(client_cmd_and_args)(HChar *buf
 
 Int VG_(waitpid)(Int pid, Int *status, Int options)
 {
-#  if defined(VGO_linux)
+#  if defined(VGO_linux) || defined(VGO_netbsd)
+#    if defined(VGO_netbsd)
+   SysRes res = VG_(do_syscall4)(__NR___wait450,
+#    else
    SysRes res = VG_(do_syscall4)(__NR_wait4,
+#    endif
                                  pid, (UWord)status, options, 0);
    return sr_isError(res) ? -1 : sr_Res(res);
 #  elif defined(VGO_darwin)
@@ -586,7 +590,7 @@ Int VG_(system) ( const HChar* cmd )
 Int VG_(sysctl)(Int *name, UInt namelen, void *oldp, SizeT *oldlenp, void *newp, SizeT newlen)
 {
    SysRes res;
-#  if defined(VGO_darwin)
+#  if defined(VGO_darwin) || defined(VGO_netbsd)
    res = VG_(do_syscall6)(__NR___sysctl,
                            (UWord)name, namelen, (UWord)oldp, (UWord)oldlenp, (UWord)newp, newlen);
 #  else
@@ -689,6 +693,10 @@ Int VG_(gettid)(void)
    // Use Mach thread ports for lwpid instead.
    return mach_thread_self();
 
+#  elif defined(VGO_netbsd)
+   SysRes res = VG_(do_syscall0)(__NR__lwp_self);
+   return sr_Res(res);
+
 #  elif defined(VGO_solaris)
    SysRes res = VG_(do_syscall0)(__NR_lwp_self);
    return sr_Res(res);
@@ -710,7 +718,7 @@ Int VG_(getpgrp) ( void )
    /* ASSUMES SYSCALL ALWAYS SUCCEEDS */
 #  if defined(VGP_arm64_linux)
    return sr_Res( VG_(do_syscall1)(__NR_getpgid, 0) );
-#  elif defined(VGO_linux) || defined(VGO_darwin)
+#  elif defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    return sr_Res( VG_(do_syscall0)(__NR_getpgrp) );
 #  elif defined(VGO_solaris)
    /* Uses the shared pgrpsys syscall, 0 for the getpgrp variant. */
@@ -723,7 +731,7 @@ Int VG_(getpgrp) ( void )
 Int VG_(getppid) ( void )
 {
    /* ASSUMES SYSCALL ALWAYS SUCCEEDS */
-#  if defined(VGO_linux) || defined(VGO_darwin)
+#  if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    return sr_Res( VG_(do_syscall0)(__NR_getppid) );
 #  elif defined(VGO_solaris)
    /* Uses the shared getpid/getppid syscall, val2 contains a parent pid. */
@@ -736,7 +744,7 @@ Int VG_(getppid) ( void )
 Int VG_(geteuid) ( void )
 {
    /* ASSUMES SYSCALL ALWAYS SUCCEEDS */
-#  if defined(VGO_linux) || defined(VGO_darwin)
+#  if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    {
 #     if defined(__NR_geteuid32)
       // We use the 32-bit version if it's supported.  Otherwise, IDs greater
@@ -757,7 +765,7 @@ Int VG_(geteuid) ( void )
 
 Int VG_(getegid) ( void )
 {
-#  if defined(VGO_linux) || defined(VGO_darwin)
+#  if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    /* ASSUMES SYSCALL ALWAYS SUCCEEDS */
 #    if defined(__NR_getegid32)
    // We use the 32-bit version if it's supported.  Otherwise, IDs greater
@@ -804,7 +812,7 @@ Int VG_(getgroups)( Int size, UInt* list
         || defined(VGP_ppc64be_linux) || defined(VGP_ppc64le_linux)  \
         || defined(VGO_darwin) || defined(VGP_s390x_linux)    \
         || defined(VGP_mips32_linux) || defined(VGP_arm64_linux) \
-        || defined(VGO_solaris)
+        || defined(VGO_solaris) || defined(VGO_netbsd)
    SysRes sres;
    sres = VG_(do_syscall2)(__NR_getgroups, size, (Addr)list);
    if (sr_isError(sres))
@@ -823,7 +831,7 @@ Int VG_(getgroups)( Int size, UInt* list
 Int VG_(ptrace) ( Int request, Int pid, void *addr, void *data )
 {
    SysRes res;
-#  if defined(VGO_linux) || defined(VGO_darwin)
+#  if defined(VGO_linux) || defined(VGO_darwin) || defined(VGO_netbsd)
    res = VG_(do_syscall4)(__NR_ptrace, request, pid, (UWord)addr, (UWord)data);
 #  elif defined(VGO_solaris)
    /* There is no ptrace syscall on Solaris.  Such requests has to be
@@ -860,7 +868,7 @@ Int VG_(fork) ( void )
       return -1;
    return sr_Res(res);
 
-#  elif defined(VGO_darwin)
+#  elif defined(VGO_darwin) || defined(VGO_netbsd)
    SysRes res;
    res = VG_(do_syscall0)(__NR_fork); /* __NR_fork is UX64 */
    if (sr_isError(res))
@@ -921,6 +929,14 @@ UInt VG_(read_millisecond_timer) ( void 
      }
    }
 
+#  elif defined(VGO_netbsd)
+   { SysRes res;
+     struct vki_timeval tv_now;
+     res = VG_(do_syscall2)(__NR___gettimeofday50, (UWord)&tv_now, (UWord)NULL);
+     vg_assert(! sr_isError(res));
+     now = tv_now.tv_sec * 1000000ULL + tv_now.tv_usec;
+   }
+
 #  elif defined(VGO_darwin)
    // Weird: it seems that gettimeofday() doesn't fill in the timeval, but
    // rather returns the tv_sec as the low 32 bits of the result and the
@@ -947,7 +963,11 @@ UInt VG_(read_millisecond_timer) ( void 
 Int VG_(gettimeofday)(struct vki_timeval *tv, struct vki_timezone *tz)
 {
    SysRes res;
+#  if defined(VGO_netbsd)
+   res = VG_(do_syscall2)(__NR___gettimeofday50, (UWord)tv, (UWord)tz);
+#  else
    res = VG_(do_syscall2)(__NR_gettimeofday, (UWord)tv, (UWord)tz);
+#endif
 
    if (! sr_isError(res)) return 0;
 
@@ -982,7 +1002,7 @@ UInt VG_(get_user_milliseconds)(void)
       }
    }
 
-#  elif defined(VGO_darwin)
+#  elif defined(VGO_darwin) || defined(VGO_netbsd)
    res = 0;
 
 #  else
