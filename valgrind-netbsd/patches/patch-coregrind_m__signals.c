$NetBSD$

--- coregrind/m_signals.c.orig	2018-09-30 04:41:00.000000000 +0000
+++ coregrind/m_signals.c
@@ -512,6 +512,22 @@ typedef struct SigQueue {
       srP->misc.AMD64.r_rbp = (ULong)(ss->__rbp);
    }
 
+#elif defined(VGP_amd64_netbsd)
+#  define VG_UCONTEXT_INSTR_PTR(uc)       VKI__UC_MACHINE_PC(uc)
+#  define VG_UCONTEXT_STACK_PTR(uc)       VKI__UC_MACHINE_SP(uc)
+#  define VG_UCONTEXT_FRAME_PTR(uc)       VKI__UC_MACHINE_FP(uc)
+#  define VG_UCONTEXT_SYSCALL_NUM(uc)     ((uc)->uc_mcontext.__gregs[VKI__REG_RAX])
+#  define VG_UCONTEXT_SYSCALL_SYSRES(uc)                        \
+      /* Convert the value in uc_mcontext.rax into a SysRes. */ \
+      VG_(mk_SysRes_amd64_netbsd)( ((uc)->uc_mcontext.__gregs[VKI__REG_RAX]), \
+         ((uc)->uc_mcontext.__gregs[VKI__REG_RDX]), ((uc)->uc_mcontext.__gregs[VKI__REG_RFLAGS]) != 0 ? True : False )
+#  define VG_UCONTEXT_LINK_REG(uc)        0 /* No LR on amd64 either */                                                                                      
+#  define VG_UCONTEXT_TO_UnwindStartRegs(srP, uc)        \
+      { (srP)->r_pc = VKI__UC_MACHINE_PC(uc);             \
+        (srP)->r_sp = VKI__UC_MACHINE_SP(uc);             \
+        (srP)->misc.AMD64.r_rbp = VKI__UC_MACHINE_FP(uc); \
+      }
+
 #elif defined(VGP_s390x_linux)
 
 #  define VG_UCONTEXT_INSTR_PTR(uc)       ((uc)->uc_mcontext.regs.psw.addr)
@@ -605,7 +621,7 @@ typedef struct SigQueue {
 #if defined(VGO_linux)
 #  define VKI_SIGINFO_si_addr  _sifields._sigfault._addr
 #  define VKI_SIGINFO_si_pid   _sifields._kill._pid
-#elif defined(VGO_darwin) || defined(VGO_solaris)
+#elif defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
 #  define VKI_SIGINFO_si_addr  si_addr
 #  define VKI_SIGINFO_si_pid   si_pid
 #else
@@ -979,7 +995,7 @@ extern void my_sigreturn(void);
    "   syscall\n" \
    ".previous\n"
 
-#elif defined(VGP_x86_solaris) || defined(VGP_amd64_solaris)
+#elif defined(VGP_x86_solaris) || defined(VGP_amd64_solaris) || defined(VGO_netbsd)
 /* Not used on Solaris. */
 #  define _MY_SIGRETURN(name) \
    ".text\n" \
@@ -1031,7 +1047,7 @@ static void handle_SCSS_change ( Bool fo
       ksa.sa_flags    = skss.skss_per_sig[sig].skss_flags;
 #     if !defined(VGP_ppc32_linux) && \
          !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-         !defined(VGP_mips32_linux) && !defined(VGO_solaris)
+         !defined(VGP_mips32_linux) && !defined(VGO_solaris) && !defined(VGO_netbsd)
       ksa.sa_restorer = my_sigreturn;
 #     endif
       /* Re above ifdef (also the assertion below), PaulM says:
@@ -1078,7 +1094,7 @@ static void handle_SCSS_change ( Bool fo
 #        if !defined(VGP_ppc32_linux) && \
             !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
             !defined(VGP_mips32_linux) && !defined(VGP_mips64_linux) && \
-            !defined(VGO_solaris)
+            !defined(VGO_solaris) && !defined(VGO_netbsd)
          vg_assert(ksa_old.sa_restorer == my_sigreturn);
 #        endif
          VG_(sigaddset)( &ksa_old.sa_mask, VKI_SIGKILL );
@@ -1199,7 +1215,7 @@ SysRes VG_(do_sys_sigaction) ( Int signo
       old_act->sa_flags    = scss.scss_per_sig[signo].scss_flags;
       old_act->sa_mask     = scss.scss_per_sig[signo].scss_mask;
 #     if !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-         !defined(VGO_solaris)
+         !defined(VGO_solaris) && !defined(VGO_netbsd)
       old_act->sa_restorer = scss.scss_per_sig[signo].scss_restorer;
 #     endif
    }
@@ -1212,7 +1228,7 @@ SysRes VG_(do_sys_sigaction) ( Int signo
 
       scss.scss_per_sig[signo].scss_restorer = NULL;
 #     if !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-         !defined(VGO_solaris)
+         !defined(VGO_solaris) && !defined(VGO_netbsd)
       scss.scss_per_sig[signo].scss_restorer = new_act->sa_restorer;
 #     endif
 
@@ -1558,7 +1574,7 @@ void VG_(kill_self)(Int sigNo)
    sa.ksa_handler = VKI_SIG_DFL;
    sa.sa_flags = 0;
 #  if !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-      !defined(VGO_solaris)
+      !defined(VGO_solaris) && !defined(VGO_netbsd)
    sa.sa_restorer = 0;
 #  endif
    VG_(sigemptyset)(&sa.sa_mask);
@@ -1586,14 +1602,14 @@ void VG_(kill_self)(Int sigNo)
 // request (SI_ASYNCIO).  There's lots of implementation-defined leeway in
 // POSIX, but the user vs. kernal distinction is what we want here.  We also
 // pass in some other details that can help when si_code is unreliable.
-static Bool is_signal_from_kernel(ThreadId tid, int signum, int si_code)
+static Bool is_signal_from_kernel(ThreadId tid, int signum, int my_si_code)
 {
-#  if defined(VGO_linux) || defined(VGO_solaris)
+#  if defined(VGO_linux) || defined(VGO_solaris) || defined(VGO_netbsd)
    // On Linux, SI_USER is zero, negative values are from the user, positive
    // values are from the kernel.  There are SI_FROMUSER and SI_FROMKERNEL
    // macros but we don't use them here because other platforms don't have
    // them.
-   return ( si_code > VKI_SI_USER ? True : False );
+   return ( my_si_code > VKI_SI_USER ? True : False );
 
 #  elif defined(VGO_darwin)
    // On Darwin 9.6.0, the si_code is completely unreliable.  It should be the
@@ -1615,7 +1631,7 @@ static Bool is_signal_from_kernel(Thread
 
    // If it's a SIGSEGV, use the proper condition, since it's fairly reliable.
    } else if (SIGSEGV == signum) {
-      return ( si_code > 0 ? True : False );
+      return ( my_si_code > 0 ? True : False );
 
    // If it's anything else, assume it's kernel-generated.  Reason being that
    // kernel-generated sync signals are more common, and it's probable that
@@ -2025,7 +2041,7 @@ static void resume_scheduler(ThreadId ti
    }
 }
 
-static void synth_fault_common(ThreadId tid, Addr addr, Int si_code)
+static void synth_fault_common(ThreadId tid, Addr addr, Int my_si_code)
 {
    vki_siginfo_t info;
 
@@ -2033,7 +2049,7 @@ static void synth_fault_common(ThreadId 
 
    VG_(memset)(&info, 0, sizeof(info));
    info.si_signo = VKI_SIGSEGV;
-   info.si_code = si_code;
+   info.si_code = my_si_code;
    info.VKI_SIGINFO_si_addr = (void*)addr;
 
    /* Even if gdbserver indicates to ignore the signal, we must deliver it.
@@ -2266,7 +2282,7 @@ static vki_siginfo_t *next_queued(Thread
    return ret;
 }
 
-static int sanitize_si_code(int si_code)
+static int sanitize_si_code(int my_si_code)
 {
 #if defined(VGO_linux)
    /* The linux kernel uses the top 16 bits of si_code for it's own
@@ -2277,9 +2293,9 @@ static int sanitize_si_code(int si_code)
       The kernel treats the bottom 16 bits as signed and (when it does
       mask them off) sign extends them when exporting to user space so
       we do the same thing here. */
-   return (Short)si_code;
-#elif defined(VGO_darwin) || defined(VGO_solaris)
-   return si_code;
+   return (Short)my_si_code;
+#elif defined(VGO_darwin) || defined(VGO_solaris) || defined(VGO_netbsd)
+   return my_si_code;
 #else
 #  error Unknown OS
 #endif
@@ -2463,7 +2479,7 @@ void async_signalhandler ( Int sigNo,
    /* (1) */
    VG_(fixup_guest_state_after_syscall_interrupted)(
       tid, 
-      VG_UCONTEXT_INSTR_PTR(uc), 
+      VG_UCONTEXT_INSTR_PTR(uc),
       sres,  
       !!(scss.scss_per_sig[sigNo].scss_flags & VKI_SA_RESTART),
       uc
@@ -2904,7 +2920,7 @@ void pp_ksigaction ( vki_sigaction_toK_t
                sa->ksa_handler, 
                (UInt)sa->sa_flags, 
 #              if !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-                  !defined(VGO_solaris)
+                  !defined(VGO_solaris) && !defined(VGO_netbsd)
                   sa->sa_restorer
 #              else
                   (void*)0
@@ -2927,7 +2943,7 @@ void VG_(set_default_handler)(Int signo)
    sa.ksa_handler = VKI_SIG_DFL;
    sa.sa_flags = 0;
 #  if !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-      !defined(VGO_solaris)
+      !defined(VGO_solaris) && !defined(VGO_netbsd)
    sa.sa_restorer = 0;
 #  endif
    VG_(sigemptyset)(&sa.sa_mask);
@@ -3047,7 +3063,7 @@ void VG_(sigstartup_actions) ( void )
 	 tsa.ksa_handler = (void *)sync_signalhandler;
 	 tsa.sa_flags = VKI_SA_SIGINFO;
 #        if !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-            !defined(VGO_solaris)
+            !defined(VGO_solaris) && !defined(VGO_netbsd)
 	 tsa.sa_restorer = 0;
 #        endif
 	 VG_(sigfillset)(&tsa.sa_mask);
@@ -3075,7 +3091,7 @@ void VG_(sigstartup_actions) ( void )
 
       scss.scss_per_sig[i].scss_restorer = NULL;
 #     if !defined(VGP_x86_darwin) && !defined(VGP_amd64_darwin) && \
-         !defined(VGO_solaris)
+         !defined(VGO_solaris) && !defined(VGO_netbsd)
       scss.scss_per_sig[i].scss_restorer = sa.sa_restorer;
 #     endif
 
