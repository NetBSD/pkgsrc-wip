$NetBSD$

--- lib/sanitizer_common/sanitizer_netbsd_syscalls.inc.orig	2017-12-21 18:53:40.996191468 +0000
+++ lib/sanitizer_common/sanitizer_netbsd_syscalls.inc
@@ -0,0 +1,2277 @@
+//===-- sanitizer_common_syscalls.inc ---------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+//
+// Common syscalls handlers for tools like AddressSanitizer,
+// ThreadSanitizer, MemorySanitizer, etc.
+//
+// This file should be included into the tool's interceptor file,
+// which has to define it's own macros:
+//   COMMON_SYSCALL_PRE_READ_RANGE
+//          Called in prehook for regions that will be read by the kernel and
+//          must be initialized.
+//   COMMON_SYSCALL_PRE_WRITE_RANGE
+//          Called in prehook for regions that will be written to by the kernel
+//          and must be addressable. The actual write range may be smaller than
+//          reported in the prehook. See POST_WRITE_RANGE.
+//   COMMON_SYSCALL_POST_READ_RANGE
+//          Called in posthook for regions that were read by the kernel. Does
+//          not make much sense.
+//   COMMON_SYSCALL_POST_WRITE_RANGE
+//          Called in posthook for regions that were written to by the kernel
+//          and are now initialized.
+//   COMMON_SYSCALL_ACQUIRE(addr)
+//          Acquire memory visibility from addr.
+//   COMMON_SYSCALL_RELEASE(addr)
+//          Release memory visibility to addr.
+//   COMMON_SYSCALL_FD_CLOSE(fd)
+//          Called before closing file descriptor fd.
+//   COMMON_SYSCALL_FD_ACQUIRE(fd)
+//          Acquire memory visibility from fd.
+//   COMMON_SYSCALL_FD_RELEASE(fd)
+//          Release memory visibility to fd.
+//   COMMON_SYSCALL_PRE_FORK()
+//          Called before fork syscall.
+//   COMMON_SYSCALL_POST_FORK(long res)
+//          Called after fork syscall.
+//
+// DO NOT EDIT! THIS FILE HAS BEEN GENERATED!
+//
+// Generated with: generate_netbsd_syscalls.awk
+// Generated date: 2017-12-21
+// Generated from: syscalls.master,v 1.290 2017/12/19 19:40:03 kamil Exp
+//
+//===----------------------------------------------------------------------===//
+
+#include "sanitizer_platform.h"
+#if SANITIZER_NETBSD
+
+#include "sanitizer_libc.h"
+
+#define PRE_SYSCALL(name)                                                      \
+  SANITIZER_INTERFACE_ATTRIBUTE void __sanitizer_syscall_pre_impl_##name
+#define PRE_READ(p, s) COMMON_SYSCALL_PRE_READ_RANGE(p, s)
+#define PRE_WRITE(p, s) COMMON_SYSCALL_PRE_WRITE_RANGE(p, s)
+
+#define POST_SYSCALL(name)                                                     \
+  SANITIZER_INTERFACE_ATTRIBUTE void __sanitizer_syscall_post_impl_##name
+#define POST_READ(p, s) COMMON_SYSCALL_POST_READ_RANGE(p, s)
+#define POST_WRITE(p, s) COMMON_SYSCALL_POST_WRITE_RANGE(p, s)
+
+#ifndef COMMON_SYSCALL_ACQUIRE
+#define COMMON_SYSCALL_ACQUIRE(addr) ((void)(addr))
+#endif
+
+#ifndef COMMON_SYSCALL_RELEASE
+#define COMMON_SYSCALL_RELEASE(addr) ((void)(addr))
+#endif
+
+#ifndef COMMON_SYSCALL_FD_CLOSE
+#define COMMON_SYSCALL_FD_CLOSE(fd) ((void)(fd))
+#endif
+
+#ifndef COMMON_SYSCALL_FD_ACQUIRE
+#define COMMON_SYSCALL_FD_ACQUIRE(fd) ((void)(fd))
+#endif
+
+#ifndef COMMON_SYSCALL_FD_RELEASE
+#define COMMON_SYSCALL_FD_RELEASE(fd) ((void)(fd))
+#endif
+
+#ifndef COMMON_SYSCALL_PRE_FORK
+#define COMMON_SYSCALL_PRE_FORK()                                              \
+  {}
+#endif
+
+#ifndef COMMON_SYSCALL_POST_FORK
+#define COMMON_SYSCALL_POST_FORK(res)                                          \
+  {}
+#endif
+
+// FIXME: do some kind of PRE_READ for all syscall arguments (int(s) and such).
+
+extern "C" {
+#define SYS_MAXSYSARGS 8
+PRE_SYSCALL(syscall)(long code_, long args_[SYS_MAXSYSARGS]) {
+  /* Nothing to do */
+}
+POST_SYSCALL(syscall)(long res, long code_, long args_[SYS_MAXSYSARGS]) {
+  /* Nothing to do */
+}
+PRE_SYSCALL(exit)(long rval_) { /* Nothing to do */ }
+POST_SYSCALL(exit)(long res, long rval_) { /* Nothing to do */ }
+PRE_SYSCALL(fork)(void) { COMMON_SYSCALL_PRE_FORK(); }
+POST_SYSCALL(fork)(long res) { COMMON_SYSCALL_POST_FORK(res); }
+PRE_SYSCALL(read)(long fd_, void *buf_, long nbyte_) {
+  if (buf_) {
+    PRE_WRITE(buf_, nbyte_);
+  }
+}
+POST_SYSCALL(read)(long res, long fd_, void *buf_, long nbyte_) {}
+PRE_SYSCALL(write)(long fd_, void *buf_, long nbyte_) {
+  if (buf_) {
+    PRE_READ(buf_, nbyte_);
+  }
+}
+POST_SYSCALL(write)(long res, long fd_, void *buf_, long nbyte_) {}
+PRE_SYSCALL(open)(void *path_, long flags_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(open)(long res, void *path_, long flags_, long mode_) {}
+PRE_SYSCALL(close)(long fd_) { COMMON_SYSCALL_FD_CLOSE((int)fd_); }
+POST_SYSCALL(close)(long res, long fd_) {}
+PRE_SYSCALL(compat_50_wait4)
+(long pid_, void *status_, long options_, void *rusage_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_50_wait4)
+(long res, long pid_, void *status_, long options_, void *rusage_) {}
+PRE_SYSCALL(compat_43_ocreat)(void *path_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(compat_43_ocreat)(long res, void *path_, long mode_) {}
+PRE_SYSCALL(link)(void *path_, void *link_) {
+  const char *path = (const char *)path_;
+  const char *link = (const char *)link_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+  if (link) {
+    PRE_READ(path, __sanitizer::internal_strlen(link) + 1);
+  }
+}
+POST_SYSCALL(link)(long res, void *path_, void *link_) {}
+PRE_SYSCALL(unlink)(void *path_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(unlink)(long res, void *path_) {}
+/* syscall 11 has been skipped */
+PRE_SYSCALL(chdir)(void *path_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(chdir)(long res, void *path_) {}
+PRE_SYSCALL(fchdir)(long fd_) { /* Nothing to do */ }
+POST_SYSCALL(fchdir)(long res, long fd_) {}
+PRE_SYSCALL(compat_50_mknod)(void *path_, long mode_, long dev_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(compat_50_mknod)(long res, void *path_, long mode_, long dev_) {}
+PRE_SYSCALL(chmod)(void *path_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(chmod)(long res, void *path_, long mode_) {}
+PRE_SYSCALL(chown)(void *path_, long uid_, long gid_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(chown)(long res, void *path_, long uid_, long gid_) {}
+PRE_SYSCALL(break)(void *nsize_) { /* Nothing to do */ }
+POST_SYSCALL(break)(long res, void *nsize_) {}
+PRE_SYSCALL(compat_20_getfsstat)(void *buf_, long bufsize_, long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_20_getfsstat)
+(long res, void *buf_, long bufsize_, long flags_) {}
+PRE_SYSCALL(compat_43_olseek)(long fd_, long offset_, long whence_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_olseek)
+(long res, long fd_, long offset_, long whence_) {}
+PRE_SYSCALL(getpid)(void) { /* Nothing to do */ }
+POST_SYSCALL(getpid)(long res) {}
+PRE_SYSCALL(compat_40_mount)
+(void *type_, void *path_, long flags_, void *data_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_40_mount)
+(long res, void *type_, void *path_, long flags_, void *data_) {}
+PRE_SYSCALL(unmount)(void *path_, long flags_) { /* Nothing to do */ }
+POST_SYSCALL(unmount)(long res, void *path_, long flags_) {}
+PRE_SYSCALL(setuid)(long uid_) { /* Nothing to do */ }
+POST_SYSCALL(setuid)(long res, long uid_) {}
+PRE_SYSCALL(getuid)(void) { /* Nothing to do */ }
+POST_SYSCALL(getuid)(long res) {}
+PRE_SYSCALL(geteuid)(void) { /* Nothing to do */ }
+POST_SYSCALL(geteuid)(long res) {}
+PRE_SYSCALL(ptrace)(long req_, long pid_, void *addr_, long data_) {
+  if (req_ == ptrace_pt_io) {
+    struct __sanitizer_ptrace_io_desc *piod =
+        (struct __sanitizer_ptrace_io_desc *)addr_;
+    if (piod->piod_op == ptrace_piod_write_d ||
+        piod->piod_op == ptrace_piod_write_i) {
+      PRE_READ(piod->piod_addr, piod->piod_len);
+    }
+  } else if (req_ == ptrace_pt_set_event_mask) {
+    PRE_READ(addr_, struct_ptrace_ptrace_event_struct_sz);
+  } else if (req_ == ptrace_pt_set_siginfo) {
+    PRE_READ(addr_, struct_ptrace_ptrace_siginfo_struct_sz);
+  } else if (req_ == ptrace_pt_set_sigmask) {
+    PRE_READ(addr_, sizeof(__sanitizer_sigset_t));
+  } else if (req_ == ptrace_pt_setregs) {
+    PRE_READ(addr_, struct_ptrace_reg_struct_sz);
+  } else if (req_ == ptrace_pt_setfpregs) {
+    PRE_READ(addr_, struct_ptrace_fpreg_struct_sz);
+  } else if (req_ == ptrace_pt_setdbregs) {
+    PRE_READ(addr_, struct_ptrace_dbreg_struct_sz);
+  }
+}
+POST_SYSCALL(ptrace)(long res, long req_, long pid_, void *addr_, long data_) {}
+PRE_SYSCALL(recvmsg)(long s_, void *msg_, long flags_) {
+  PRE_READ(msg_, sizeof(__sanitizer_msghdr));
+}
+POST_SYSCALL(recvmsg)(long res, long s_, void *msg_, long flags_) {}
+PRE_SYSCALL(sendmsg)(long s_, void *msg_, long flags_) { /* Nothing to do */ }
+POST_SYSCALL(sendmsg)(long res, long s_, void *msg_, long flags_) {}
+PRE_SYSCALL(recvfrom)
+(long s_, void *buf_, long len_, long flags_, void *from_, void *fromlenaddr_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(recvfrom)
+(long res, long s_, void *buf_, long len_, long flags_, void *from_,
+  void *fromlenaddr_) {}
+PRE_SYSCALL(accept)(long s_, void *name_, void *anamelen_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(accept)(long res, long s_, void *name_, void *anamelen_) {}
+PRE_SYSCALL(getpeername)(long fdes_, void *asa_, void *alen_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(getpeername)(long res, long fdes_, void *asa_, void *alen_) {}
+PRE_SYSCALL(getsockname)(long fdes_, void *asa_, void *alen_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(getsockname)(long res, long fdes_, void *asa_, void *alen_) {}
+PRE_SYSCALL(access)(void *path_, long flags_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(access)(long res, void *path_, long flags_) {}
+PRE_SYSCALL(chflags)(void *path_, long flags_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(chflags)(long res, void *path_, long flags_) {}
+PRE_SYSCALL(fchflags)(long fd_, long flags_) { /* Nothing to do */ }
+POST_SYSCALL(fchflags)(long res, long fd_, long flags_) {}
+PRE_SYSCALL(sync)(void) { /* Nothing to do */ }
+POST_SYSCALL(sync)(long res) {}
+PRE_SYSCALL(kill)(long pid_, long signum_) { /* Nothing to do */ }
+POST_SYSCALL(kill)(long res, long pid_, long signum_) {}
+PRE_SYSCALL(compat_43_stat43)(void *path_, void *ub_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(compat_43_stat43)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(getppid)(void) { /* Nothing to do */ }
+POST_SYSCALL(getppid)(long res) {}
+PRE_SYSCALL(compat_43_lstat43)(void *path_, void *ub_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(compat_43_lstat43)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(dup)(long fd_) { /* Nothing to do */ }
+POST_SYSCALL(dup)(long res, long fd_) {}
+PRE_SYSCALL(pipe)(void) { /* Nothing to do */ }
+POST_SYSCALL(pipe)(long res) {}
+PRE_SYSCALL(getegid)(void) { /* Nothing to do */ }
+POST_SYSCALL(getegid)(long res) {}
+PRE_SYSCALL(profil)(void *samples_, long size_, long offset_, long scale_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(profil)
+(long res, void *samples_, long size_, long offset_, long scale_) {}
+PRE_SYSCALL(ktrace)(void *fname_, long ops_, long facs_, long pid_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(ktrace)
+(long res, void *fname_, long ops_, long facs_, long pid_) {}
+PRE_SYSCALL(compat_13_sigaction13)(long signum_, void *nsa_, void *osa_) {
+  struct __sanitizer_sigaction13 *nsa = (struct __sanitizer_sigaction13 *)nsa_;
+  if (nsa) {
+    PRE_READ(&nsa->osa_handler, sizeof(nsa->osa_handler));
+    PRE_READ(&nsa->osa_flags, sizeof(nsa->osa_flags));
+    PRE_READ(&nsa->osa_mask, sizeof(nsa->osa_mask));
+  }
+}
+POST_SYSCALL(compat_13_sigaction13)
+(long res, long signum_, void *nsa_, void *osa_) {}
+PRE_SYSCALL(getgid)(void) { /* Nothing to do */ }
+POST_SYSCALL(getgid)(long res) {}
+PRE_SYSCALL(compat_13_sigprocmask13)(long how_, long mask_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_13_sigprocmask13)(long res, long how_, long mask_) {}
+PRE_SYSCALL(__getlogin)(void *namebuf_, long namelen_) { /* Nothing to do */ }
+POST_SYSCALL(__getlogin)(long res, void *namebuf_, long namelen_) {}
+PRE_SYSCALL(__setlogin)(void *namebuf_) {
+  const char *namebuf = (const char *)namebuf_;
+  if (namebuf) {
+    PRE_READ(namebuf, __sanitizer::internal_strlen(namebuf) + 1);
+  }
+}
+POST_SYSCALL(__setlogin)(long res, void *namebuf_) {}
+PRE_SYSCALL(acct)(void *path_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(acct)(long res, void *path_) {}
+PRE_SYSCALL(compat_13_sigpending13)(void) { /* Nothing to do */ }
+POST_SYSCALL(compat_13_sigpending13)(long res) {}
+PRE_SYSCALL(compat_13_sigaltstack13)(void *nss_, void *oss_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_13_sigaltstack13)(long res, void *nss_, void *oss_) {}
+PRE_SYSCALL(ioctl)(long fd_, long com_, void *data_) { /* Nothing to do */ }
+POST_SYSCALL(ioctl)(long res, long fd_, long com_, void *data_) {}
+PRE_SYSCALL(compat_12_oreboot)(long opt_) { /* Nothing to do */ }
+POST_SYSCALL(compat_12_oreboot)(long res, long opt_) {}
+PRE_SYSCALL(revoke)(void *path_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(revoke)(long res, void *path_) {}
+PRE_SYSCALL(symlink)(void *path_, void *link_) {
+  const char *path = (const char *)path_;
+  const char *link = (const char *)link_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+  if (link) {
+    PRE_READ(link, __sanitizer::internal_strlen(link) + 1);
+  }
+}
+POST_SYSCALL(symlink)(long res, void *path_, void *link_) {}
+PRE_SYSCALL(readlink)(void *path_, void *buf_, long count_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(readlink)(long res, void *path_, void *buf_, long count_) {}
+PRE_SYSCALL(execve)(void *path_, void *argp_, void *envp_) {
+  const char *path = (const char *)path_;
+  char **argp = (char **)argp_;
+  char **envp = (char **)envp_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+  if (argp && argp[0]) {
+    char *a = argp[0];
+    while (a++) {
+      PRE_READ(a, __sanitizer::internal_strlen(a) + 1);
+    }
+  }
+  if (envp && envp[0]) {
+    char *e = envp[0];
+    while (e++) {
+      PRE_READ(e, __sanitizer::internal_strlen(e) + 1);
+    }
+  }
+}
+POST_SYSCALL(execve)(long res, void *path_, void *argp_, void *envp_) {}
+PRE_SYSCALL(umask)(long newmask_) { /* Nothing to do */ }
+POST_SYSCALL(umask)(long res, long newmask_) {}
+PRE_SYSCALL(chroot)(void *path_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(chroot)(long res, void *path_) {}
+PRE_SYSCALL(compat_43_fstat43)(long fd_, void *sb_) { /* Nothing to do */ }
+POST_SYSCALL(compat_43_fstat43)(long res, long fd_, void *sb_) {}
+PRE_SYSCALL(compat_43_ogetkerninfo)
+(long op_, void *where_, void *size_, long arg_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_ogetkerninfo)
+(long res, long op_, void *where_, void *size_, long arg_) {}
+PRE_SYSCALL(compat_43_ogetpagesize)(void) { /* Nothing to do */ }
+POST_SYSCALL(compat_43_ogetpagesize)(long res) {}
+PRE_SYSCALL(compat_12_msync)(void *addr_, long len_) { /* Nothing to do */ }
+POST_SYSCALL(compat_12_msync)(long res, void *addr_, long len_) {}
+PRE_SYSCALL(vfork)(void) { /* Nothing to do */ }
+POST_SYSCALL(vfork)(long res) {}
+/* syscall 67 has been skipped */
+/* syscall 68 has been skipped */
+/* syscall 69 has been skipped */
+/* syscall 70 has been skipped */
+PRE_SYSCALL(compat_43_ommap)
+(void *addr_, long len_, long prot_, long flags_, long fd_, long pos_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_ommap)
+(long res, void *addr_, long len_, long prot_, long flags_, long fd_,
+  long pos_) {}
+/* syscall 72 has been skipped */
+PRE_SYSCALL(munmap)(void *addr_, long len_) { /* Nothing to do */ }
+POST_SYSCALL(munmap)(long res, void *addr_, long len_) {}
+PRE_SYSCALL(mprotect)(void *addr_, long len_, long prot_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(mprotect)(long res, void *addr_, long len_, long prot_) {}
+PRE_SYSCALL(madvise)(void *addr_, long len_, long behav_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(madvise)(long res, void *addr_, long len_, long behav_) {}
+/* syscall 76 has been skipped */
+/* syscall 77 has been skipped */
+PRE_SYSCALL(mincore)(void *addr_, long len_, void *vec_) { /* Nothing to do */ }
+POST_SYSCALL(mincore)(long res, void *addr_, long len_, void *vec_) {}
+PRE_SYSCALL(getgroups)(long gidsetsize_, void *gidset_) { /* Nothing to do */ }
+POST_SYSCALL(getgroups)(long res, long gidsetsize_, void *gidset_) {}
+PRE_SYSCALL(setgroups)(long gidsetsize_, void *gidset_) {
+  unsigned int *gidset = (unsigned int *)gidset_;
+  if (gidset) {
+    PRE_READ(gidset, sizeof(*gidset) * gidsetsize_);
+  }
+}
+POST_SYSCALL(setgroups)(long res, long gidsetsize_, void *gidset_) {}
+PRE_SYSCALL(getpgrp)(void) { /* Nothing to do */ }
+POST_SYSCALL(getpgrp)(long res) {}
+PRE_SYSCALL(setpgid)(long pid_, long pgid_) { /* Nothing to do */ }
+POST_SYSCALL(setpgid)(long res, long pid_, long pgid_) {}
+PRE_SYSCALL(compat_50_setitimer)(long which_, void *itv_, void *oitv_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_50_setitimer)
+(long res, long which_, void *itv_, void *oitv_) {}
+PRE_SYSCALL(compat_43_owait)(void) { /* Nothing to do */ }
+POST_SYSCALL(compat_43_owait)(long res) {}
+PRE_SYSCALL(compat_12_oswapon)(void *name_) {
+  const char *name = (const char *)name_;
+  if (name) {
+    PRE_READ(name, __sanitizer::internal_strlen(name) + 1);
+  }
+}
+POST_SYSCALL(compat_12_oswapon)(long res, void *name_) {}
+PRE_SYSCALL(compat_50_getitimer)(long which_, void *itv_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_50_getitimer)(long res, long which_, void *itv_) {}
+PRE_SYSCALL(compat_43_ogethostname)(void *hostname_, long len_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_ogethostname)(long res, void *hostname_, long len_) {}
+PRE_SYSCALL(compat_43_osethostname)(void *hostname_, long len_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_osethostname)(long res, void *hostname_, long len_) {}
+PRE_SYSCALL(compat_43_ogetdtablesize)(void) { /* Nothing to do */ }
+POST_SYSCALL(compat_43_ogetdtablesize)(long res) {}
+PRE_SYSCALL(dup2)(long from_, long to_) { /* Nothing to do */ }
+POST_SYSCALL(dup2)(long res, long from_, long to_) {}
+/* syscall 91 has been skipped */
+PRE_SYSCALL(fcntl)(long fd_, long cmd_, void *arg_) { /* Nothing to do */ }
+POST_SYSCALL(fcntl)(long res, long fd_, long cmd_, void *arg_) {}
+PRE_SYSCALL(compat_50_select)
+(long nd_, void *in_, void *ou_, void *ex_, void *tv_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_50_select)
+(long res, long nd_, void *in_, void *ou_, void *ex_, void *tv_) {}
+/* syscall 94 has been skipped */
+PRE_SYSCALL(fsync)(long fd_) { /* Nothing to do */ }
+POST_SYSCALL(fsync)(long res, long fd_) {}
+PRE_SYSCALL(setpriority)(long which_, long who_, long prio_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(setpriority)(long res, long which_, long who_, long prio_) {}
+PRE_SYSCALL(compat_30_socket)(long domain_, long type_, long protocol_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_30_socket)
+(long res, long domain_, long type_, long protocol_) {}
+PRE_SYSCALL(connect)(long s_, void *name_, long namelen_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(connect)(long res, long s_, void *name_, long namelen_) {}
+PRE_SYSCALL(compat_43_oaccept)(long s_, void *name_, void *anamelen_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_oaccept)
+(long res, long s_, void *name_, void *anamelen_) {}
+PRE_SYSCALL(getpriority)(long which_, long who_) { /* Nothing to do */ }
+POST_SYSCALL(getpriority)(long res, long which_, long who_) {}
+PRE_SYSCALL(compat_43_osend)(long s_, void *buf_, long len_, long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_osend)
+(long res, long s_, void *buf_, long len_, long flags_) {}
+PRE_SYSCALL(compat_43_orecv)(long s_, void *buf_, long len_, long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(compat_43_orecv)
+(long res, long s_, void *buf_, long len_, long flags_) {}
+PRE_SYSCALL(compat_13_sigreturn13)(void *sigcntxp_) { /* Missing on amd64? */ }
+POST_SYSCALL(compat_13_sigreturn13)(long res, void *sigcntxp_) {}
+PRE_SYSCALL(bind)(long s_, void *name_, long namelen_) { /* Nothing to do */ }
+POST_SYSCALL(bind)(long res, long s_, void *name_, long namelen_) {}
+PRE_SYSCALL(setsockopt)
+(long s_, long level_, long name_, void *val_, long valsize_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(setsockopt)
+(long res, long s_, long level_, long name_, void *val_, long valsize_) {}
+PRE_SYSCALL(listen)(long s_, long backlog_) { /* Nothing to do */ }
+POST_SYSCALL(listen)(long res, long s_, long backlog_) {}
+/* syscall 107 has been skipped */
+PRE_SYSCALL(compat_43_osigvec)(long signum_, void *nsv_, void *osv_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_43_osigvec)
+(long res, long signum_, void *nsv_, void *osv_) {}
+PRE_SYSCALL(compat_43_osigblock)(long mask_) { /* TODO */ }
+POST_SYSCALL(compat_43_osigblock)(long res, long mask_) {}
+PRE_SYSCALL(compat_43_osigsetmask)(long mask_) { /* TODO */ }
+POST_SYSCALL(compat_43_osigsetmask)(long res, long mask_) {}
+PRE_SYSCALL(compat_13_sigsuspend13)(long mask_) { /* TODO */ }
+POST_SYSCALL(compat_13_sigsuspend13)(long res, long mask_) {}
+PRE_SYSCALL(compat_43_osigstack)(void *nss_, void *oss_) { /* TODO */ }
+POST_SYSCALL(compat_43_osigstack)(long res, void *nss_, void *oss_) {}
+PRE_SYSCALL(compat_43_orecvmsg)(long s_, void *msg_, long flags_) { /* TODO */ }
+POST_SYSCALL(compat_43_orecvmsg)(long res, long s_, void *msg_, long flags_) {}
+PRE_SYSCALL(compat_43_osendmsg)(long s_, void *msg_, long flags_) { /* TODO */ }
+POST_SYSCALL(compat_43_osendmsg)(long res, long s_, void *msg_, long flags_) {}
+/* syscall 115 has been skipped */
+PRE_SYSCALL(compat_50_gettimeofday)(void *tp_, void *tzp_) { /* TODO */ }
+POST_SYSCALL(compat_50_gettimeofday)(long res, void *tp_, void *tzp_) {}
+PRE_SYSCALL(compat_50_getrusage)(long who_, void *rusage_) { /* TODO */ }
+POST_SYSCALL(compat_50_getrusage)(long res, long who_, void *rusage_) {}
+PRE_SYSCALL(getsockopt)
+(long s_, long level_, long name_, void *val_, void *avalsize_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(getsockopt)
+(long res, long s_, long level_, long name_, void *val_, void *avalsize_) {}
+/* syscall 119 has been skipped */
+PRE_SYSCALL(readv)(long fd_, void *iovp_, long iovcnt_) { /* Nothing to do */ }
+POST_SYSCALL(readv)(long res, long fd_, void *iovp_, long iovcnt_) {}
+PRE_SYSCALL(writev)(long fd_, void *iovp_, long iovcnt_) { /* Nothing to do */ }
+POST_SYSCALL(writev)(long res, long fd_, void *iovp_, long iovcnt_) {}
+PRE_SYSCALL(compat_50_settimeofday)(void *tv_, void *tzp_) { /* TODO */ }
+POST_SYSCALL(compat_50_settimeofday)(long res, void *tv_, void *tzp_) {}
+PRE_SYSCALL(fchown)(long fd_, long uid_, long gid_) { /* Nothing to do */ }
+POST_SYSCALL(fchown)(long res, long fd_, long uid_, long gid_) {}
+PRE_SYSCALL(fchmod)(long fd_, long mode_) { /* Nothing to do */ }
+POST_SYSCALL(fchmod)(long res, long fd_, long mode_) {}
+PRE_SYSCALL(compat_43_orecvfrom)
+(long s_, void *buf_, long len_, long flags_, void *from_, void *fromlenaddr_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_43_orecvfrom)
+(long res, long s_, void *buf_, long len_, long flags_, void *from_,
+  void *fromlenaddr_) {}
+PRE_SYSCALL(setreuid)(long ruid_, long euid_) { /* Nothing to do */ }
+POST_SYSCALL(setreuid)(long res, long ruid_, long euid_) {}
+PRE_SYSCALL(setregid)(long rgid_, long egid_) { /* Nothing to do */ }
+POST_SYSCALL(setregid)(long res, long rgid_, long egid_) {}
+PRE_SYSCALL(rename)(void *from_, void *to_) {
+  const char *from = (const char *)from_;
+  const char *to = (const char *)to_;
+  if (from) {
+    PRE_READ(from, __sanitizer::internal_strlen(from) + 1);
+  }
+  if (to) {
+    PRE_READ(to, __sanitizer::internal_strlen(to) + 1);
+  }
+}
+POST_SYSCALL(rename)(long res, void *from_, void *to_) {}
+PRE_SYSCALL(compat_43_otruncate)(void *path_, long length_) { /* TODO */ }
+POST_SYSCALL(compat_43_otruncate)(long res, void *path_, long length_) {}
+PRE_SYSCALL(compat_43_oftruncate)(long fd_, long length_) { /* TODO */ }
+POST_SYSCALL(compat_43_oftruncate)(long res, long fd_, long length_) {}
+PRE_SYSCALL(flock)(long fd_, long how_) { /* Nothing to do */ }
+POST_SYSCALL(flock)(long res, long fd_, long how_) {}
+PRE_SYSCALL(mkfifo)(void *path_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(mkfifo)(long res, void *path_, long mode_) {}
+PRE_SYSCALL(sendto)
+(long s_, void *buf_, long len_, long flags_, void *to_, long tolen_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(sendto)
+(long res, long s_, void *buf_, long len_, long flags_, void *to_,
+  long tolen_) {}
+PRE_SYSCALL(shutdown)(long s_, long how_) { /* Nothing to do */ }
+POST_SYSCALL(shutdown)(long res, long s_, long how_) {}
+PRE_SYSCALL(socketpair)(long domain_, long type_, long protocol_, void *rsv_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(socketpair)
+(long res, long domain_, long type_, long protocol_, void *rsv_) {}
+PRE_SYSCALL(mkdir)(void *path_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(mkdir)(long res, void *path_, long mode_) {}
+PRE_SYSCALL(rmdir)(void *path_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(rmdir)(long res, void *path_) {}
+PRE_SYSCALL(compat_50_utimes)(void *path_, void *tptr_) { /* TODO */ }
+POST_SYSCALL(compat_50_utimes)(long res, void *path_, void *tptr_) {}
+/* syscall 139 has been skipped */
+PRE_SYSCALL(compat_50_adjtime)(void *delta_, void *olddelta_) { /* TODO */ }
+POST_SYSCALL(compat_50_adjtime)(long res, void *delta_, void *olddelta_) {}
+PRE_SYSCALL(compat_43_ogetpeername)(long fdes_, void *asa_, void *alen_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_43_ogetpeername)
+(long res, long fdes_, void *asa_, void *alen_) {}
+PRE_SYSCALL(compat_43_ogethostid)(void) { /* TODO */ }
+POST_SYSCALL(compat_43_ogethostid)(long res) {}
+PRE_SYSCALL(compat_43_osethostid)(long hostid_) { /* TODO */ }
+POST_SYSCALL(compat_43_osethostid)(long res, long hostid_) {}
+PRE_SYSCALL(compat_43_ogetrlimit)(long which_, void *rlp_) { /* TODO */ }
+POST_SYSCALL(compat_43_ogetrlimit)(long res, long which_, void *rlp_) {}
+PRE_SYSCALL(compat_43_osetrlimit)(long which_, void *rlp_) { /* TODO */ }
+POST_SYSCALL(compat_43_osetrlimit)(long res, long which_, void *rlp_) {}
+PRE_SYSCALL(compat_43_okillpg)(long pgid_, long signum_) { /* TODO */ }
+POST_SYSCALL(compat_43_okillpg)(long res, long pgid_, long signum_) {}
+PRE_SYSCALL(setsid)(void) { /* Nothing to do */ }
+POST_SYSCALL(setsid)(long res) {}
+PRE_SYSCALL(compat_50_quotactl)(void *path_, long cmd_, long uid_, void *arg_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_quotactl)
+(long res, void *path_, long cmd_, long uid_, void *arg_) {}
+PRE_SYSCALL(compat_43_oquota)(void) { /* TODO */ }
+POST_SYSCALL(compat_43_oquota)(long res) {}
+PRE_SYSCALL(compat_43_ogetsockname)(long fdec_, void *asa_, void *alen_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_43_ogetsockname)
+(long res, long fdec_, void *asa_, void *alen_) {}
+/* syscall 151 has been skipped */
+/* syscall 152 has been skipped */
+/* syscall 153 has been skipped */
+/* syscall 154 has been skipped */
+PRE_SYSCALL(nfssvc)(long flag_, void *argp_) { /* Nothing to do */ }
+POST_SYSCALL(nfssvc)(long res, long flag_, void *argp_) {}
+PRE_SYSCALL(compat_43_ogetdirentries)
+(long fd_, void *buf_, long count_, void *basep_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_43_ogetdirentries)
+(long res, long fd_, void *buf_, long count_, void *basep_) {}
+PRE_SYSCALL(compat_20_statfs)(void *path_, void *buf_) { /* TODO */ }
+POST_SYSCALL(compat_20_statfs)(long res, void *path_, void *buf_) {}
+PRE_SYSCALL(compat_20_fstatfs)(long fd_, void *buf_) { /* TODO */ }
+POST_SYSCALL(compat_20_fstatfs)(long res, long fd_, void *buf_) {}
+/* syscall 159 has been skipped */
+/* syscall 160 has been skipped */
+PRE_SYSCALL(compat_30_getfh)(void *fname_, void *fhp_) { /* TODO */ }
+POST_SYSCALL(compat_30_getfh)(long res, void *fname_, void *fhp_) {}
+PRE_SYSCALL(compat_09_ogetdomainname)(void *domainname_, long len_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_09_ogetdomainname)
+(long res, void *domainname_, long len_) {}
+PRE_SYSCALL(compat_09_osetdomainname)(void *domainname_, long len_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_09_osetdomainname)
+(long res, void *domainname_, long len_) {}
+PRE_SYSCALL(compat_09_ouname)(void *name_) { /* TODO */ }
+POST_SYSCALL(compat_09_ouname)(long res, void *name_) {}
+PRE_SYSCALL(sysarch)(long op_, void *parms_) { /* TODO */ }
+POST_SYSCALL(sysarch)(long res, long op_, void *parms_) {}
+/* syscall 166 has been skipped */
+/* syscall 167 has been skipped */
+/* syscall 168 has been skipped */
+#if !defined(_LP64)
+PRE_SYSCALL(compat_10_osemsys)
+(long which_, long a2_, long a3_, long a4_, long a5_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_10_osemsys)
+(long res, long which_, long a2_, long a3_, long a4_, long a5_) {}
+#else
+/* syscall 169 has been skipped */
+#endif
+#if !defined(_LP64)
+PRE_SYSCALL(compat_10_omsgsys)
+(long which_, long a2_, long a3_, long a4_, long a5_, long a6_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_10_omsgsys)
+(long res, long which_, long a2_, long a3_, long a4_, long a5_, long a6_) {}
+#else
+/* syscall 170 has been skipped */
+#endif
+#if !defined(_LP64)
+PRE_SYSCALL(compat_10_oshmsys)(long which_, long a2_, long a3_, long a4_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_10_oshmsys)
+(long res, long which_, long a2_, long a3_, long a4_) {}
+#else
+/* syscall 171 has been skipped */
+#endif
+/* syscall 172 has been skipped */
+PRE_SYSCALL(pread)(long fd_, void *buf_, long nbyte_, long PAD_, long offset_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(pread)
+(long res, long fd_, void *buf_, long nbyte_, long PAD_, long offset_) {}
+PRE_SYSCALL(pwrite)
+(long fd_, void *buf_, long nbyte_, long PAD_, long offset_) {
+  if (buf_) {
+    PRE_READ(buf_, nbyte_);
+  }
+}
+POST_SYSCALL(pwrite)
+(long res, long fd_, void *buf_, long nbyte_, long PAD_, long offset_) {}
+PRE_SYSCALL(compat_30_ntp_gettime)(void *ntvp_) { /* TODO */ }
+POST_SYSCALL(compat_30_ntp_gettime)(long res, void *ntvp_) {}
+#if defined(NTP) || !defined(_KERNEL_OPT)
+PRE_SYSCALL(ntp_adjtime)(void *tp_) { /* Nothing to do */ }
+POST_SYSCALL(ntp_adjtime)(long res, void *tp_) {}
+#else
+/* syscall 176 has been skipped */
+#endif
+/* syscall 177 has been skipped */
+/* syscall 178 has been skipped */
+/* syscall 179 has been skipped */
+/* syscall 180 has been skipped */
+PRE_SYSCALL(setgid)(long gid_) { /* Nothing to do */ }
+POST_SYSCALL(setgid)(long res, long gid_) {}
+PRE_SYSCALL(setegid)(long egid_) { /* Nothing to do */ }
+POST_SYSCALL(setegid)(long res, long egid_) {}
+PRE_SYSCALL(seteuid)(long euid_) { /* Nothing to do */ }
+POST_SYSCALL(seteuid)(long res, long euid_) {}
+PRE_SYSCALL(lfs_bmapv)(void *fsidp_, void *blkiov_, long blkcnt_) { /* TODO */ }
+POST_SYSCALL(lfs_bmapv)(long res, void *fsidp_, void *blkiov_, long blkcnt_) {}
+PRE_SYSCALL(lfs_markv)(void *fsidp_, void *blkiov_, long blkcnt_) { /* TODO */ }
+POST_SYSCALL(lfs_markv)(long res, void *fsidp_, void *blkiov_, long blkcnt_) {}
+PRE_SYSCALL(lfs_segclean)(void *fsidp_, long segment_) { /* TODO */ }
+POST_SYSCALL(lfs_segclean)(long res, void *fsidp_, long segment_) {}
+PRE_SYSCALL(compat_50_lfs_segwait)(void *fsidp_, void *tv_) { /* TODO */ }
+POST_SYSCALL(compat_50_lfs_segwait)(long res, void *fsidp_, void *tv_) {}
+PRE_SYSCALL(compat_12_stat12)(void *path_, void *ub_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(compat_12_stat12)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(compat_12_fstat12)(long fd_, void *sb_) { /* Nothing to do */ }
+POST_SYSCALL(compat_12_fstat12)(long res, long fd_, void *sb_) {}
+PRE_SYSCALL(compat_12_lstat12)(void *path_, void *ub_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(compat_12_lstat12)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(pathconf)(void *path_, long name_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(pathconf)(long res, void *path_, long name_) {}
+PRE_SYSCALL(fpathconf)(long fd_, long name_) { /* Nothing to do */ }
+POST_SYSCALL(fpathconf)(long res, long fd_, long name_) {}
+/* syscall 193 has been skipped */
+PRE_SYSCALL(getrlimit)(long which_, void *rlp_) { /* Nothing to do */ }
+POST_SYSCALL(getrlimit)(long res, long which_, void *rlp_) {}
+PRE_SYSCALL(setrlimit)(long which_, void *rlp_) { /* Nothing to do */ }
+POST_SYSCALL(setrlimit)(long res, long which_, void *rlp_) {}
+PRE_SYSCALL(compat_12_getdirentries)
+(long fd_, void *buf_, long count_, void *basep_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_12_getdirentries)
+(long res, long fd_, void *buf_, long count_, void *basep_) {}
+PRE_SYSCALL(mmap)
+(void *addr_, long len_, long prot_, long flags_, long fd_, long PAD_,
+  long pos_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(mmap)
+(long res, void *addr_, long len_, long prot_, long flags_, long fd_, long PAD_,
+  long pos_) {}
+PRE_SYSCALL(__syscall)(long code_, long args_[SYS_MAXSYSARGS]) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__syscall)(long res, long code_, long args_[SYS_MAXSYSARGS]) {}
+PRE_SYSCALL(lseek)(long fd_, long PAD_, long offset_, long whence_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(lseek)
+(long res, long fd_, long PAD_, long offset_, long whence_) {}
+PRE_SYSCALL(truncate)(void *path_, long PAD_, long length_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(truncate)(long res, void *path_, long PAD_, long length_) {}
+PRE_SYSCALL(ftruncate)(long fd_, long PAD_, long length_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(ftruncate)(long res, long fd_, long PAD_, long length_) {}
+PRE_SYSCALL(__sysctl)
+(void *name_, long namelen_, void *oldv_, void *oldlenp_, void *newv_,
+  long newlen_) {
+  const int *name = (const int *)name_;
+  if (name) {
+    PRE_READ(name, namelen_ * sizeof(*name));
+  }
+  if (newv_) {
+    PRE_READ(name, newlen_);
+  }
+}
+POST_SYSCALL(__sysctl)
+(long res, void *name_, long namelen_, void *oldv_, void *oldlenp_, void *newv_,
+  long newlen_) {}
+PRE_SYSCALL(mlock)(void *addr_, long len_) { /* Nothing to do */ }
+POST_SYSCALL(mlock)(long res, void *addr_, long len_) {}
+PRE_SYSCALL(munlock)(void *addr_, long len_) { /* Nothing to do */ }
+POST_SYSCALL(munlock)(long res, void *addr_, long len_) {}
+PRE_SYSCALL(undelete)(void *path_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(undelete)(long res, void *path_) {}
+PRE_SYSCALL(compat_50_futimes)(long fd_, void *tptr_) { /* TODO */ }
+POST_SYSCALL(compat_50_futimes)(long res, long fd_, void *tptr_) {}
+PRE_SYSCALL(getpgid)(long pid_) { /* Nothing to do */ }
+POST_SYSCALL(getpgid)(long res, long pid_) {}
+PRE_SYSCALL(reboot)(long opt_, void *bootstr_) {
+  const char *bootstr = (const char *)bootstr_;
+  if (bootstr) {
+    PRE_READ(bootstr, __sanitizer::internal_strlen(bootstr) + 1);
+  }
+}
+POST_SYSCALL(reboot)(long res, long opt_, void *bootstr_) {}
+PRE_SYSCALL(poll)(void *fds_, long nfds_, long timeout_) { /* Nothing to do */ }
+POST_SYSCALL(poll)(long res, void *fds_, long nfds_, long timeout_) {}
+PRE_SYSCALL(afssys)
+(long id_, long a1_, long a2_, long a3_, long a4_, long a5_, long a6_) {
+  /* TODO */
+}
+POST_SYSCALL(afssys)
+(long res, long id_, long a1_, long a2_, long a3_, long a4_, long a5_,
+  long a6_) {}
+/* syscall 211 has been skipped */
+/* syscall 212 has been skipped */
+/* syscall 213 has been skipped */
+/* syscall 214 has been skipped */
+/* syscall 215 has been skipped */
+/* syscall 216 has been skipped */
+/* syscall 217 has been skipped */
+/* syscall 218 has been skipped */
+/* syscall 219 has been skipped */
+PRE_SYSCALL(compat_14___semctl)
+(long semid_, long semnum_, long cmd_, void *arg_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_14___semctl)
+(long res, long semid_, long semnum_, long cmd_, void *arg_) {}
+PRE_SYSCALL(semget)(long key_, long nsems_, long semflg_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(semget)(long res, long key_, long nsems_, long semflg_) {}
+PRE_SYSCALL(semop)(long semid_, void *sops_, long nsops_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(semop)(long res, long semid_, void *sops_, long nsops_) {}
+PRE_SYSCALL(semconfig)(long flag_) { /* Nothing to do */ }
+POST_SYSCALL(semconfig)(long res, long flag_) {}
+PRE_SYSCALL(compat_14_msgctl)(long msqid_, long cmd_, void *buf_) { /* TODO */ }
+POST_SYSCALL(compat_14_msgctl)(long res, long msqid_, long cmd_, void *buf_) {}
+PRE_SYSCALL(msgget)(long key_, long msgflg_) { /* Nothing to do */ }
+POST_SYSCALL(msgget)(long res, long key_, long msgflg_) {}
+PRE_SYSCALL(msgsnd)(long msqid_, void *msgp_, long msgsz_, long msgflg_) {
+  if (msgp_) {
+    PRE_READ(msgp_, msgsz_);
+  }
+}
+POST_SYSCALL(msgsnd)
+(long res, long msqid_, void *msgp_, long msgsz_, long msgflg_) {}
+PRE_SYSCALL(msgrcv)
+(long msqid_, void *msgp_, long msgsz_, long msgtyp_, long msgflg_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(msgrcv)
+(long res, long msqid_, void *msgp_, long msgsz_, long msgtyp_, long msgflg_) {}
+PRE_SYSCALL(shmat)(long shmid_, void *shmaddr_, long shmflg_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(shmat)(long res, long shmid_, void *shmaddr_, long shmflg_) {}
+PRE_SYSCALL(compat_14_shmctl)(long shmid_, long cmd_, void *buf_) { /* TODO */ }
+POST_SYSCALL(compat_14_shmctl)(long res, long shmid_, long cmd_, void *buf_) {}
+PRE_SYSCALL(shmdt)(void *shmaddr_) { /* Nothing to do */ }
+POST_SYSCALL(shmdt)(long res, void *shmaddr_) {}
+PRE_SYSCALL(shmget)(long key_, long size_, long shmflg_) { /* Nothing to do */ }
+POST_SYSCALL(shmget)(long res, long key_, long size_, long shmflg_) {}
+PRE_SYSCALL(compat_50_clock_gettime)(long clock_id_, void *tp_) { /* TODO */ }
+POST_SYSCALL(compat_50_clock_gettime)(long res, long clock_id_, void *tp_) {}
+PRE_SYSCALL(compat_50_clock_settime)(long clock_id_, void *tp_) { /* TODO */ }
+POST_SYSCALL(compat_50_clock_settime)(long res, long clock_id_, void *tp_) {}
+PRE_SYSCALL(compat_50_clock_getres)(long clock_id_, void *tp_) { /* TODO */ }
+POST_SYSCALL(compat_50_clock_getres)(long res, long clock_id_, void *tp_) {}
+PRE_SYSCALL(timer_create)(long clock_id_, void *evp_, void *timerid_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(timer_create)
+(long res, long clock_id_, void *evp_, void *timerid_) {}
+PRE_SYSCALL(timer_delete)(long timerid_) { /* Nothing to do */ }
+POST_SYSCALL(timer_delete)(long res, long timerid_) {}
+PRE_SYSCALL(compat_50_timer_settime)
+(long timerid_, long flags_, void *value_, void *ovalue_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_timer_settime)
+(long res, long timerid_, long flags_, void *value_, void *ovalue_) {}
+PRE_SYSCALL(compat_50_timer_gettime)(long timerid_, void *value_) { /* TODO */ }
+POST_SYSCALL(compat_50_timer_gettime)(long res, long timerid_, void *value_) {}
+PRE_SYSCALL(timer_getoverrun)(long timerid_) { /* Nothing to do */ }
+POST_SYSCALL(timer_getoverrun)(long res, long timerid_) {}
+PRE_SYSCALL(compat_50_nanosleep)(void *rqtp_, void *rmtp_) { /* TODO */ }
+POST_SYSCALL(compat_50_nanosleep)(long res, void *rqtp_, void *rmtp_) {}
+PRE_SYSCALL(fdatasync)(long fd_) { /* Nothing to do */ }
+POST_SYSCALL(fdatasync)(long res, long fd_) {}
+PRE_SYSCALL(mlockall)(long flags_) { /* Nothing to do */ }
+POST_SYSCALL(mlockall)(long res, long flags_) {}
+PRE_SYSCALL(munlockall)(void) { /* Nothing to do */ }
+POST_SYSCALL(munlockall)(long res) {}
+PRE_SYSCALL(compat_50___sigtimedwait)(void *set_, void *info_, void *timeout_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50___sigtimedwait)
+(long res, void *set_, void *info_, void *timeout_) {}
+PRE_SYSCALL(sigqueueinfo)(long pid_, void *info_) {
+  if (info_) {
+    PRE_READ(info_, siginfo_t_sz);
+  }
+}
+POST_SYSCALL(sigqueueinfo)(long res, long pid_, void *info_) {}
+PRE_SYSCALL(modctl)(long cmd_, void *arg_) { /* TODO */ }
+POST_SYSCALL(modctl)(long res, long cmd_, void *arg_) {}
+PRE_SYSCALL(_ksem_init)(long value_, void *idp_) {}
+POST_SYSCALL(_ksem_init)(long res, long value_, void *idp_) {}
+PRE_SYSCALL(_ksem_open)
+(void *name_, long oflag_, long mode_, long value_, void *idp_) {
+  const char *name = (const char *)name_;
+  if (name) {
+    PRE_READ(name, __sanitizer::internal_strlen(name) + 1);
+  }
+}
+POST_SYSCALL(_ksem_open)
+(long res, void *name_, long oflag_, long mode_, long value_, void *idp_) {}
+PRE_SYSCALL(_ksem_unlink)(void *name_) {
+  const char *name = (const char *)name_;
+  if (name) {
+    PRE_READ(name, __sanitizer::internal_strlen(name) + 1);
+  }
+}
+POST_SYSCALL(_ksem_unlink)(long res, void *name_) {}
+PRE_SYSCALL(_ksem_close)(long id_) { /* Nothing to do */ }
+POST_SYSCALL(_ksem_close)(long res, long id_) {}
+PRE_SYSCALL(_ksem_post)(long id_) { /* Nothing to do */ }
+POST_SYSCALL(_ksem_post)(long res, long id_) {}
+PRE_SYSCALL(_ksem_wait)(long id_) { /* Nothing to do */ }
+POST_SYSCALL(_ksem_wait)(long res, long id_) {}
+PRE_SYSCALL(_ksem_trywait)(long id_) { /* Nothing to do */ }
+POST_SYSCALL(_ksem_trywait)(long res, long id_) {}
+PRE_SYSCALL(_ksem_getvalue)(long id_, void *value_) { /* Nothing to do */ }
+POST_SYSCALL(_ksem_getvalue)(long res, long id_, void *value_) {}
+PRE_SYSCALL(_ksem_destroy)(long id_) { /* Nothing to do */ }
+POST_SYSCALL(_ksem_destroy)(long res, long id_) {}
+PRE_SYSCALL(_ksem_timedwait)(long id_, void *abstime_) {
+  if (abstime_) {
+    PRE_READ(abstime_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(_ksem_timedwait)(long res, long id_, void *abstime_) {}
+PRE_SYSCALL(mq_open)(void *name_, long oflag_, long mode_, void *attr_) {
+  const char *name = (const char *)name_;
+  if (name) {
+    PRE_READ(name, __sanitizer::internal_strlen(name) + 1);
+  }
+}
+POST_SYSCALL(mq_open)
+(long res, void *name_, long oflag_, long mode_, void *attr_) {}
+PRE_SYSCALL(mq_close)(long mqdes_) { /* Nothing to do */ }
+POST_SYSCALL(mq_close)(long res, long mqdes_) {}
+PRE_SYSCALL(mq_unlink)(void *name_) {
+  const char *name = (const char *)name_;
+  if (name) {
+    PRE_READ(name, __sanitizer::internal_strlen(name) + 1);
+  }
+}
+POST_SYSCALL(mq_unlink)(long res, void *name_) {}
+PRE_SYSCALL(mq_getattr)(long mqdes_, void *mqstat_) { /* Nothing to do */ }
+POST_SYSCALL(mq_getattr)(long res, long mqdes_, void *mqstat_) {}
+PRE_SYSCALL(mq_setattr)(long mqdes_, void *mqstat_, void *omqstat_) {
+  if (mqstat_) {
+    PRE_READ(mqstat_, struct_mq_attr_sz);
+  }
+}
+POST_SYSCALL(mq_setattr)
+(long res, long mqdes_, void *mqstat_, void *omqstat_) {}
+PRE_SYSCALL(mq_notify)(long mqdes_, void *notification_) {
+  if (notification_) {
+    PRE_READ(notification_, struct_sigevent_sz);
+  }
+}
+POST_SYSCALL(mq_notify)(long res, long mqdes_, void *notification_) {}
+PRE_SYSCALL(mq_send)
+(long mqdes_, void *msg_ptr_, long msg_len_, long msg_prio_) {
+  if (msg_ptr_) {
+    PRE_READ(msg_ptr_, msg_len_);
+  }
+}
+POST_SYSCALL(mq_send)
+(long res, long mqdes_, void *msg_ptr_, long msg_len_, long msg_prio_) {}
+PRE_SYSCALL(mq_receive)
+(long mqdes_, void *msg_ptr_, long msg_len_, void *msg_prio_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(mq_receive)
+(long res, long mqdes_, void *msg_ptr_, long msg_len_, void *msg_prio_) {}
+PRE_SYSCALL(compat_50_mq_timedsend)
+(long mqdes_, void *msg_ptr_, long msg_len_, long msg_prio_,
+  void *abs_timeout_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_mq_timedsend)
+(long res, long mqdes_, void *msg_ptr_, long msg_len_, long msg_prio_,
+  void *abs_timeout_) {}
+PRE_SYSCALL(compat_50_mq_timedreceive)
+(long mqdes_, void *msg_ptr_, long msg_len_, void *msg_prio_,
+  void *abs_timeout_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_mq_timedreceive)
+(long res, long mqdes_, void *msg_ptr_, long msg_len_, void *msg_prio_,
+  void *abs_timeout_) {}
+/* syscall 267 has been skipped */
+/* syscall 268 has been skipped */
+/* syscall 269 has been skipped */
+PRE_SYSCALL(__posix_rename)(void *from_, void *to_) {
+  const char *from = (const char *)from_;
+  const char *to = (const char *)to_;
+  if (from_) {
+    PRE_READ(from, __sanitizer::internal_strlen(from) + 1);
+  }
+  if (to) {
+    PRE_READ(to, __sanitizer::internal_strlen(to) + 1);
+  }
+}
+POST_SYSCALL(__posix_rename)(long res, void *from_, void *to_) {}
+PRE_SYSCALL(swapctl)(long cmd_, void *arg_, long misc_) { /* TODO */ }
+POST_SYSCALL(swapctl)(long res, long cmd_, void *arg_, long misc_) {}
+PRE_SYSCALL(compat_30_getdents)(long fd_, void *buf_, long count_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_30_getdents)(long res, long fd_, void *buf_, long count_) {}
+PRE_SYSCALL(minherit)(void *addr_, long len_, long inherit_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(minherit)(long res, void *addr_, long len_, long inherit_) {}
+PRE_SYSCALL(lchmod)(void *path_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(lchmod)(long res, void *path_, long mode_) {}
+PRE_SYSCALL(lchown)(void *path_, long uid_, long gid_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(lchown)(long res, void *path_, long uid_, long gid_) {}
+PRE_SYSCALL(compat_50_lutimes)(void *path_, void *tptr_) { /* TODO */ }
+POST_SYSCALL(compat_50_lutimes)(long res, void *path_, void *tptr_) {}
+PRE_SYSCALL(__msync13)(void *addr_, long len_, long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__msync13)(long res, void *addr_, long len_, long flags_) {}
+PRE_SYSCALL(compat_30___stat13)(void *path_, void *ub_) { /* TODO */ }
+POST_SYSCALL(compat_30___stat13)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(compat_30___fstat13)(long fd_, void *sb_) { /* TODO */ }
+POST_SYSCALL(compat_30___fstat13)(long res, long fd_, void *sb_) {}
+PRE_SYSCALL(compat_30___lstat13)(void *path_, void *ub_) { /* TODO */ }
+POST_SYSCALL(compat_30___lstat13)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(__sigaltstack14)(void *nss_, void *oss_) {
+  if (nss_) {
+    PRE_READ(nss_, struct_sigaltstack_sz);
+  }
+  if (oss_) {
+    PRE_READ(oss_, struct_sigaltstack_sz);
+  }
+}
+POST_SYSCALL(__sigaltstack14)(long res, void *nss_, void *oss_) {}
+PRE_SYSCALL(__vfork14)(void) { /* Nothing to do */ }
+POST_SYSCALL(__vfork14)(long res) {}
+PRE_SYSCALL(__posix_chown)(void *path_, long uid_, long gid_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(__posix_chown)(long res, void *path_, long uid_, long gid_) {}
+PRE_SYSCALL(__posix_fchown)(long fd_, long uid_, long gid_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__posix_fchown)(long res, long fd_, long uid_, long gid_) {}
+PRE_SYSCALL(__posix_lchown)(void *path_, long uid_, long gid_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(__posix_lchown)(long res, void *path_, long uid_, long gid_) {}
+PRE_SYSCALL(getsid)(long pid_) { /* Nothing to do */ }
+POST_SYSCALL(getsid)(long res, long pid_) {}
+PRE_SYSCALL(__clone)(long flags_, void *stack_) { /* Nothing to do */ }
+POST_SYSCALL(__clone)(long res, long flags_, void *stack_) {}
+PRE_SYSCALL(fktrace)(long fd_, long ops_, long facs_, long pid_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(fktrace)(long res, long fd_, long ops_, long facs_, long pid_) {}
+PRE_SYSCALL(preadv)
+(long fd_, void *iovp_, long iovcnt_, long PAD_, long offset_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(preadv)
+(long res, long fd_, void *iovp_, long iovcnt_, long PAD_, long offset_) {}
+PRE_SYSCALL(pwritev)
+(long fd_, void *iovp_, long iovcnt_, long PAD_, long offset_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(pwritev)
+(long res, long fd_, void *iovp_, long iovcnt_, long PAD_, long offset_) {}
+PRE_SYSCALL(compat_16___sigaction14)(long signum_, void *nsa_, void *osa_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_16___sigaction14)
+(long res, long signum_, void *nsa_, void *osa_) {}
+PRE_SYSCALL(__sigpending14)(void *set_) { /* Nothing to do */ }
+POST_SYSCALL(__sigpending14)(long res, void *set_) {}
+PRE_SYSCALL(__sigprocmask14)(long how_, void *set_, void *oset_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__sigprocmask14)(long res, long how_, void *set_, void *oset_) {}
+PRE_SYSCALL(__sigsuspend14)(void *set_) {
+  if (set_) {
+    PRE_READ(set_, sizeof(__sanitizer_sigset_t));
+  }
+}
+POST_SYSCALL(__sigsuspend14)(long res, void *set_) {}
+PRE_SYSCALL(compat_16___sigreturn14)(void *sigcntxp_) { /* TODO */ }
+POST_SYSCALL(compat_16___sigreturn14)(long res, void *sigcntxp_) {}
+PRE_SYSCALL(__getcwd)(void *bufp_, long length_) { /* Nothing to do */ }
+POST_SYSCALL(__getcwd)(long res, void *bufp_, long length_) {}
+PRE_SYSCALL(fchroot)(long fd_) { /* Nothing to do */ }
+POST_SYSCALL(fchroot)(long res, long fd_) {}
+PRE_SYSCALL(compat_30_fhopen)(void *fhp_, long flags_) { /* TODO */ }
+POST_SYSCALL(compat_30_fhopen)(long res, void *fhp_, long flags_) {}
+PRE_SYSCALL(compat_30_fhstat)(void *fhp_, void *sb_) { /* TODO */ }
+POST_SYSCALL(compat_30_fhstat)(long res, void *fhp_, void *sb_) {}
+PRE_SYSCALL(compat_20_fhstatfs)(void *fhp_, void *buf_) { /* TODO */ }
+POST_SYSCALL(compat_20_fhstatfs)(long res, void *fhp_, void *buf_) {}
+PRE_SYSCALL(compat_50_____semctl13)
+(long semid_, long semnum_, long cmd_, void *arg_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_____semctl13)
+(long res, long semid_, long semnum_, long cmd_, void *arg_) {}
+PRE_SYSCALL(compat_50___msgctl13)(long msqid_, long cmd_, void *buf_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50___msgctl13)
+(long res, long msqid_, long cmd_, void *buf_) {}
+PRE_SYSCALL(compat_50___shmctl13)(long shmid_, long cmd_, void *buf_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50___shmctl13)
+(long res, long shmid_, long cmd_, void *buf_) {}
+PRE_SYSCALL(lchflags)(void *path_, long flags_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(lchflags)(long res, void *path_, long flags_) {}
+PRE_SYSCALL(issetugid)(void) { /* Nothing to do */ }
+POST_SYSCALL(issetugid)(long res) {}
+PRE_SYSCALL(utrace)(void *label_, void *addr_, long len_) {
+  const char *label = (const char *)label_;
+  if (label) {
+    PRE_READ(label, __sanitizer::internal_strlen(label) + 1);
+  }
+  if (addr_) {
+    PRE_READ(addr_, len_);
+  }
+}
+POST_SYSCALL(utrace)(long res, void *label_, void *addr_, long len_) {}
+PRE_SYSCALL(getcontext)(void *ucp_) { /* Nothing to do */ }
+POST_SYSCALL(getcontext)(long res, void *ucp_) {}
+PRE_SYSCALL(setcontext)(void *ucp_) {
+  if (ucp_) {
+    PRE_READ(ucp_, ucontext_t_sz);
+  }
+}
+POST_SYSCALL(setcontext)(long res, void *ucp_) {}
+PRE_SYSCALL(_lwp_create)(void *ucp_, long flags_, void *new_lwp_) {
+  if (ucp_) {
+    PRE_READ(ucp_, ucontext_t_sz);
+  }
+}
+POST_SYSCALL(_lwp_create)(long res, void *ucp_, long flags_, void *new_lwp_) {}
+PRE_SYSCALL(_lwp_exit)(void) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_exit)(long res) {}
+PRE_SYSCALL(_lwp_self)(void) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_self)(long res) {}
+PRE_SYSCALL(_lwp_wait)(long wait_for_, void *departed_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_wait)(long res, long wait_for_, void *departed_) {}
+PRE_SYSCALL(_lwp_suspend)(long target_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_suspend)(long res, long target_) {}
+PRE_SYSCALL(_lwp_continue)(long target_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_continue)(long res, long target_) {}
+PRE_SYSCALL(_lwp_wakeup)(long target_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_wakeup)(long res, long target_) {}
+PRE_SYSCALL(_lwp_getprivate)(void) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_getprivate)(long res) {}
+PRE_SYSCALL(_lwp_setprivate)(void *ptr_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_setprivate)(long res, void *ptr_) {}
+PRE_SYSCALL(_lwp_kill)(long target_, long signo_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_kill)(long res, long target_, long signo_) {}
+PRE_SYSCALL(_lwp_detach)(long target_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_detach)(long res, long target_) {}
+PRE_SYSCALL(compat_50__lwp_park)
+(void *ts_, long unpark_, void *hint_, void *unparkhint_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50__lwp_park)
+(long res, void *ts_, long unpark_, void *hint_, void *unparkhint_) {}
+PRE_SYSCALL(_lwp_unpark)(long target_, void *hint_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_unpark)(long res, long target_, void *hint_) {}
+PRE_SYSCALL(_lwp_unpark_all)(void *targets_, long ntargets_, void *hint_) {
+  if (targets_) {
+    PRE_READ(targets_, ntargets_ * sizeof(__sanitizer_lwpid_t));
+  }
+}
+POST_SYSCALL(_lwp_unpark_all)
+(long res, void *targets_, long ntargets_, void *hint_) {}
+PRE_SYSCALL(_lwp_setname)(long target_, void *name_) {
+  const char *name = (const char *)name_;
+  if (name) {
+    PRE_READ(name, __sanitizer::internal_strlen(name) + 1);
+  }
+}
+POST_SYSCALL(_lwp_setname)(long res, long target_, void *name_) {}
+PRE_SYSCALL(_lwp_getname)(long target_, void *name_, long len_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(_lwp_getname)(long res, long target_, void *name_, long len_) {}
+PRE_SYSCALL(_lwp_ctl)(long features_, void **address_) { /* Nothing to do */ }
+POST_SYSCALL(_lwp_ctl)(long res, long features_, void **address_) {}
+/* syscall 326 has been skipped */
+/* syscall 327 has been skipped */
+/* syscall 328 has been skipped */
+/* syscall 329 has been skipped */
+PRE_SYSCALL(compat_60_sa_register)
+(void *newv_, void **oldv_, long flags_, long stackinfo_offset_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_60_sa_register)
+(long res, void *newv_, void **oldv_, long flags_, long stackinfo_offset_) {}
+PRE_SYSCALL(compat_60_sa_stacks)(long num_, void *stacks_) { /* TODO */ }
+POST_SYSCALL(compat_60_sa_stacks)(long res, long num_, void *stacks_) {}
+PRE_SYSCALL(compat_60_sa_enable)(void) { /* TODO */ }
+POST_SYSCALL(compat_60_sa_enable)(long res) {}
+PRE_SYSCALL(compat_60_sa_setconcurrency)(long concurrency_) { /* TODO */ }
+POST_SYSCALL(compat_60_sa_setconcurrency)(long res, long concurrency_) {}
+PRE_SYSCALL(compat_60_sa_yield)(void) { /* TODO */ }
+POST_SYSCALL(compat_60_sa_yield)(long res) {}
+PRE_SYSCALL(compat_60_sa_preempt)(long sa_id_) { /* TODO */ }
+POST_SYSCALL(compat_60_sa_preempt)(long res, long sa_id_) {}
+/* syscall 336 has been skipped */
+/* syscall 337 has been skipped */
+/* syscall 338 has been skipped */
+/* syscall 339 has been skipped */
+PRE_SYSCALL(__sigaction_sigtramp)
+(long signum_, void *nsa_, void *osa_, void *tramp_, long vers_) {
+  if (nsa_) {
+    PRE_READ(nsa_, sizeof(__sanitizer_sigaction));
+  }
+}
+POST_SYSCALL(__sigaction_sigtramp)
+(long res, long signum_, void *nsa_, void *osa_, void *tramp_, long vers_) {}
+PRE_SYSCALL(pmc_get_info)(long ctr_, long op_, void *args_) { /* TODO */ }
+POST_SYSCALL(pmc_get_info)(long res, long ctr_, long op_, void *args_) {}
+PRE_SYSCALL(pmc_control)(long ctr_, long op_, void *args_) { /* TODO */ }
+POST_SYSCALL(pmc_control)(long res, long ctr_, long op_, void *args_) {}
+PRE_SYSCALL(rasctl)(void *addr_, long len_, long op_) { /* Nothing to do */ }
+POST_SYSCALL(rasctl)(long res, void *addr_, long len_, long op_) {}
+PRE_SYSCALL(kqueue)(void) { /* Nothing to do */ }
+POST_SYSCALL(kqueue)(long res) {}
+PRE_SYSCALL(compat_50_kevent)
+(long fd_, void *changelist_, long nchanges_, void *eventlist_, long nevents_,
+  void *timeout_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_kevent)
+(long res, long fd_, void *changelist_, long nchanges_, void *eventlist_,
+  long nevents_, void *timeout_) {}
+PRE_SYSCALL(_sched_setparam)
+(long pid_, long lid_, long policy_, void *params_) {
+  if (params_) {
+    PRE_READ(params_, struct_sched_param_sz);
+  }
+}
+POST_SYSCALL(_sched_setparam)
+(long res, long pid_, long lid_, long policy_, void *params_) {}
+PRE_SYSCALL(_sched_getparam)
+(long pid_, long lid_, void *policy_, void *params_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(_sched_getparam)
+(long res, long pid_, long lid_, void *policy_, void *params_) {}
+PRE_SYSCALL(_sched_setaffinity)
+(long pid_, long lid_, long size_, void *cpuset_) {
+  if (cpuset_) {
+    PRE_READ(cpuset_, size_);
+  }
+}
+POST_SYSCALL(_sched_setaffinity)
+(long res, long pid_, long lid_, long size_, void *cpuset_) {}
+PRE_SYSCALL(_sched_getaffinity)
+(long pid_, long lid_, long size_, void *cpuset_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(_sched_getaffinity)
+(long res, long pid_, long lid_, long size_, void *cpuset_) {}
+PRE_SYSCALL(sched_yield)(void) { /* Nothing to do */ }
+POST_SYSCALL(sched_yield)(long res) {}
+PRE_SYSCALL(_sched_protect)(long priority_) { /* Nothing to do */ }
+POST_SYSCALL(_sched_protect)(long res, long priority_) {}
+/* syscall 352 has been skipped */
+/* syscall 353 has been skipped */
+PRE_SYSCALL(fsync_range)(long fd_, long flags_, long start_, long length_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(fsync_range)
+(long res, long fd_, long flags_, long start_, long length_) {}
+PRE_SYSCALL(uuidgen)(void *store_, long count_) { /* Nothing to do */ }
+POST_SYSCALL(uuidgen)(long res, void *store_, long count_) {}
+PRE_SYSCALL(getvfsstat)(void *buf_, long bufsize_, long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(getvfsstat)(long res, void *buf_, long bufsize_, long flags_) {}
+PRE_SYSCALL(statvfs1)(void *path_, void *buf_, long flags_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(statvfs1)(long res, void *path_, void *buf_, long flags_) {}
+PRE_SYSCALL(fstatvfs1)(long fd_, void *buf_, long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(fstatvfs1)(long res, long fd_, void *buf_, long flags_) {}
+PRE_SYSCALL(compat_30_fhstatvfs1)(void *fhp_, void *buf_, long flags_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_30_fhstatvfs1)
+(long res, void *fhp_, void *buf_, long flags_) {}
+PRE_SYSCALL(extattrctl)
+(void *path_, long cmd_, void *filename_, long attrnamespace_,
+  void *attrname_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattrctl)
+(long res, void *path_, long cmd_, void *filename_, long attrnamespace_,
+  void *attrname_) {}
+PRE_SYSCALL(extattr_set_file)
+(void *path_, long attrnamespace_, void *attrname_, void *data_, long nbytes_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_set_file)
+(long res, void *path_, long attrnamespace_, void *attrname_, void *data_,
+  long nbytes_) {}
+PRE_SYSCALL(extattr_get_file)
+(void *path_, long attrnamespace_, void *attrname_, void *data_, long nbytes_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_get_file)
+(long res, void *path_, long attrnamespace_, void *attrname_, void *data_,
+  long nbytes_) {}
+PRE_SYSCALL(extattr_delete_file)
+(void *path_, long attrnamespace_, void *attrname_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_delete_file)
+(long res, void *path_, long attrnamespace_, void *attrname_) {}
+PRE_SYSCALL(extattr_set_fd)
+(long fd_, long attrnamespace_, void *attrname_, void *data_, long nbytes_) {
+  /* TODO */
+}
+POST_SYSCALL(extattr_set_fd)
+(long res, long fd_, long attrnamespace_, void *attrname_, void *data_,
+  long nbytes_) {}
+PRE_SYSCALL(extattr_get_fd)
+(long fd_, long attrnamespace_, void *attrname_, void *data_, long nbytes_) {
+  /* TODO */
+}
+POST_SYSCALL(extattr_get_fd)
+(long res, long fd_, long attrnamespace_, void *attrname_, void *data_,
+  long nbytes_) {}
+PRE_SYSCALL(extattr_delete_fd)(long fd_, long attrnamespace_, void *attrname_) {
+  /* TODO */
+}
+POST_SYSCALL(extattr_delete_fd)
+(long res, long fd_, long attrnamespace_, void *attrname_) {}
+PRE_SYSCALL(extattr_set_link)
+(void *path_, long attrnamespace_, void *attrname_, void *data_, long nbytes_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_set_link)
+(long res, void *path_, long attrnamespace_, void *attrname_, void *data_,
+  long nbytes_) {}
+PRE_SYSCALL(extattr_get_link)
+(void *path_, long attrnamespace_, void *attrname_, void *data_, long nbytes_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_get_link)
+(long res, void *path_, long attrnamespace_, void *attrname_, void *data_,
+  long nbytes_) {}
+PRE_SYSCALL(extattr_delete_link)
+(void *path_, long attrnamespace_, void *attrname_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_delete_link)
+(long res, void *path_, long attrnamespace_, void *attrname_) {}
+PRE_SYSCALL(extattr_list_fd)
+(long fd_, long attrnamespace_, void *data_, long nbytes_) {
+  /* TODO */
+}
+POST_SYSCALL(extattr_list_fd)
+(long res, long fd_, long attrnamespace_, void *data_, long nbytes_) {}
+PRE_SYSCALL(extattr_list_file)
+(void *path_, long attrnamespace_, void *data_, long nbytes_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_list_file)
+(long res, void *path_, long attrnamespace_, void *data_, long nbytes_) {}
+PRE_SYSCALL(extattr_list_link)
+(void *path_, long attrnamespace_, void *data_, long nbytes_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(extattr_list_link)
+(long res, void *path_, long attrnamespace_, void *data_, long nbytes_) {}
+PRE_SYSCALL(compat_50_pselect)
+(long nd_, void *in_, void *ou_, void *ex_, void *ts_, void *mask_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_pselect)
+(long res, long nd_, void *in_, void *ou_, void *ex_, void *ts_, void *mask_) {}
+PRE_SYSCALL(compat_50_pollts)(void *fds_, long nfds_, void *ts_, void *mask_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_pollts)
+(long res, void *fds_, long nfds_, void *ts_, void *mask_) {}
+PRE_SYSCALL(setxattr)
+(void *path_, void *name_, void *value_, long size_, long flags_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(setxattr)
+(long res, void *path_, void *name_, void *value_, long size_, long flags_) {}
+PRE_SYSCALL(lsetxattr)
+(void *path_, void *name_, void *value_, long size_, long flags_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(lsetxattr)
+(long res, void *path_, void *name_, void *value_, long size_, long flags_) {}
+PRE_SYSCALL(fsetxattr)
+(long fd_, void *name_, void *value_, long size_, long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(fsetxattr)
+(long res, long fd_, void *name_, void *value_, long size_, long flags_) {}
+PRE_SYSCALL(getxattr)(void *path_, void *name_, void *value_, long size_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(getxattr)
+(long res, void *path_, void *name_, void *value_, long size_) {}
+PRE_SYSCALL(lgetxattr)(void *path_, void *name_, void *value_, long size_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(lgetxattr)
+(long res, void *path_, void *name_, void *value_, long size_) {}
+PRE_SYSCALL(fgetxattr)(long fd_, void *name_, void *value_, long size_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(fgetxattr)
+(long res, long fd_, void *name_, void *value_, long size_) {}
+PRE_SYSCALL(listxattr)(void *path_, void *list_, long size_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(listxattr)(long res, void *path_, void *list_, long size_) {}
+PRE_SYSCALL(llistxattr)(void *path_, void *list_, long size_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(llistxattr)(long res, void *path_, void *list_, long size_) {}
+PRE_SYSCALL(flistxattr)(long fd_, void *list_, long size_) { /* TODO */ }
+POST_SYSCALL(flistxattr)(long res, long fd_, void *list_, long size_) {}
+PRE_SYSCALL(removexattr)(void *path_, void *name_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(removexattr)(long res, void *path_, void *name_) {}
+PRE_SYSCALL(lremovexattr)(void *path_, void *name_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(lremovexattr)(long res, void *path_, void *name_) {}
+PRE_SYSCALL(fremovexattr)(long fd_, void *name_) { /* TODO */ }
+POST_SYSCALL(fremovexattr)(long res, long fd_, void *name_) {}
+PRE_SYSCALL(compat_50___stat30)(void *path_, void *ub_) { /* TODO */ }
+POST_SYSCALL(compat_50___stat30)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(compat_50___fstat30)(long fd_, void *sb_) { /* TODO */ }
+POST_SYSCALL(compat_50___fstat30)(long res, long fd_, void *sb_) {}
+PRE_SYSCALL(compat_50___lstat30)(void *path_, void *ub_) { /* TODO */ }
+POST_SYSCALL(compat_50___lstat30)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(__getdents30)(long fd_, void *buf_, long count_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__getdents30)(long res, long fd_, void *buf_, long count_) {}
+PRE_SYSCALL(posix_fadvise)(long) { /* Nothing to do */ }
+POST_SYSCALL(posix_fadvise)(long res, long) {}
+PRE_SYSCALL(compat_30___fhstat30)(void *fhp_, void *sb_) { /* TODO */ }
+POST_SYSCALL(compat_30___fhstat30)(long res, void *fhp_, void *sb_) {}
+PRE_SYSCALL(compat_50___ntp_gettime30)(void *ntvp_) { /* TODO */ }
+POST_SYSCALL(compat_50___ntp_gettime30)(long res, void *ntvp_) {}
+PRE_SYSCALL(__socket30)(long domain_, long type_, long protocol_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__socket30)(long res, long domain_, long type_, long protocol_) {}
+PRE_SYSCALL(__getfh30)(void *fname_, void *fhp_, void *fh_size_) {
+  const char *fname = (const char *)fname_;
+  if (fname) {
+    PRE_READ(fname, __sanitizer::internal_strlen(fname) + 1);
+  }
+}
+POST_SYSCALL(__getfh30)(long res, void *fname_, void *fhp_, void *fh_size_) {}
+PRE_SYSCALL(__fhopen40)(void *fhp_, long fh_size_, long flags_) {
+  if (fhp_) {
+    PRE_READ(fhp_, fh_size_);
+  }
+}
+POST_SYSCALL(__fhopen40)(long res, void *fhp_, long fh_size_, long flags_) {}
+PRE_SYSCALL(__fhstatvfs140)
+(void *fhp_, long fh_size_, void *buf_, long flags_) {
+  if (fhp_) {
+    PRE_READ(fhp_, fh_size_);
+  }
+}
+POST_SYSCALL(__fhstatvfs140)
+(long res, void *fhp_, long fh_size_, void *buf_, long flags_) {}
+PRE_SYSCALL(compat_50___fhstat40)(void *fhp_, long fh_size_, void *sb_) {
+  if (fhp_) {
+    PRE_READ(fhp_, fh_size_);
+  }
+}
+POST_SYSCALL(compat_50___fhstat40)
+(long res, void *fhp_, long fh_size_, void *sb_) {}
+PRE_SYSCALL(aio_cancel)(long fildes_, void *aiocbp_) {
+  if (aiocbp_) {
+    PRE_READ(aiocbp_, sizeof(struct __sanitizer_aiocb));
+  }
+}
+POST_SYSCALL(aio_cancel)(long res, long fildes_, void *aiocbp_) {}
+PRE_SYSCALL(aio_error)(void *aiocbp_) {
+  if (aiocbp_) {
+    PRE_READ(aiocbp_, sizeof(struct __sanitizer_aiocb));
+  }
+}
+POST_SYSCALL(aio_error)(long res, void *aiocbp_) {}
+PRE_SYSCALL(aio_fsync)(long op_, void *aiocbp_) {
+  if (aiocbp_) {
+    PRE_READ(aiocbp_, sizeof(struct __sanitizer_aiocb));
+  }
+}
+POST_SYSCALL(aio_fsync)(long res, long op_, void *aiocbp_) {}
+PRE_SYSCALL(aio_read)(void *aiocbp_) {
+  if (aiocbp_) {
+    PRE_READ(aiocbp_, sizeof(struct __sanitizer_aiocb));
+  }
+}
+POST_SYSCALL(aio_read)(long res, void *aiocbp_) {}
+PRE_SYSCALL(aio_return)(void *aiocbp_) {
+  if (aiocbp_) {
+    PRE_READ(aiocbp_, sizeof(struct __sanitizer_aiocb));
+  }
+}
+POST_SYSCALL(aio_return)(long res, void *aiocbp_) {}
+PRE_SYSCALL(compat_50_aio_suspend)(void *list_, long nent_, void *timeout_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_50_aio_suspend)
+(long res, void *list_, long nent_, void *timeout_) {}
+PRE_SYSCALL(aio_write)(void *aiocbp_) {
+  if (aiocbp_) {
+    PRE_READ(aiocbp_, sizeof(struct __sanitizer_aiocb));
+  }
+}
+POST_SYSCALL(aio_write)(long res, void *aiocbp_) {}
+PRE_SYSCALL(lio_listio)(long mode_, void *list_, long nent_, void *sig_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(lio_listio)
+(long res, long mode_, void *list_, long nent_, void *sig_) {}
+/* syscall 407 has been skipped */
+/* syscall 408 has been skipped */
+/* syscall 409 has been skipped */
+PRE_SYSCALL(__mount50)
+(void *type_, void *path_, long flags_, void *data_, long data_len_) {
+  const char *type = (const char *)type_;
+  const char *path = (const char *)path_;
+  if (type) {
+    PRE_READ(type, __sanitizer::internal_strlen(type) + 1);
+  }
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+  if (data_) {
+    PRE_READ(data_, data_len_);
+  }
+}
+POST_SYSCALL(__mount50)
+(long res, void *type_, void *path_, long flags_, void *data_, long data_len_) {
+}
+PRE_SYSCALL(mremap)
+(void *old_address_, long old_size_, void *new_address_, long new_size_,
+  long flags_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(mremap)
+(long res, void *old_address_, long old_size_, void *new_address_,
+  long new_size_, long flags_) {}
+PRE_SYSCALL(pset_create)(void *psid_) { /* Nothing to do */ }
+POST_SYSCALL(pset_create)(long res, void *psid_) {}
+PRE_SYSCALL(pset_destroy)(long psid_) { /* Nothing to do */ }
+POST_SYSCALL(pset_destroy)(long res, long psid_) {}
+PRE_SYSCALL(pset_assign)(long psid_, long cpuid_, void *opsid_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(pset_assign)(long res, long psid_, long cpuid_, void *opsid_) {}
+PRE_SYSCALL(_pset_bind)
+(long idtype_, long first_id_, long second_id_, long psid_, void *opsid_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(_pset_bind)
+(long res, long idtype_, long first_id_, long second_id_, long psid_,
+  void *opsid_) {}
+PRE_SYSCALL(__posix_fadvise50)
+(long fd_, long PAD_, long offset_, long len_, long advice_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__posix_fadvise50)
+(long res, long fd_, long PAD_, long offset_, long len_, long advice_) {}
+PRE_SYSCALL(__select50)(long nd_, void *in_, void *ou_, void *ex_, void *tv_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__select50)
+(long res, long nd_, void *in_, void *ou_, void *ex_, void *tv_) {}
+PRE_SYSCALL(__gettimeofday50)(void *tp_, void *tzp_) { /* Nothing to do */ }
+POST_SYSCALL(__gettimeofday50)(long res, void *tp_, void *tzp_) {}
+PRE_SYSCALL(__settimeofday50)(void *tv_, void *tzp_) {
+  if (tv_) {
+    PRE_READ(tv_, timeval_sz);
+  }
+  if (tzp_) {
+    PRE_READ(tzp_, struct_timezone_sz);
+  }
+}
+POST_SYSCALL(__settimeofday50)(long res, void *tv_, void *tzp_) {}
+PRE_SYSCALL(__utimes50)(void *path_, void *tptr_) {
+  struct __sanitizer_timespec **tptr = (struct __sanitizer_timespec **)tptr_;
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+  if (tptr) {
+    PRE_READ(tptr[0], struct_timespec_sz);
+    PRE_READ(tptr[1], struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__utimes50)(long res, void *path_, void *tptr_) {}
+PRE_SYSCALL(__adjtime50)(void *delta_, void *olddelta_) {
+  if (delta_) {
+    PRE_READ(delta_, timeval_sz);
+  }
+}
+POST_SYSCALL(__adjtime50)(long res, void *delta_, void *olddelta_) {}
+PRE_SYSCALL(__lfs_segwait50)(void *fsidp_, void *tv_) { /* TODO */ }
+POST_SYSCALL(__lfs_segwait50)(long res, void *fsidp_, void *tv_) {}
+PRE_SYSCALL(__futimes50)(long fd_, void *tptr_) {
+  struct __sanitizer_timespec **tptr = (struct __sanitizer_timespec **)tptr_;
+  if (tptr) {
+    PRE_READ(tptr[0], struct_timespec_sz);
+    PRE_READ(tptr[1], struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__futimes50)(long res, long fd_, void *tptr_) {}
+PRE_SYSCALL(__lutimes50)(void *path_, void *tptr_) {
+  struct __sanitizer_timespec **tptr = (struct __sanitizer_timespec **)tptr_;
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+  if (tptr) {
+    PRE_READ(tptr[0], struct_timespec_sz);
+    PRE_READ(tptr[1], struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__lutimes50)(long res, void *path_, void *tptr_) {}
+PRE_SYSCALL(__setitimer50)(long which_, void *itv_, void *oitv_) {
+  struct __sanitizer_itimerval *itv = (struct __sanitizer_itimerval *)itv_;
+  if (itv) {
+    PRE_READ(&itv->it_interval.tv_sec, sizeof(__sanitizer_time_t));
+    PRE_READ(&itv->it_interval.tv_usec, sizeof(__sanitizer_suseconds_t));
+    PRE_READ(&itv->it_value.tv_sec, sizeof(__sanitizer_time_t));
+    PRE_READ(&itv->it_value.tv_usec, sizeof(__sanitizer_suseconds_t));
+  }
+}
+POST_SYSCALL(__setitimer50)(long res, long which_, void *itv_, void *oitv_) {}
+PRE_SYSCALL(__getitimer50)(long which_, void *itv_) { /* Nothing to do */ }
+POST_SYSCALL(__getitimer50)(long res, long which_, void *itv_) {}
+PRE_SYSCALL(__clock_gettime50)(long clock_id_, void *tp_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__clock_gettime50)(long res, long clock_id_, void *tp_) {}
+PRE_SYSCALL(__clock_settime50)(long clock_id_, void *tp_) {
+  if (tp_) {
+    PRE_READ(tp_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__clock_settime50)(long res, long clock_id_, void *tp_) {}
+PRE_SYSCALL(__clock_getres50)(long clock_id_, void *tp_) { /* Nothing to do */ }
+POST_SYSCALL(__clock_getres50)(long res, long clock_id_, void *tp_) {}
+PRE_SYSCALL(__nanosleep50)(void *rqtp_, void *rmtp_) {
+  if (rqtp_) {
+    PRE_READ(rqtp_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__nanosleep50)(long res, void *rqtp_, void *rmtp_) {}
+PRE_SYSCALL(____sigtimedwait50)(void *set_, void *info_, void *timeout_) {
+  if (set_) {
+    PRE_READ(set_, sizeof(__sanitizer_sigset_t));
+  }
+  if (timeout_) {
+    PRE_READ(timeout_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(____sigtimedwait50)
+(long res, void *set_, void *info_, void *timeout_) {}
+PRE_SYSCALL(__mq_timedsend50)
+(long mqdes_, void *msg_ptr_, long msg_len_, long msg_prio_,
+  void *abs_timeout_) {
+  if (msg_ptr_) {
+    PRE_READ(msg_ptr_, msg_len_);
+  }
+  if (abs_timeout_) {
+    PRE_READ(abs_timeout_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__mq_timedsend50)
+(long res, long mqdes_, void *msg_ptr_, long msg_len_, long msg_prio_,
+  void *abs_timeout_) {}
+PRE_SYSCALL(__mq_timedreceive50)
+(long mqdes_, void *msg_ptr_, long msg_len_, void *msg_prio_,
+  void *abs_timeout_) {
+  if (msg_ptr_) {
+    PRE_READ(msg_ptr_, msg_len_);
+  }
+  if (abs_timeout_) {
+    PRE_READ(abs_timeout_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__mq_timedreceive50)
+(long res, long mqdes_, void *msg_ptr_, long msg_len_, void *msg_prio_,
+  void *abs_timeout_) {}
+PRE_SYSCALL(compat_60__lwp_park)
+(void *ts_, long unpark_, void *hint_, void *unparkhint_) {
+  /* TODO */
+}
+POST_SYSCALL(compat_60__lwp_park)
+(long res, void *ts_, long unpark_, void *hint_, void *unparkhint_) {}
+PRE_SYSCALL(__kevent50)
+(long fd_, void *changelist_, long nchanges_, void *eventlist_, long nevents_,
+  void *timeout_) {
+  if (changelist_) {
+    PRE_READ(changelist_, nchanges_ * struct_kevent_sz);
+  }
+  if (timeout_) {
+    PRE_READ(timeout_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__kevent50)
+(long res, long fd_, void *changelist_, long nchanges_, void *eventlist_,
+  long nevents_, void *timeout_) {}
+PRE_SYSCALL(__pselect50)
+(long nd_, void *in_, void *ou_, void *ex_, void *ts_, void *mask_) {
+  if (ts_) {
+    PRE_READ(ts_, struct_timespec_sz);
+  }
+  if (mask_) {
+    PRE_READ(mask_, sizeof(struct __sanitizer_sigset_t));
+  }
+}
+POST_SYSCALL(__pselect50)
+(long res, long nd_, void *in_, void *ou_, void *ex_, void *ts_, void *mask_) {}
+PRE_SYSCALL(__pollts50)(void *fds_, long nfds_, void *ts_, void *mask_) {
+  if (ts_) {
+    PRE_READ(ts_, struct_timespec_sz);
+  }
+  if (mask_) {
+    PRE_READ(mask_, sizeof(struct __sanitizer_sigset_t));
+  }
+}
+POST_SYSCALL(__pollts50)
+(long res, void *fds_, long nfds_, void *ts_, void *mask_) {}
+PRE_SYSCALL(__aio_suspend50)(void *list_, long nent_, void *timeout_) {
+  int i;
+  const struct aiocb *const *list = (const struct aiocb *const *)list_;
+  if (list) {
+    for (i = 0; i < nent_; i++) {
+      if (list[i]) {
+        PRE_READ(list[i], sizeof(struct __sanitizer_aiocb));
+      }
+    }
+  }
+  if (timeout_) {
+    PRE_READ(timeout_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(__aio_suspend50)
+(long res, void *list_, long nent_, void *timeout_) {}
+PRE_SYSCALL(__stat50)(void *path_, void *ub_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(__stat50)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(__fstat50)(long fd_, void *sb_) { /* Nothing to do */ }
+POST_SYSCALL(__fstat50)(long res, long fd_, void *sb_) {}
+PRE_SYSCALL(__lstat50)(void *path_, void *ub_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(__lstat50)(long res, void *path_, void *ub_) {}
+PRE_SYSCALL(____semctl50)(long semid_, long semnum_, long cmd_, void *arg_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(____semctl50)
+(long res, long semid_, long semnum_, long cmd_, void *arg_) {}
+PRE_SYSCALL(__shmctl50)(long shmid_, long cmd_, void *buf_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__shmctl50)(long res, long shmid_, long cmd_, void *buf_) {}
+PRE_SYSCALL(__msgctl50)(long msqid_, long cmd_, void *buf_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__msgctl50)(long res, long msqid_, long cmd_, void *buf_) {}
+PRE_SYSCALL(__getrusage50)(long who_, void *rusage_) { /* Nothing to do */ }
+POST_SYSCALL(__getrusage50)(long res, long who_, void *rusage_) {}
+PRE_SYSCALL(__timer_settime50)
+(long timerid_, long flags_, void *value_, void *ovalue_) {
+  struct __sanitizer_itimerval *value = (struct __sanitizer_itimerval *)value_;
+  if (value) {
+    PRE_READ(&value->it_interval.tv_sec, sizeof(__sanitizer_time_t));
+    PRE_READ(&value->it_interval.tv_usec, sizeof(__sanitizer_suseconds_t));
+    PRE_READ(&value->it_value.tv_sec, sizeof(__sanitizer_time_t));
+    PRE_READ(&value->it_value.tv_usec, sizeof(__sanitizer_suseconds_t));
+  }
+}
+POST_SYSCALL(__timer_settime50)
+(long res, long timerid_, long flags_, void *value_, void *ovalue_) {}
+PRE_SYSCALL(__timer_gettime50)(long timerid_, void *value_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__timer_gettime50)(long res, long timerid_, void *value_) {}
+#if defined(NTP) || !defined(_KERNEL_OPT)
+PRE_SYSCALL(__ntp_gettime50)(void *ntvp_) { /* Nothing to do */ }
+POST_SYSCALL(__ntp_gettime50)(long res, void *ntvp_) {}
+#else
+/* syscall 448 has been skipped */
+#endif
+PRE_SYSCALL(__wait450)(long pid_, void *status_, long options_, void *rusage_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(__wait450)
+(long res, long pid_, void *status_, long options_, void *rusage_) {}
+PRE_SYSCALL(__mknod50)(void *path_, long mode_, long dev_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(__mknod50)(long res, void *path_, long mode_, long dev_) {}
+PRE_SYSCALL(__fhstat50)(void *fhp_, long fh_size_, void *sb_) {
+  if (fhp_) {
+    PRE_READ(fhp_, fh_size_);
+  }
+}
+POST_SYSCALL(__fhstat50)(long res, void *fhp_, long fh_size_, void *sb_) {}
+/* syscall 452 has been skipped */
+PRE_SYSCALL(pipe2)(void *fildes_, long flags_) { /* Nothing to do */ }
+POST_SYSCALL(pipe2)(long res, void *fildes_, long flags_) {}
+PRE_SYSCALL(dup3)(long from_, long to_, long flags_) { /* Nothing to do */ }
+POST_SYSCALL(dup3)(long res, long from_, long to_, long flags_) {}
+PRE_SYSCALL(kqueue1)(long flags_) { /* Nothing to do */ }
+POST_SYSCALL(kqueue1)(long res, long flags_) {}
+PRE_SYSCALL(paccept)
+(long s_, void *name_, void *anamelen_, void *mask_, long flags_) {
+  if (mask_) {
+    PRE_READ(mask_, sizeof(__sanitizer_sigset_t));
+  }
+}
+POST_SYSCALL(paccept)
+(long res, long s_, void *name_, void *anamelen_, void *mask_, long flags_) {}
+PRE_SYSCALL(linkat)
+(long fd1_, void *name1_, long fd2_, void *name2_, long flags_) {
+  const char *name1 = (const char *)name1_;
+  const char *name2 = (const char *)name2_;
+  if (name1) {
+    PRE_READ(name1, __sanitizer::internal_strlen(name1) + 1);
+  }
+  if (name2) {
+    PRE_READ(name2, __sanitizer::internal_strlen(name2) + 1);
+  }
+}
+POST_SYSCALL(linkat)
+(long res, long fd1_, void *name1_, long fd2_, void *name2_, long flags_) {}
+PRE_SYSCALL(renameat)(long fromfd_, void *from_, long tofd_, void *to_) {
+  const char *from = (const char *)from_;
+  const char *to = (const char *)to_;
+  if (from) {
+    PRE_READ(from, __sanitizer::internal_strlen(from) + 1);
+  }
+  if (to) {
+    PRE_READ(to, __sanitizer::internal_strlen(to) + 1);
+  }
+}
+POST_SYSCALL(renameat)
+(long res, long fromfd_, void *from_, long tofd_, void *to_) {}
+PRE_SYSCALL(mkfifoat)(long fd_, void *path_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(mkfifoat)(long res, long fd_, void *path_, long mode_) {}
+PRE_SYSCALL(mknodat)(long fd_, void *path_, long mode_, long PAD_, long dev_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(mknodat)
+(long res, long fd_, void *path_, long mode_, long PAD_, long dev_) {}
+PRE_SYSCALL(mkdirat)(long fd_, void *path_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(mkdirat)(long res, long fd_, void *path_, long mode_) {}
+PRE_SYSCALL(faccessat)(long fd_, void *path_, long amode_, long flag_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(faccessat)
+(long res, long fd_, void *path_, long amode_, long flag_) {}
+PRE_SYSCALL(fchmodat)(long fd_, void *path_, long mode_, long flag_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(fchmodat)
+(long res, long fd_, void *path_, long mode_, long flag_) {}
+PRE_SYSCALL(fchownat)
+(long fd_, void *path_, long owner_, long group_, long flag_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(fchownat)
+(long res, long fd_, void *path_, long owner_, long group_, long flag_) {}
+PRE_SYSCALL(fexecve)(long fd_, void *argp_, void *envp_) {
+  char **argp = (char **)argp_;
+  char **envp = (char **)envp_;
+  if (argp && argp[0]) {
+    char *a = argp[0];
+    while (a++) {
+      PRE_READ(a, __sanitizer::internal_strlen(a) + 1);
+    }
+  }
+  if (envp && envp[0]) {
+    char *e = envp[0];
+    while (e++) {
+      PRE_READ(e, __sanitizer::internal_strlen(e) + 1);
+    }
+  }
+}
+POST_SYSCALL(fexecve)(long res, long fd_, void *argp_, void *envp_) {}
+PRE_SYSCALL(fstatat)(long fd_, void *path_, void *buf_, long flag_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(fstatat)
+(long res, long fd_, void *path_, void *buf_, long flag_) {}
+PRE_SYSCALL(utimensat)(long fd_, void *path_, void *tptr_, long flag_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+  if (tptr_) {
+    PRE_READ(tptr_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(utimensat)
+(long res, long fd_, void *path_, void *tptr_, long flag_) {}
+PRE_SYSCALL(openat)(long fd_, void *path_, long oflags_, long mode_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(openat)
+(long res, long fd_, void *path_, long oflags_, long mode_) {}
+PRE_SYSCALL(readlinkat)(long fd_, void *path_, void *buf_, long bufsize_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(readlinkat)
+(long res, long fd_, void *path_, void *buf_, long bufsize_) {}
+PRE_SYSCALL(symlinkat)(void *path1_, long fd_, void *path2_) {
+  const char *path1 = (const char *)path1_;
+  const char *path2 = (const char *)path2_;
+  if (path1) {
+    PRE_READ(path1, __sanitizer::internal_strlen(path1) + 1);
+  }
+  if (path2) {
+    PRE_READ(path2, __sanitizer::internal_strlen(path2) + 1);
+  }
+}
+POST_SYSCALL(symlinkat)(long res, void *path1_, long fd_, void *path2_) {}
+PRE_SYSCALL(unlinkat)(long fd_, void *path_, long flag_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(unlinkat)(long res, long fd_, void *path_, long flag_) {}
+PRE_SYSCALL(futimens)(long fd_, void *tptr_) {
+  struct __sanitizer_timespec **tptr = (struct __sanitizer_timespec **)tptr_;
+  if (tptr) {
+    PRE_READ(tptr[0], struct_timespec_sz);
+    PRE_READ(tptr[1], struct_timespec_sz);
+  }
+}
+POST_SYSCALL(futimens)(long res, long fd_, void *tptr_) {}
+PRE_SYSCALL(__quotactl)(void *path_, void *args_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(__quotactl)(long res, void *path_, void *args_) {}
+PRE_SYSCALL(posix_spawn)
+(void *pid_, void *path_, void *file_actions_, void *attrp_, void *argv_,
+  void *envp_) {
+  const char *path = (const char *)path_;
+  if (path) {
+    PRE_READ(path, __sanitizer::internal_strlen(path) + 1);
+  }
+}
+POST_SYSCALL(posix_spawn)
+(long res, void *pid_, void *path_, void *file_actions_, void *attrp_,
+  void *argv_, void *envp_) {}
+PRE_SYSCALL(recvmmsg)
+(long s_, void *mmsg_, long vlen_, long flags_, void *timeout_) {
+  if (timeout_) {
+    PRE_READ(timeout_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(recvmmsg)
+(long res, long s_, void *mmsg_, long vlen_, long flags_, void *timeout_) {}
+PRE_SYSCALL(sendmmsg)(long s_, void *mmsg_, long vlen_, long flags_) {
+  struct __sanitizer_mmsghdr *mmsg = (struct __sanitizer_mmsghdr *)mmsg_;
+  unsigned int vlen = (vlen_ > 1024 ? 1024 : vlen_);
+  if (mmsg) {
+    PRE_READ(mmsg, sizeof(struct __sanitizer_mmsghdr) * vlen);
+  }
+}
+POST_SYSCALL(sendmmsg)
+(long res, long s_, void *mmsg_, long vlen_, long flags_) {}
+PRE_SYSCALL(clock_nanosleep)
+(long clock_id_, long flags_, void *rqtp_, void *rmtp_) {
+  if (rqtp_) {
+    PRE_READ(rqtp_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(clock_nanosleep)
+(long res, long clock_id_, long flags_, void *rqtp_, void *rmtp_) {}
+PRE_SYSCALL(___lwp_park60)
+(long clock_id_, long flags_, void *ts_, long unpark_, void *hint_,
+  void *unparkhint_) {
+  if (ts_) {
+    PRE_READ(ts_, struct_timespec_sz);
+  }
+}
+POST_SYSCALL(___lwp_park60)
+(long res, long clock_id_, long flags_, void *ts_, long unpark_, void *hint_,
+  void *unparkhint_) {}
+PRE_SYSCALL(posix_fallocate)(long fd_, long PAD_, long pos_, long len_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(posix_fallocate)
+(long res, long fd_, long PAD_, long pos_, long len_) {}
+PRE_SYSCALL(fdiscard)(long fd_, long PAD_, long pos_, long len_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(fdiscard)(long res, long fd_, long PAD_, long pos_, long len_) {}
+PRE_SYSCALL(wait6)
+(long idtype_, long id_, void *status_, long options_, void *wru_,
+  void *info_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(wait6)
+(long res, long idtype_, long id_, void *status_, long options_, void *wru_,
+  void *info_) {}
+PRE_SYSCALL(clock_getcpuclockid2)(long idtype_, long id_, void *clock_id_) {
+  /* Nothing to do */
+}
+POST_SYSCALL(clock_getcpuclockid2)
+(long res, long idtype_, long id_, void *clock_id_) {}
+#undef SYS_MAXSYSARGS
+} // extern "C"
+
+#undef PRE_SYSCALL
+#undef PRE_READ
+#undef PRE_WRITE
+#undef POST_SYSCALL
+#undef POST_READ
+#undef POST_WRITE
+
+#endif // SANITIZER_NETBSD
