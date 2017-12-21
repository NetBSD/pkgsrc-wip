$NetBSD$

--- lib/sanitizer_common/sanitizer_platform_limits_netbsd.h.orig	2017-12-21 18:53:10.665534563 +0000
+++ lib/sanitizer_common/sanitizer_platform_limits_netbsd.h
@@ -58,32 +58,34 @@ extern unsigned struct_rlimit_sz;
 extern unsigned struct_utimbuf_sz;
 extern unsigned struct_timespec_sz;
 
-struct __sanitizer_iocb {
+extern unsigned struct_kevent_sz;
+
+union __sanitizer_sigval {
+  int sival_int;
+  uptr sival_ptr;
+};
+
+struct __sanitizer_sigevent {
+  int sigev_notify;
+  int sigev_signo;
+  union __sanitizer_sigval sigev_value;
+  uptr sigev_notify_function;
+  uptr sigev_notify_attributes;
+};
+
+struct __sanitizer_aiocb {
   u64 aio_offset;
   uptr aio_buf;
-  long aio_nbytes;
-  u32 aio_fildes;
-  u32 aio_lio_opcode;
-  long aio_reqprio;
-#if SANITIZER_WORDSIZE == 64
-  u8 aio_sigevent[32];
-#else
-  u8 aio_sigevent[20];
-#endif
-  u32 _state;
-  u32 _errno;
+  uptr aio_nbytes;
+  int aio_fildes;
+  int aio_lio_opcode;
+  int aio_reqprio;
+  struct __sanitizer_sigevent aio_sigevent;
+  int _state;
+  int _errno;
   long _retval;
 };
 
-struct __sanitizer___sysctl_args {
-  int *name;
-  int nlen;
-  void *oldval;
-  uptr *oldlenp;
-  void *newval;
-  uptr newlen;
-};
-
 struct __sanitizer_sem_t {
   uptr data[5];
 };
@@ -135,6 +137,23 @@ typedef unsigned __sanitizer_pthread_key
 
 typedef long long __sanitizer_time_t;
 
+typedef int __sanitizer_suseconds_t;
+
+struct __sanitizer_timeval {
+  __sanitizer_time_t tv_sec;
+  __sanitizer_suseconds_t tv_usec;
+};
+
+struct __sanitizer_itimerval {
+  struct __sanitizer_timeval it_interval;
+  struct __sanitizer_timeval it_value;
+};
+
+struct __sanitizer_timespec {
+  __sanitizer_time_t tv_sec;
+  long tv_nsec;
+};
+
 struct __sanitizer_passwd {
   char *pw_name;
   char *pw_passwd;
@@ -189,6 +208,12 @@ struct __sanitizer_msghdr {
   unsigned msg_controllen;
   int msg_flags;
 };
+
+struct __sanitizer_mmsghdr {
+  struct __sanitizer_msghdr msg_hdr;
+  unsigned int msg_len;
+};
+
 struct __sanitizer_cmsghdr {
   unsigned cmsg_len;
   int cmsg_level;
@@ -241,6 +266,22 @@ struct __sanitizer_sigaction {
   int sa_flags;
 };
 
+extern unsigned struct_sigaltstack_sz;
+
+typedef unsigned int __sanitizer_sigset13_t;
+
+struct __sanitizer_sigaction13 {
+  __sanitizer_sighandler_ptr osa_handler;
+  __sanitizer_sigset13_t osa_mask;
+  int osa_flags;
+};
+
+struct __sanitizer_sigaltstack {
+  void *ss_sp;
+  uptr ss_size;
+  int ss_flags;
+};
+
 typedef __sanitizer_sigset_t __sanitizer_kernel_sigset_t;
 
 struct __sanitizer_kernel_sigaction_t {
@@ -298,6 +339,8 @@ struct __sanitizer_pollfd {
 
 typedef unsigned __sanitizer_nfds_t;
 
+typedef int __sanitizer_lwpid_t;
+
 struct __sanitizer_glob_t {
   uptr gl_pathc;
   uptr gl_matchc;
@@ -317,6 +360,30 @@ extern int glob_altdirfunc;
 
 extern unsigned path_max;
 
+extern int ptrace_pt_io;
+extern int ptrace_pt_set_event_mask;
+extern int ptrace_pt_set_siginfo;
+extern int ptrace_pt_set_sigmask;
+extern int ptrace_piod_write_d;
+extern int ptrace_piod_write_i;
+extern int ptrace_pt_setregs;
+extern int ptrace_pt_setfpregs;
+extern int ptrace_pt_setdbregs;
+
+struct __sanitizer_ptrace_io_desc {
+  int piod_op;
+  void *piod_offs;
+  void *piod_addr;
+  uptr piod_len;
+};
+
+extern unsigned struct_ptrace_ptrace_event_struct_sz;
+extern unsigned struct_ptrace_ptrace_siginfo_struct_sz;
+
+extern unsigned struct_ptrace_reg_struct_sz;
+extern unsigned struct_ptrace_fpreg_struct_sz;
+extern unsigned struct_ptrace_dbreg_struct_sz;
+
 struct __sanitizer_wordexp_t {
   uptr we_wordc;
   char **we_wordv;
