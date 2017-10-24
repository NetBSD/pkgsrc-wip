$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2017-10-20 11:21:05.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -87,7 +87,9 @@ extern char **environ;  // provided by c
 #include <limits.h>  // For NAME_MAX
 #include <sys/sysctl.h>
 extern char **environ;  // provided by crt1
-#endif                  // SANITIZER_NETBSD
+#include <sys/exec.h>
+extern struct ps_strings *__ps_strings;
+#endif  // SANITIZER_NETBSD
 
 #if !SANITIZER_ANDROID
 #include <sys/signal.h>
@@ -174,11 +176,11 @@ uptr internal_mmap(void *addr, uptr leng
 #endif // !SANITIZER_S390
 
 uptr internal_munmap(void *addr, uptr length) {
-  return internal_syscall(SYSCALL(munmap), (uptr)addr, length);
+  return internal_syscall_ptr(SYSCALL(munmap), (uptr)addr, length);
 }
 
 int internal_mprotect(void *addr, uptr length, int prot) {
-  return internal_syscall(SYSCALL(mprotect), (uptr)addr, length, prot);
+  return internal_syscall_ptr(SYSCALL(mprotect), (uptr)addr, length, prot);
 }
 
 uptr internal_close(fd_t fd) {
@@ -189,7 +191,7 @@ uptr internal_open(const char *filename,
 #if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(openat), AT_FDCWD, (uptr)filename, flags);
 #else
-  return internal_syscall(SYSCALL(open), (uptr)filename, flags);
+  return internal_syscall_ptr(SYSCALL(open), (uptr)filename, flags);
 #endif
 }
 
@@ -198,36 +200,28 @@ uptr internal_open(const char *filename,
   return internal_syscall(SYSCALL(openat), AT_FDCWD, (uptr)filename, flags,
                           mode);
 #else
-  return internal_syscall(SYSCALL(open), (uptr)filename, flags, mode);
+  return internal_syscall_ptr(SYSCALL(open), (uptr)filename, flags, mode);
 #endif
 }
 
 uptr internal_read(fd_t fd, void *buf, uptr count) {
   sptr res;
-#if SANITIZER_NETBSD
-  HANDLE_EINTR(res, internal_syscall_ptr(SYSCALL(read), fd, buf, count));
-#else
-  HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(read), fd, (uptr)buf,
+  HANDLE_EINTR(res, (sptr)internal_syscall_ptr(SYSCALL(read), fd, (uptr)buf,
                count));
-#endif
   return res;
 }
 
 uptr internal_write(fd_t fd, const void *buf, uptr count) {
   sptr res;
-#if SANITIZER_NETBSD
-  HANDLE_EINTR(res, internal_syscall_ptr(SYSCALL(write), fd, buf, count));
-#else
-  HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(write), fd, (uptr)buf,
+  HANDLE_EINTR(res, (sptr)internal_syscall_ptr(SYSCALL(write), fd, (uptr)buf,
                count));
-#endif
   return res;
 }
 
 uptr internal_ftruncate(fd_t fd, uptr size) {
   sptr res;
 #if SANITIZER_NETBSD
-  HANDLE_EINTR(res, internal_syscall(SYSCALL(ftruncate), fd, 0, (s64)size));
+  HANDLE_EINTR(res, internal_syscall64(SYSCALL(ftruncate), fd, 0, (s64)size));
 #else
   HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(ftruncate), fd,
                (OFF_T)size));
@@ -304,7 +298,7 @@ static void kernel_stat_to_stat(struct k
 
 uptr internal_stat(const char *path, void *buf) {
 #if SANITIZER_FREEBSD || SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
+  return internal_syscall_ptr(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, 0);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(newfstatat), AT_FDCWD, (uptr)path,
@@ -329,7 +323,7 @@ uptr internal_stat(const char *path, voi
 
 uptr internal_lstat(const char *path, void *buf) {
 #if SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(lstat), path, buf);
+  return internal_syscall_ptr(SYSCALL(lstat), path, buf);
 #elif SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, AT_SYMLINK_NOFOLLOW);
@@ -355,15 +349,15 @@ uptr internal_lstat(const char *path, vo
 }
 
 uptr internal_fstat(fd_t fd, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS || SANITIZER_NETBSD
-# if SANITIZER_MIPS64
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS
+# if SANITIZER_MIPS64 && !SANITIZER_NETBSD
   // For mips64, fstat syscall fills buffer in the format of kernel_stat
   struct kernel_stat kbuf;
   int res = internal_syscall(SYSCALL(fstat), fd, &kbuf);
   kernel_stat_to_stat(&kbuf, (struct stat *)buf);
   return res;
 # else
-  return internal_syscall(SYSCALL(fstat), fd, (uptr)buf);
+  return internal_syscall_ptr(SYSCALL(fstat), fd, (uptr)buf);
 # endif
 #else
   struct stat64 buf64;
@@ -389,13 +383,11 @@ uptr internal_dup2(int oldfd, int newfd)
 }
 
 uptr internal_readlink(const char *path, char *buf, uptr bufsize) {
-#if SANITIZER_NETBSD
-  return internal_syscall_ptr(SYSCALL(readlink), path, buf, bufsize);
-#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(readlinkat), AT_FDCWD,
                           (uptr)path, (uptr)buf, bufsize);
 #else
-  return internal_syscall(SYSCALL(readlink), (uptr)path, (uptr)buf, bufsize);
+  return internal_syscall_ptr(SYSCALL(readlink), path, buf, bufsize);
 #endif
 }
 
@@ -403,7 +395,7 @@ uptr internal_unlink(const char *path) {
 #if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(unlinkat), AT_FDCWD, (uptr)path, 0);
 #else
-  return internal_syscall(SYSCALL(unlink), (uptr)path);
+  return internal_syscall_ptr(SYSCALL(unlink), (uptr)path);
 #endif
 }
 
@@ -412,7 +404,7 @@ uptr internal_rename(const char *oldpath
   return internal_syscall(SYSCALL(renameat), AT_FDCWD, (uptr)oldpath, AT_FDCWD,
                           (uptr)newpath);
 #else
-  return internal_syscall(SYSCALL(rename), (uptr)oldpath, (uptr)newpath);
+  return internal_syscall_ptr(SYSCALL(rename), (uptr)oldpath, (uptr)newpath);
 #endif
 }
 
@@ -433,14 +425,14 @@ unsigned int internal_sleep(unsigned int
   struct timespec ts;
   ts.tv_sec = 1;
   ts.tv_nsec = 0;
-  int res = internal_syscall(SYSCALL(nanosleep), &ts, &ts);
+  int res = internal_syscall_ptr(SYSCALL(nanosleep), &ts, &ts);
   if (res) return ts.tv_sec;
   return 0;
 }
 
 uptr internal_execve(const char *filename, char *const argv[],
                      char *const envp[]) {
-  return internal_syscall(SYSCALL(execve), (uptr)filename, (uptr)argv,
+  return internal_syscall_ptr(SYSCALL(execve), (uptr)filename, (uptr)argv,
                           (uptr)envp);
 }
 
@@ -474,11 +466,7 @@ u64 NanoTime() {
   kernel_timeval tv;
 #endif
   internal_memset(&tv, 0, sizeof(tv));
-#if SANITIZER_NETBSD
-  internal_syscall_ptr(SYSCALL(gettimeofday), &tv, NULL);
-#else
-  internal_syscall(SYSCALL(gettimeofday), (uptr)&tv, 0);
-#endif
+  internal_syscall_ptr(SYSCALL(gettimeofday), &tv, 0);
   return (u64)tv.tv_sec * 1000*1000*1000 + tv.tv_usec * 1000;
 }
 
@@ -524,13 +512,13 @@ const char *GetEnv(const char *name) {
 #endif
 }
 
-#if !SANITIZER_FREEBSD
+#if !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 extern "C" {
   SANITIZER_WEAK_ATTRIBUTE extern void *__libc_stack_end;
 }
 #endif
 
-#if !SANITIZER_GO && !SANITIZER_FREEBSD
+#if !SANITIZER_GO && !SANITIZER_FREEBSD && !SANITIZER_NETBSD
 static void ReadNullSepFileToArray(const char *path, char ***arr,
                                    int arr_size) {
   char *buff;
@@ -556,7 +544,22 @@ static void ReadNullSepFileToArray(const
 #endif
 
 static void GetArgsAndEnv(char ***argv, char ***envp) {
-#if !SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD
+  // On FreeBSD, retrieving the argument and environment arrays is done via the
+  // kern.ps_strings sysctl, which returns a pointer to a structure containing
+  // this information. See also <sys/exec.h>.
+  ps_strings *pss;
+  size_t sz = sizeof(pss);
+  if (sysctlbyname("kern.ps_strings", &pss, &sz, NULL, 0) == -1) {
+    Printf("sysctl kern.ps_strings failed\n");
+    Die();
+  }
+  *argv = pss->ps_argvstr;
+  *envp = pss->ps_envstr;
+#elif SANITIZER_NETBSD
+  *argv = __ps_strings->ps_argvstr;
+  *argv = __ps_strings->ps_envstr;
+#else
 #if !SANITIZER_GO
   if (&__libc_stack_end) {
 #endif
@@ -571,18 +574,6 @@ static void GetArgsAndEnv(char ***argv, 
     ReadNullSepFileToArray("/proc/self/environ", envp, kMaxEnvp);
   }
 #endif
-#else
-  // On FreeBSD, retrieving the argument and environment arrays is done via the
-  // kern.ps_strings sysctl, which returns a pointer to a structure containing
-  // this information. See also <sys/exec.h>.
-  ps_strings *pss;
-  size_t sz = sizeof(pss);
-  if (sysctlbyname("kern.ps_strings", &pss, &sz, NULL, 0) == -1) {
-    Printf("sysctl kern.ps_strings failed\n");
-    Die();
-  }
-  *argv = pss->ps_argvstr;
-  *envp = pss->ps_envstr;
 #endif
 }
 
@@ -594,8 +585,22 @@ char **GetArgv() {
 
 void ReExec() {
   char **argv, **envp;
+  const char *pathname = "/proc/self/exe";
+
+#if SANITIZER_NETBSD
+  static const int name[] = {
+    CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME,
+  };
+  char path[400];
+  size_t len;
+
+  len = sizeof(path);
+  if (sysctl(name, ARRAY_SIZE(name), path, &len, NULL, 0) != -1)
+    pathname = path;
+#endif
+
   GetArgsAndEnv(&argv, &envp);
-  uptr rv = internal_execve("/proc/self/exe", argv, envp);
+  uptr rv = internal_execve(pathname, argv, envp);
   int rverrno;
   CHECK_EQ(internal_iserror(rv, &rverrno), true);
   Printf("execve failed, errno %d\n", rverrno);
@@ -698,13 +703,8 @@ uptr internal_ptrace(int request, int pi
 }
 
 uptr internal_waitpid(int pid, int *status, int options) {
-#if SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(wait4), pid, status, options,
-                          NULL /* rusage */);
-#else
-  return internal_syscall(SYSCALL(wait4), pid, (uptr)status, options,
+  return internal_syscall_ptr(SYSCALL(wait4), pid, (uptr)status, options,
                           0 /* rusage */);
-#endif
 }
 
 uptr internal_getpid() {
@@ -716,14 +716,12 @@ uptr internal_getppid() {
 }
 
 uptr internal_getdents(fd_t fd, struct linux_dirent *dirp, unsigned int count) {
-#if SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(getdents), fd, dirp, (uptr)count);
-#elif SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(getdirentries), fd, (uptr)dirp, count, NULL);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(getdents64), fd, (uptr)dirp, count);
 #else
-  return internal_syscall(SYSCALL(getdents), fd, (uptr)dirp, count);
+  return internal_syscall_ptr(SYSCALL(getdents), fd, (uptr)dirp, count);
 #endif
 }
 
@@ -742,7 +740,7 @@ uptr internal_prctl(int option, uptr arg
 #endif
 
 uptr internal_sigaltstack(const void *ss, void *oss) {
-  return internal_syscall(SYSCALL(sigaltstack), (uptr)ss, (uptr)oss);
+  return internal_syscall_ptr(SYSCALL(sigaltstack), (uptr)ss, (uptr)oss);
 }
 
 int internal_fork() {
@@ -824,7 +822,7 @@ int internal_sigaction_syscall(int signu
 uptr internal_sigprocmask(int how, __sanitizer_sigset_t *set,
     __sanitizer_sigset_t *oldset) {
 #if SANITIZER_FREEBSD || SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(sigprocmask), how, set, oldset);
+  return internal_syscall_ptr(SYSCALL(sigprocmask), how, set, oldset);
 #else
   __sanitizer_kernel_sigset_t *k_set = (__sanitizer_kernel_sigset_t *)set;
   __sanitizer_kernel_sigset_t *k_oldset = (__sanitizer_kernel_sigset_t *)oldset;
