$NetBSD$

--- coregrind/m_syswrap/syswrap-main.c.orig	2018-08-14 06:09:34.000000000 +0000
+++ coregrind/m_syswrap/syswrap-main.c
@@ -81,6 +81,9 @@
    fills in the immediate field.
    s390x r1/SVC r2   r3   r4   r5   r6   r7   n/a  n/a  r2        (== ARG1)
 
+   FreeBSD:
+   amd64  rax rdi  rsi  rdx  rcx  r8   r9   +8   +16  rdx:rax, rflags.c
+
           NUM   ARG1 ARG2 ARG3 ARG4 ARG5 ARG6 ARG7 ARG8 RESULT
    DARWIN:
    x86    eax   +4   +8   +12  +16  +20  +24  +28  +32  edx:eax, eflags.c
@@ -292,6 +295,14 @@ UWord ML_(do_syscall_for_client_WRK)( Wo
                                       const vki_sigset_t *syscall_mask,
                                       const vki_sigset_t *restore_mask,
                                       Word sigsetSzB );
+#elif defined(VGO_netbsd)
+extern
+UWord ML_(do_syscall_for_client_WRK)( Word syscallno,
+                                      void* guest_state,
+                                      const vki_sigset_t *syscall_mask,
+                                      const vki_sigset_t *restore_mask,
+                                      Word sigsetSzB );
+
 #elif defined(VGO_darwin)
 extern
 UWord ML_(do_syscall_for_client_unix_WRK)( Word syscallno, 
@@ -335,11 +346,25 @@ void do_syscall_for_client ( Int syscall
 {
    vki_sigset_t saved;
    UWord err;
+#  if defined(VGO_netbsd)
+   Int real_syscallno;
+#  endif
 #  if defined(VGO_linux)
    err = ML_(do_syscall_for_client_WRK)(
             syscallno, &tst->arch.vex, 
             syscall_mask, &saved, sizeof(vki_sigset_t)
          );
+#  elif defined(VGO_netbsd)
+   if (tst->arch.vex.guest_SC_CLASS == VG_NETBSD_SYSCALL0)
+      real_syscallno = __NR_syscall;
+   else if (tst->arch.vex.guest_SC_CLASS == VG_NETBSD_SYSCALL198)
+      real_syscallno = __NR___syscall;
+   else
+      real_syscallno = syscallno;
+   err = ML_(do_syscall_for_client_WRK)(
+            real_syscallno, &tst->arch.vex,                                                                                                                  
+            syscall_mask, &saved, sizeof(vki_sigset_t)                                                                                                       
+         );
 #  elif defined(VGO_darwin)
    switch (VG_DARWIN_SYSNO_CLASS(syscallno)) {
       case VG_DARWIN_SYSCALL_CLASS_UNIX:
@@ -532,6 +557,47 @@ void getSyscallArgsFromGuestState ( /*OU
    canonical->arg6  = gst->guest_X5;
    canonical->arg7  = 0;
    canonical->arg8  = 0;
+#elif defined(VGP_amd64_netbsd)
+   VexGuestAMD64State* gst = (VexGuestAMD64State*)gst_vanilla;
+   UWord *stack = (UWord *)gst->guest_RSP;
+      
+   // NetBSD supports different calling conventions
+   switch (gst->guest_RAX) {
+   case __NR_syscall:
+      canonical->klass = VG_NETBSD_SYSCALL0;
+      canonical->sysno = gst->guest_RDI;
+      break;
+   case __NR___syscall:
+      canonical->klass = VG_NETBSD_SYSCALL198;
+      canonical->sysno = gst->guest_RDI;
+      break;
+   default:
+      canonical->klass = 0;
+      canonical->sysno = gst->guest_RAX;
+      break;
+   }
+   // stack[0] is a (fake) return address
+   if (canonical->klass != VG_NETBSD_SYSCALL0 && canonical->klass != VG_NETBSD_SYSCALL198) {
+      // stack[0] is return address
+      canonical->arg1  = gst->guest_RDI;
+      canonical->arg2  = gst->guest_RSI;
+      canonical->arg3  = gst->guest_RDX;
+      canonical->arg4  = gst->guest_R10;
+      canonical->arg5  = gst->guest_R8;
+      canonical->arg6  = gst->guest_R9;                                                                                                                      
+      canonical->arg7  = stack[1];
+      canonical->arg8  = stack[2];
+   } else {
+      // stack[0] is return address
+      canonical->arg1  = gst->guest_RSI;
+      canonical->arg2  = gst->guest_RDX;
+      canonical->arg3  = gst->guest_R10;
+      canonical->arg4  = gst->guest_R8;
+      canonical->arg5  = gst->guest_R9;                                                                                                                      
+      canonical->arg6  = stack[1];
+      canonical->arg7  = stack[2];
+      canonical->arg8  = stack[3];
+   }
 
 #elif defined(VGP_mips32_linux)
    VexGuestMIPS32State* gst = (VexGuestMIPS32State*)gst_vanilla;
@@ -950,6 +1016,49 @@ void putSyscallArgsIntoGuestState ( /*IN
    stack[1] = canonical->arg7;
    stack[2] = canonical->arg8;
 
+#elif defined(VGP_amd64_netbsd)
+   VexGuestAMD64State* gst = (VexGuestAMD64State*)gst_vanilla;
+   UWord *stack = (UWord *)gst->guest_RSP;
+      
+   // stack[0] is a (fake) return address
+   switch (canonical->klass) {
+   case VG_NETBSD_SYSCALL0:
+      gst->guest_RAX = __NR_syscall;   
+      gst->guest_RDI = canonical->sysno;
+      gst->guest_RSI = canonical->arg1;
+      gst->guest_RDX = canonical->arg2;
+      gst->guest_R10 = canonical->arg3;   
+      gst->guest_R8  = canonical->arg4;
+      gst->guest_R9  = canonical->arg5;  
+      stack[1]       = canonical->arg6;
+      stack[2]       = canonical->arg7;
+      stack[3]       = canonical->arg8;
+      break;
+   case VG_NETBSD_SYSCALL198:
+      gst->guest_RAX = __NR___syscall;
+      gst->guest_RDI = canonical->sysno;
+      gst->guest_RSI = canonical->arg1;
+      gst->guest_RDX = canonical->arg2;
+      gst->guest_R10 = canonical->arg3;                                                                                                                      
+      gst->guest_R8  = canonical->arg4;
+      gst->guest_R9  = canonical->arg5;
+      stack[1]       = canonical->arg6;
+      stack[2]       = canonical->arg7;
+      stack[3]       = canonical->arg8;
+      break;
+   default:
+      gst->guest_RAX = canonical->sysno;
+      gst->guest_RDI = canonical->arg1; 
+      gst->guest_RSI = canonical->arg2;
+      gst->guest_RDX = canonical->arg3;
+      gst->guest_R10 = canonical->arg4;                                                                                                                      
+      gst->guest_R8  = canonical->arg5;
+      gst->guest_R9  = canonical->arg6;
+      stack[1]       = canonical->arg7;                                                                                                                      
+      stack[2]       = canonical->arg8;
+      break;
+   }
+
 #else
 #  error "putSyscallArgsIntoGuestState: unknown arch"
 #endif
@@ -983,6 +1092,7 @@ void getSyscallStatusFromGuestState ( /*
    canonical->sres = VG_(mk_SysRes_ppc64_linux)( gst->guest_GPR3, cr0so );
    canonical->what = SsComplete;
 
+
 #  elif defined(VGP_arm_linux)
    VexGuestARMState* gst = (VexGuestARMState*)gst_vanilla;
    canonical->sres = VG_(mk_SysRes_arm_linux)( gst->guest_R0 );
@@ -1041,6 +1151,14 @@ void getSyscallStatusFromGuestState ( /*
                      );
    canonical->what = SsComplete;
 
+#  elif defined(VGP_amd64_netbsd)
+   /* duplicates logic in m_signals.VG_UCONTEXT_SYSCALL_SYSRES */
+   VexGuestAMD64State* gst = (VexGuestAMD64State*)gst_vanilla; 
+   ULong flags = LibVEX_GuestAMD64_get_rflags(gst);
+   canonical->sres = VG_(mk_SysRes_amd64_netbsd)(gst->guest_RAX, gst->guest_RDX,
+                        (flags & 1) != 0 ? True : False);
+   canonical->what = SsComplete;
+
 #  elif defined(VGP_amd64_darwin)
    /* duplicates logic in m_signals.VG_UCONTEXT_SYSCALL_SYSRES */
    VexGuestAMD64State* gst = (VexGuestAMD64State*)gst_vanilla;
@@ -1134,6 +1252,26 @@ void putSyscallStatusIntoGuestState ( /*
    VG_TRACK( post_reg_write, Vg_CoreSysCall, tid, 
              OFFSET_amd64_RAX, sizeof(UWord) );
 
+#elif defined(VGP_amd64_freebsd)
+   VexGuestAMD64State* gst = (VexGuestAMD64State*)gst_vanilla;
+   vg_assert(canonical->what == SsComplete);
+   if (sr_isError(canonical->sres)) {
+      gst->guest_RAX = sr_Err(canonical->sres);
+      LibVEX_GuestAMD64_put_rflag_c(1, gst);
+   } else {                                                                                                                                                  
+      gst->guest_RAX = sr_Res(canonical->sres);                                                                                                              
+      gst->guest_RDX = sr_ResHI(canonical->sres);                                                                                                            
+      LibVEX_GuestAMD64_put_rflag_c(0, gst);                                                                                                                 
+   }
+   VG_TRACK( post_reg_write, Vg_CoreSysCall, tid,
+      OFFSET_amd64_RAX, sizeof(ULong) );
+   VG_TRACK( post_reg_write, Vg_CoreSysCall, tid,
+      OFFSET_amd64_RDX, sizeof(ULong) );
+   // GrP fixme sets defined for entire eflags, not just bit c
+   // DDD: this breaks exp-ptrcheck.
+   VG_TRACK( post_reg_write, Vg_CoreSysCall, tid,
+      offsetof(VexGuestAMD64State, guest_CC_DEP1), sizeof(ULong) );
+
 #  elif defined(VGP_ppc32_linux)
    VexGuestPPC32State* gst = (VexGuestPPC32State*)gst_vanilla;
    UInt old_cr = LibVEX_GuestPPC32_get_CR(gst);
@@ -1363,6 +1501,26 @@ void putSyscallStatusIntoGuestState ( /*
    VG_TRACK(post_reg_write, Vg_CoreSysCall, tid, offsetof(VexGuestAMD64State,
             guest_CC_DEP2), sizeof(ULong));
 
+#elif defined(VGP_amd64_netbsd)
+   VexGuestAMD64State* gst = (VexGuestAMD64State*)gst_vanilla;
+   vg_assert(canonical->what == SsComplete);
+   if (sr_isError(canonical->sres)) {
+      gst->guest_RAX = sr_Err(canonical->sres);
+      LibVEX_GuestAMD64_put_rflag_c(1, gst);
+   } else {
+      gst->guest_RAX = sr_Res(canonical->sres);
+      gst->guest_RDX = sr_ResHI(canonical->sres);
+      LibVEX_GuestAMD64_put_rflag_c(0, gst);
+   }
+   VG_TRACK( post_reg_write, Vg_CoreSysCall, tid,
+      OFFSET_amd64_RAX, sizeof(ULong) );
+   VG_TRACK( post_reg_write, Vg_CoreSysCall, tid,
+      OFFSET_amd64_RDX, sizeof(ULong) );
+   // GrP fixme sets defined for entire eflags, not just bit c
+   // DDD: this breaks exp-ptrcheck.
+   VG_TRACK( post_reg_write, Vg_CoreSysCall, tid,
+      offsetof(VexGuestAMD64State, guest_CC_DEP1), sizeof(ULong) );
+
 #  else
 #    error "putSyscallStatusIntoGuestState: unknown arch"
 #  endif
@@ -1478,6 +1636,17 @@ void getSyscallArgLayout ( /*OUT*/Syscal
    layout->s_arg7   = sizeof(UWord) * 7;
    layout->s_arg8   = sizeof(UWord) * 8;
    
+#elif defined(VGP_amd64_netbsd)
+   layout->o_sysno  = OFFSET_amd64_RAX;
+   layout->o_arg1   = OFFSET_amd64_RDI;
+   layout->o_arg2   = OFFSET_amd64_RSI; 
+   layout->o_arg3   = OFFSET_amd64_RDX; 
+   layout->o_arg4   = OFFSET_amd64_R10; 
+   layout->o_arg5   = OFFSET_amd64_R8;  
+   layout->o_arg6   = OFFSET_amd64_R9;  
+   layout->s_arg7   = sizeof(UWord) * 1;
+   layout->s_arg8   = sizeof(UWord) * 2;
+
 #elif defined(VGP_amd64_darwin)
    layout->o_sysno  = OFFSET_amd64_RAX;
    layout->o_arg1   = OFFSET_amd64_RDI;
@@ -1543,6 +1712,7 @@ void bad_before ( ThreadId              
                   /*OUT*/SyscallStatus* status,
                   /*OUT*/UWord*         flags )
 {
+   __builtin_trap();
    VG_(dmsg)("WARNING: unhandled %s syscall: %s\n",
       VG_PLATFORM, VG_SYSNUM_STRING(args->sysno));
    if (VG_(clo_verbosity) > 1) {
@@ -1570,6 +1740,11 @@ static const SyscallTableEntry* get_sysc
 #  if defined(VGO_linux)
    sys = ML_(get_linux_syscall_entry)( syscallno );
 
+#  elif defined(VGO_netbsd)
+   if (syscallno >= 0 && syscallno < ML_(syscall_table_size) &&
+       ML_(syscall_table)[syscallno].before != NULL)
+      sys = &ML_(syscall_table)[syscallno];
+
 #  elif defined(VGO_darwin)
    Int idx = VG_DARWIN_SYSNO_INDEX(syscallno);
 
@@ -1786,6 +1961,9 @@ void VG_(client_syscall) ( ThreadId tid,
       is interrupted by a signal. */
    sysno = sci->orig_args.sysno;
 
+#  if defined(VGO_freebsd)
+   tst->arch.vex.guest_SC_CLASS = sci->orig_args.klass;
+#  endif
    /* It's sometimes useful, as a crude debugging hack, to get a
       stack trace at each (or selected) syscalls. */
    if (0 && sysno == __NR_ioctl) {
@@ -2186,7 +2364,7 @@ void VG_(post_syscall) (ThreadId tid)
 /* These are addresses within ML_(do_syscall_for_client_WRK).  See
    syscall-$PLAT.S for details. 
 */
-#if defined(VGO_linux)
+#if defined(VGO_linux) || defined(VGO_netbsd)
   extern const Addr ML_(blksys_setup);
   extern const Addr ML_(blksys_restart);
   extern const Addr ML_(blksys_complete);
@@ -2246,6 +2424,26 @@ void ML_(fixup_guest_state_to_restart_sy
       vg_assert(p[0] == 0xcd && p[1] == 0x80);
    }
 
+#elif defined(VGP_amd64_netbsd)
+   /* XXX: we support different syscall methods. */
+   arch->vex.guest_RIP -= 2;             // sizeof(syscall)
+            
+   /* Make sure our caller is actually sane, and we're really backing
+      back over a syscall.
+      
+      syscall == 0F 05
+   */
+   {
+      UChar *p = (UChar *)arch->vex.guest_RIP;
+   
+      if (p[0] != 0x0F || p[1] != 0x05)
+         VG_(message)(Vg_DebugMsg,
+                      "?! restarting over syscall at %#llx %02x %02x\n",
+                      arch->vex.guest_RIP, p[0], p[1]);
+      
+      vg_assert(p[0] == 0x0F && p[1] == 0x05);
+   }
+
 #elif defined(VGP_amd64_linux)
    arch->vex.guest_RIP -= 2;             // sizeof(syscall)
 
@@ -2592,7 +2790,7 @@ VG_(fixup_guest_state_after_syscall_inte
    th_regs = &tst->arch;
    sci     = & syscallInfo[tid];
 
-#  if defined(VGO_linux)
+#  if defined(VGO_linux) || defined(VGO_netbsd)
    outside_range
       = ip < ML_(blksys_setup) || ip >= ML_(blksys_finished);
    in_setup_to_restart
