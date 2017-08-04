$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -14,7 +14,7 @@
 
 #include "sanitizer_platform.h"
 
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "sanitizer_common.h"
 #include "sanitizer_flags.h"
@@ -27,10 +27,14 @@
 #include "sanitizer_stacktrace.h"
 #include "sanitizer_symbolizer.h"
 
-#if !SANITIZER_FREEBSD
+#if SANITIZER_LINUX
 #include <asm/param.h>
 #endif
 
+#if SANITIZER_NETBSD
+#include <lwp.h>
+#endif
+
 // For mips64, syscall(__NR_stat) fills the buffer in the 'struct kernel_stat'
 // format. Struct kernel_stat is defined as 'struct stat' in asm/stat.h. To
 // access stat from asm/stat.h, without conflicting with definition in
@@ -79,6 +83,12 @@ extern "C" {
 extern char **environ;  // provided by crt1
 #endif  // SANITIZER_FREEBSD
 
+#if SANITIZER_NETBSD
+#include <limits.h>  // For NAME_MAX
+#include <sys/sysctl.h>
+extern char **environ;  // provided by crt1
+#endif                  // SANITIZER_NETBSD
+
 #if !SANITIZER_ANDROID
 #include <sys/signal.h>
 #endif
@@ -139,7 +149,10 @@ namespace __sanitizer {
 #if !SANITIZER_S390
 uptr internal_mmap(void *addr, uptr length, int prot, int flags, int fd,
                    OFF_T offset) {
-#if SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(mmap), addr, length, prot, flags, fd,
+                              (long)0, offset);
+#elif SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS
   return internal_syscall(SYSCALL(mmap), (uptr)addr, length, prot, flags, fd,
                           offset);
 #else
@@ -182,26 +195,38 @@ uptr internal_open(const char *filename,
 
 uptr internal_read(fd_t fd, void *buf, uptr count) {
   sptr res;
+#if SANITIZER_NETBSD
+  HANDLE_EINTR(res, internal_syscall_ptr(SYSCALL(read), fd, buf, count));
+#else
   HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(read), fd, (uptr)buf,
                count));
+#endif
   return res;
 }
 
 uptr internal_write(fd_t fd, const void *buf, uptr count) {
   sptr res;
+#if SANITIZER_NETBSD
+  HANDLE_EINTR(res, internal_syscall_ptr(SYSCALL(write), fd, buf, count));
+#else
   HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(write), fd, (uptr)buf,
                count));
+#endif
   return res;
 }
 
 uptr internal_ftruncate(fd_t fd, uptr size) {
   sptr res;
+#if SANITIZER_NETBSD
+  HANDLE_EINTR(res, internal_syscall(SYSCALL(ftruncate), fd, 0, (s64)size));
+#else
   HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(ftruncate), fd,
                (OFF_T)size));
+#endif
   return res;
 }
 
-#if !SANITIZER_LINUX_USES_64BIT_SYSCALLS && !SANITIZER_FREEBSD
+#if !SANITIZER_LINUX_USES_64BIT_SYSCALLS && SANITIZER_LINUX
 static void stat64_to_stat(struct stat64 *in, struct stat *out) {
   internal_memset(out, 0, sizeof(*out));
   out->st_dev = in->st_dev;
@@ -240,7 +265,7 @@ static void kernel_stat_to_stat(struct k
 #endif
 
 uptr internal_stat(const char *path, void *buf) {
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
   return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, 0);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
@@ -265,7 +290,9 @@ uptr internal_stat(const char *path, voi
 }
 
 uptr internal_lstat(const char *path, void *buf) {
-#if SANITIZER_FREEBSD
+#if SANITIZER_NETBSD
+  return internal_syscall(SYSCALL(lstat), path, buf);
+#elif SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, AT_SYMLINK_NOFOLLOW);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
@@ -290,7 +317,7 @@ uptr internal_lstat(const char *path, vo
 }
 
 uptr internal_fstat(fd_t fd, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS
+#if SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS || SANITIZER_NETBSD
 # if SANITIZER_MIPS64
   // For mips64, fstat syscall fills buffer in the format of kernel_stat
   struct kernel_stat kbuf;
@@ -324,7 +351,9 @@ uptr internal_dup2(int oldfd, int newfd)
 }
 
 uptr internal_readlink(const char *path, char *buf, uptr bufsize) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(readlink), path, buf, bufsize);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(readlinkat), AT_FDCWD,
                           (uptr)path, (uptr)buf, bufsize);
 #else
@@ -354,7 +383,7 @@ uptr internal_sched_yield() {
 }
 
 void internal__exit(int exitcode) {
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
   internal_syscall(SYSCALL(exit), exitcode);
 #else
   internal_syscall(SYSCALL(exit_group), exitcode);
@@ -393,19 +422,25 @@ bool FileExists(const char *filename) {
 tid_t GetTid() {
 #if SANITIZER_FREEBSD
   return (uptr)pthread_self();
+#elif SANITIZER_NETBSD
+  return _lwp_self();
 #else
   return internal_syscall(SYSCALL(gettid));
 #endif
 }
 
 u64 NanoTime() {
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
   timeval tv;
 #else
   kernel_timeval tv;
 #endif
   internal_memset(&tv, 0, sizeof(tv));
+#if SANITIZER_NETBSD
+  internal_syscall_ptr(SYSCALL(gettimeofday), &tv, NULL);
+#else
   internal_syscall(SYSCALL(gettimeofday), (uptr)&tv, 0);
+#endif
   return (u64)tv.tv_sec * 1000*1000*1000 + tv.tv_usec * 1000;
 }
 
@@ -413,7 +448,7 @@ u64 NanoTime() {
 // 'environ' array (on FreeBSD) and does not use libc. This function should be
 // called first inside __asan_init.
 const char *GetEnv(const char *name) {
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
   if (::environ != 0) {
     uptr NameLen = internal_strlen(name);
     for (char **Env = ::environ; *Env != 0; Env++) {
@@ -547,6 +582,8 @@ void BlockingMutex::Lock() {
   while (atomic_exchange(m, MtxSleeping, memory_order_acquire) != MtxUnlocked) {
 #if SANITIZER_FREEBSD
     _umtx_op(m, UMTX_OP_WAIT_UINT, MtxSleeping, 0, 0);
+#elif SANITIZER_NETBSD
+    sched_yield(); /* No userspace futex-like synchromization */
 #else
     internal_syscall(SYSCALL(futex), (uptr)m, FUTEX_WAIT, MtxSleeping, 0, 0, 0);
 #endif
@@ -560,6 +597,8 @@ void BlockingMutex::Unlock() {
   if (v == MtxSleeping) {
 #if SANITIZER_FREEBSD
     _umtx_op(m, UMTX_OP_WAKE, 1, 0, 0);
+#elif SANITIZER_NETBSD
+                   /* No userspace futex-like synchromization */
 #else
     internal_syscall(SYSCALL(futex), (uptr)m, FUTEX_WAKE, 1, 0, 0, 0);
 #endif
@@ -575,6 +614,17 @@ void BlockingMutex::CheckLocked() {
 // The actual size of this structure is specified by d_reclen.
 // Note that getdents64 uses a different structure format. We only provide the
 // 32-bit syscall here.
+#if SANITIZER_NETBSD
+// struct dirent is different for Linux and us. At this moment, we use only
+// d_fileno (Linux call this d_ino), d_reclen, and d_name.
+struct linux_dirent {
+  u64 d_ino;  // d_fileno
+  u16 d_reclen;
+  u16 d_namlen;  // not used
+  u8 d_type;     // not used
+  char d_name[NAME_MAX + 1];
+};
+#else
 struct linux_dirent {
 #if SANITIZER_X32 || defined(__aarch64__)
   u64 d_ino;
@@ -589,16 +639,34 @@ struct linux_dirent {
 #endif
   char               d_name[256];
 };
+#endif
 
 // Syscall wrappers.
 uptr internal_ptrace(int request, int pid, void *addr, void *data) {
+#if SANITIZER_NETBSD
+  // XXX We need additional work for ptrace:
+  //   - for request, we use PT_FOO whereas Linux uses PTRACE_FOO
+  //   - data is int for us, but void * for Linux
+  //   - Linux sometimes uses data in the case where we use addr instead
+  // At this moment, this function is used only within
+  // "#if SANITIZER_LINUX && defined(__x86_64__)" block in
+  // sanitizer_stoptheworld_linux_libcdep.cc.
+  return internal_syscall_ptr(SYSCALL(ptrace), request, pid, (uptr)addr,
+                              (uptr)data);
+#else
   return internal_syscall(SYSCALL(ptrace), request, pid, (uptr)addr,
                           (uptr)data);
+#endif
 }
 
 uptr internal_waitpid(int pid, int *status, int options) {
+#if SANITIZER_NETBSD
+  return internal_syscall(SYSCALL(wait4), pid, status, options,
+                          NULL /* rusage */);
+#else
   return internal_syscall(SYSCALL(wait4), pid, (uptr)status, options,
                           0 /* rusage */);
+#endif
 }
 
 uptr internal_getpid() {
@@ -610,7 +678,9 @@ uptr internal_getppid() {
 }
 
 uptr internal_getdents(fd_t fd, struct linux_dirent *dirp, unsigned int count) {
-#if SANITIZER_FREEBSD
+#if SANITIZER_NETBSD
+  return internal_syscall(SYSCALL(getdents), fd, dirp, (uptr)count);
+#elif SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(getdirentries), fd, (uptr)dirp, count, NULL);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(getdents64), fd, (uptr)dirp, count);
@@ -620,7 +690,11 @@ uptr internal_getdents(fd_t fd, struct l
 }
 
 uptr internal_lseek(fd_t fd, OFF_T offset, int whence) {
+#if SANITIZER_NETBSD
+  return internal_syscall64(SYSCALL(lseek), fd, 0, offset, whence);
+#else
   return internal_syscall(SYSCALL(lseek), fd, offset, whence);
+#endif
 }
 
 #if SANITIZER_LINUX
@@ -711,7 +785,7 @@ int internal_sigaction_syscall(int signu
 
 uptr internal_sigprocmask(int how, __sanitizer_sigset_t *set,
     __sanitizer_sigset_t *oldset) {
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
   return internal_syscall(SYSCALL(sigprocmask), how, set, oldset);
 #else
   __sanitizer_kernel_sigset_t *k_set = (__sanitizer_kernel_sigset_t *)set;
@@ -856,7 +930,9 @@ static uptr GetKernelAreaSize() {
 #endif  // SANITIZER_WORDSIZE == 32
 
 uptr GetMaxVirtualAddress() {
-#if SANITIZER_WORDSIZE == 64
+#if SANITIZER_NETBSD && defined(__x86_64__)
+  return 0x7f7ffffff000ULL;  // (0x00007f8000000000 - PAGE_SIZE)
+#elif SANITIZER_WORDSIZE == 64
 # if defined(__powerpc64__) || defined(__aarch64__)
   // On PowerPC64 we have two different address space layouts: 44- and 46-bit.
   // We somehow need to figure out which one we are using now and choose
@@ -900,8 +976,12 @@ uptr GetPageSize() {
 }
 
 uptr ReadBinaryName(/*out*/char *buf, uptr buf_len) {
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
 #if SANITIZER_FREEBSD
-  const int Mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+  const int Mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+#else
+  const int Mib[4] = {CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME};
+#endif
   const char *default_module_name = "kern.proc.pathname";
   size_t Size = buf_len;
   bool IsErr = (sysctl(Mib, ARRAY_SIZE(Mib), buf, &Size, NULL, 0) != 0);
@@ -1545,6 +1625,8 @@ SignalContext::WriteFlag SignalContext::
   static const uptr PF_WRITE = 1U << 1;
 #if SANITIZER_FREEBSD
   uptr err = ucontext->uc_mcontext.mc_err;
+#elif SANITIZER_NETBSD
+  uptr err = ucontext->uc_mcontext.__gregs[_REG_ERR];
 #else
   uptr err = ucontext->uc_mcontext.gregs[REG_ERR];
 #endif
@@ -1591,6 +1673,11 @@ void GetPcSpBp(void *context, uptr *pc, 
   *pc = ucontext->uc_mcontext.mc_rip;
   *bp = ucontext->uc_mcontext.mc_rbp;
   *sp = ucontext->uc_mcontext.mc_rsp;
+#elif SANITIZER_NETBSD
+  ucontext_t *ucontext = (ucontext_t *)context;
+  *pc = ucontext->uc_mcontext.__gregs[_REG_RIP];
+  *bp = ucontext->uc_mcontext.__gregs[_REG_RBP];
+  *sp = ucontext->uc_mcontext.__gregs[_REG_RSP];
 # else
   ucontext_t *ucontext = (ucontext_t*)context;
   *pc = ucontext->uc_mcontext.gregs[REG_RIP];
@@ -1603,6 +1690,11 @@ void GetPcSpBp(void *context, uptr *pc, 
   *pc = ucontext->uc_mcontext.mc_eip;
   *bp = ucontext->uc_mcontext.mc_ebp;
   *sp = ucontext->uc_mcontext.mc_esp;
+#elif SANITIZER_NETBSD
+  ucontext_t *ucontext = (ucontext_t *)context;
+  *pc = ucontext->uc_mcontext.__gregs[_REG_EIP];
+  *bp = ucontext->uc_mcontext.__gregs[_REG_EBP];
+  *sp = ucontext->uc_mcontext.__gregs[_REG_ESP];
 # else
   ucontext_t *ucontext = (ucontext_t*)context;
   *pc = ucontext->uc_mcontext.gregs[REG_EIP];
@@ -1704,4 +1796,4 @@ bool GetRandom(void *buffer, uptr length
 
 } // namespace __sanitizer
 
-#endif // SANITIZER_FREEBSD || SANITIZER_LINUX
+#endif  // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
