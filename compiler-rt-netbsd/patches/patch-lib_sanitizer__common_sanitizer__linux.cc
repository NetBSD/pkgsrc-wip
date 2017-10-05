$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2017-10-02 13:17:02.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -87,6 +87,8 @@ extern char **environ;  // provided by c
 #include <limits.h>  // For NAME_MAX
 #include <sys/sysctl.h>
 extern char **environ;  // provided by crt1
+#include <sys/exec.h>
+extern struct ps_strings *__ps_strings;
 #endif                  // SANITIZER_NETBSD
 
 #if !SANITIZER_ANDROID
@@ -186,7 +188,9 @@ uptr internal_close(fd_t fd) {
 }
 
 uptr internal_open(const char *filename, int flags) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(open), (uptr)filename, flags);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(openat), AT_FDCWD, (uptr)filename, flags);
 #else
   return internal_syscall(SYSCALL(open), (uptr)filename, flags);
@@ -194,7 +198,9 @@ uptr internal_open(const char *filename,
 }
 
 uptr internal_open(const char *filename, int flags, u32 mode) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(open), (uptr)filename, flags, mode);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(openat), AT_FDCWD, (uptr)filename, flags,
                           mode);
 #else
@@ -227,7 +233,7 @@ uptr internal_write(fd_t fd, const void 
 uptr internal_ftruncate(fd_t fd, uptr size) {
   sptr res;
 #if SANITIZER_NETBSD
-  HANDLE_EINTR(res, internal_syscall(SYSCALL(ftruncate), fd, 0, (s64)size));
+  HANDLE_EINTR(res, internal_syscall64(SYSCALL(ftruncate), fd, 0, (s64)size));
 #else
   HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(ftruncate), fd,
                (OFF_T)size));
@@ -303,9 +309,12 @@ static void kernel_stat_to_stat(struct k
 #endif
 
 uptr internal_stat(const char *path, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_NETBSD
+#if SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, 0);
+#elif SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
+                          (uptr)buf, 0);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(newfstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, 0);
@@ -329,7 +338,7 @@ uptr internal_stat(const char *path, voi
 
 uptr internal_lstat(const char *path, void *buf) {
 #if SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(lstat), path, buf);
+  return internal_syscall_ptr(SYSCALL(lstat), path, buf);
 #elif SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, AT_SYMLINK_NOFOLLOW);
@@ -355,7 +364,9 @@ uptr internal_lstat(const char *path, vo
 }
 
 uptr internal_fstat(fd_t fd, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS || SANITIZER_NETBSD
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(fstat), fd, (uptr)buf);
+#elif SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS
 # if SANITIZER_MIPS64
   // For mips64, fstat syscall fills buffer in the format of kernel_stat
   struct kernel_stat kbuf;
@@ -400,7 +411,9 @@ uptr internal_readlink(const char *path,
 }
 
 uptr internal_unlink(const char *path) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(unlink), (uptr)path);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(unlinkat), AT_FDCWD, (uptr)path, 0);
 #else
   return internal_syscall(SYSCALL(unlink), (uptr)path);
@@ -408,7 +421,9 @@ uptr internal_unlink(const char *path) {
 }
 
 uptr internal_rename(const char *oldpath, const char *newpath) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(rename), (uptr)oldpath, (uptr)newpath);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(renameat), AT_FDCWD, (uptr)oldpath, AT_FDCWD,
                           (uptr)newpath);
 #else
@@ -433,15 +448,24 @@ unsigned int internal_sleep(unsigned int
   struct timespec ts;
   ts.tv_sec = 1;
   ts.tv_nsec = 0;
+#if SANITIZER_NETBSD
+  int res = internal_syscall_ptr(SYSCALL(nanosleep), &ts, &ts);
+#else
   int res = internal_syscall(SYSCALL(nanosleep), &ts, &ts);
+#endif
   if (res) return ts.tv_sec;
   return 0;
 }
 
 uptr internal_execve(const char *filename, char *const argv[],
                      char *const envp[]) {
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(execve), (uptr)filename, (uptr)argv,
+                          (uptr)envp);
+#else
   return internal_syscall(SYSCALL(execve), (uptr)filename, (uptr)argv,
                           (uptr)envp);
+#endif
 }
 
 // ----------------- sanitizer_common.h
@@ -524,13 +548,13 @@ const char *GetEnv(const char *name) {
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
@@ -556,7 +580,22 @@ static void ReadNullSepFileToArray(const
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
@@ -571,18 +610,6 @@ static void GetArgsAndEnv(char ***argv, 
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
 
@@ -594,8 +621,22 @@ char **GetArgv() {
 
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
@@ -699,7 +740,7 @@ uptr internal_ptrace(int request, int pi
 
 uptr internal_waitpid(int pid, int *status, int options) {
 #if SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(wait4), pid, status, options,
+  return internal_syscall_ptr(SYSCALL(wait4), pid, status, options,
                           NULL /* rusage */);
 #else
   return internal_syscall(SYSCALL(wait4), pid, (uptr)status, options,
@@ -717,7 +758,7 @@ uptr internal_getppid() {
 
 uptr internal_getdents(fd_t fd, struct linux_dirent *dirp, unsigned int count) {
 #if SANITIZER_NETBSD
-  return internal_syscall(SYSCALL(getdents), fd, dirp, (uptr)count);
+  return internal_syscall64(SYSCALL(getdents), fd, dirp, (uptr)count);
 #elif SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(getdirentries), fd, (uptr)dirp, count, NULL);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
@@ -742,7 +783,11 @@ uptr internal_prctl(int option, uptr arg
 #endif
 
 uptr internal_sigaltstack(const void *ss, void *oss) {
+#if SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(sigaltstack), (uptr)ss, (uptr)oss);
+#else
   return internal_syscall(SYSCALL(sigaltstack), (uptr)ss, (uptr)oss);
+#endif
 }
 
 int internal_fork() {
@@ -823,8 +868,10 @@ int internal_sigaction_syscall(int signu
 
 uptr internal_sigprocmask(int how, __sanitizer_sigset_t *set,
     __sanitizer_sigset_t *oldset) {
-#if SANITIZER_FREEBSD || SANITIZER_NETBSD
+#if SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(sigprocmask), how, set, oldset);
+#elif SANITIZER_NETBSD
+  return internal_syscall_ptr(SYSCALL(sigprocmask), how, set, oldset);
 #else
   __sanitizer_kernel_sigset_t *k_set = (__sanitizer_kernel_sigset_t *)set;
   __sanitizer_kernel_sigset_t *k_oldset = (__sanitizer_kernel_sigset_t *)oldset;
