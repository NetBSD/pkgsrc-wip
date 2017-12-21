$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc.orig	2017-11-28 08:23:47.000000000 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.cc
@@ -35,6 +35,7 @@
 #include <semaphore.h>
 #include <signal.h>
 #include <stddef.h>
+#include <sys/event.h>
 #include <sys/filio.h>
 #include <sys/ipc.h>
 #include <sys/mman.h>
@@ -99,18 +100,66 @@ unsigned struct_sockaddr_sz = sizeof(str
 unsigned ucontext_t_sz = sizeof(ucontext_t);
 unsigned struct_rlimit_sz = sizeof(struct rlimit);
 unsigned struct_timespec_sz = sizeof(struct timespec);
+unsigned struct_kevent_sz = sizeof(struct kevent);
 unsigned struct_utimbuf_sz = sizeof(struct utimbuf);
 unsigned struct_itimerspec_sz = sizeof(struct itimerspec);
 unsigned struct_timex_sz = sizeof(struct timex);
 unsigned struct_msqid_ds_sz = sizeof(struct msqid_ds);
 unsigned struct_mq_attr_sz = sizeof(struct mq_attr);
 unsigned struct_statvfs_sz = sizeof(struct statvfs);
+unsigned struct_sigaltstack_sz = sizeof(stack_t);
 
 const uptr sig_ign = (uptr)SIG_IGN;
 const uptr sig_dfl = (uptr)SIG_DFL;
 const uptr sig_err = (uptr)SIG_ERR;
 const uptr sa_siginfo = (uptr)SA_SIGINFO;
 
+int ptrace_pt_io = PT_IO;
+int ptrace_pt_set_event_mask = PT_SET_EVENT_MASK;
+int ptrace_pt_set_siginfo = PT_SET_SIGINFO;
+int ptrace_pt_set_sigmask = PT_SET_SIGMASK;
+int ptrace_piod_write_d = PIOD_WRITE_D;
+int ptrace_piod_write_i = PIOD_WRITE_I;
+
+#if defined(PT_SETREGS)
+int ptrace_pt_setregs = PT_SETREGS;
+#else
+int ptrace_pt_setregs = -1;
+#endif
+
+#if defined(PT_SETFPREGS)
+int ptrace_pt_setfpregs = PT_SETFPREGS;
+#else
+int ptrace_pt_setfpregs = -1;
+#endif
+
+#if defined(PT_SETDBREGS)
+int ptrace_pt_setdbregs = PT_SETDBREGS;
+#else
+int ptrace_pt_setdbregs = -1;
+#endif
+
+unsigned struct_ptrace_ptrace_event_struct_sz = sizeof(ptrace_event_t);
+unsigned struct_ptrace_ptrace_siginfo_struct_sz = sizeof(ptrace_siginfo_t);
+
+#if defined(PT_SETREGS)
+unsigned struct_ptrace_reg_struct_sz = sizeof(struct reg);
+#else
+unsigned struct_ptrace_reg_struct_sz = -1;
+#endif
+
+#if defined(PT_SETFPREGS)
+unsigned struct_ptrace_fpreg_struct_sz = sizeof(struct fpreg);
+#else
+unsigned struct_ptrace_fpreg_struct_sz = -1;
+#endif
+
+#if defined(PT_SETDBREGS)
+unsigned struct_ptrace_dbreg_struct_sz = sizeof(struct dbreg);
+#else
+unsigned struct_ptrace_dbreg_struct_sz = -1;
+#endif
+
 int shmctl_ipc_stat = (int)IPC_STAT;
 
 unsigned struct_utmp_sz = sizeof(struct utmp);
