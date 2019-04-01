$NetBSD$

--- coregrind/m_libcsignal.c.orig	2018-05-05 07:42:22.000000000 +0000
+++ coregrind/m_libcsignal.c
@@ -216,7 +216,10 @@ void VG_(sigcomplementset)( vki_sigset_t
 */
 Int VG_(sigprocmask)( Int how, const vki_sigset_t* set, vki_sigset_t* oldset)
 {
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_netbsd)
+   SysRes res = VG_(do_syscall3)(__NR___sigprocmask14, 
+                                 how, (UWord)set, (UWord)oldset);
+#  elif defined(VGO_linux) || defined(VGO_solaris)
 #  if defined(__NR_rt_sigprocmask)
    SysRes res = VG_(do_syscall4)(__NR_rt_sigprocmask, 
                                  how, (UWord)set, (UWord)oldset, 
@@ -320,6 +323,11 @@ Int VG_(sigaction) ( Int signum, 
                                  signum, (UWord)act, (UWord)oldact);
    return sr_isError(res) ? -1 : 0;
 
+#  elif defined(VGO_netbsd)
+   SysRes res = VG_(do_syscall3)(__NR___sigaction_sigtramp,
+                                 signum, (UWord)act, (UWord)oldact);
+   return sr_isError(res) ? -1 : 0;
+
 #  else
 #    error "Unsupported OS"
 #  endif
@@ -331,7 +339,7 @@ void 
 VG_(convert_sigaction_fromK_to_toK)( const vki_sigaction_fromK_t* fromK,
                                      /*OUT*/vki_sigaction_toK_t* toK )
 {
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    *toK = *fromK;
 #  elif defined(VGO_darwin)
    toK->ksa_handler = fromK->ksa_handler;
@@ -346,7 +354,7 @@ VG_(convert_sigaction_fromK_to_toK)( con
 
 Int VG_(kill)( Int pid, Int signo )
 {
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    SysRes res = VG_(do_syscall2)(__NR_kill, pid, signo);
 #  elif defined(VGO_darwin)
    SysRes res = VG_(do_syscall3)(__NR_kill,
@@ -372,6 +380,11 @@ Int VG_(tkill)( Int lwpid, Int signo )
    res = VG_(do_syscall2)(__NR___pthread_kill, lwpid, signo);
    return sr_isError(res) ? -1 : 0;
 
+#  elif defined(VGO_netbsd)
+   SysRes res;
+   res = VG_(do_syscall2)(__NR__lwp_kill, lwpid, signo);
+   return sr_isError(res) ? -1 : 0;
+
 #  elif defined(VGO_solaris)
    SysRes res;
 #     if defined(SOLARIS_LWP_SIGQUEUE_SYSCALL)
@@ -422,6 +435,18 @@ Int VG_(sigtimedwait_zero)( const vki_si
    return sr_isError(res) ? -1 : sr_Res(res);
 }
 
+/* ---------- sigtimedwait_zero: Linux ----------- */
+
+#elif defined(VGO_netbsd)
+Int VG_(sigtimedwait_zero)( const vki_sigset_t *set, 
+                            vki_siginfo_t *info )
+{
+   static const struct vki_timespec zero = { 0, 0 };
+   SysRes res = VG_(do_syscall3)(__NR_____sigtimedwait50, (UWord)set, (UWord)info, 
+                                 (UWord)&zero);
+   return sr_isError(res) ? -1 : sr_Res(res);
+}
+
 /* ---------- sigtimedwait_zero: Darwin ----------- */
 
 #elif defined(VGO_darwin)
