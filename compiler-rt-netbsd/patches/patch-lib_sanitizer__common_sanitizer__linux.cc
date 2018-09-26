$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2018-09-26 10:51:27.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -161,6 +161,32 @@ extern void internal_sigreturn();
 # endif
 #endif // SANITIZER_USE_GETENTROPY
 
+#if SANITIZER_NETBSD
+extern "C" void *__mmap(void *, size_t, int, int, int, int,
+                        off_t) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int __sysctl(const int *, unsigned int, void *, size_t *,
+                        const void *, size_t) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int _sys_close(int) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int _sys_open(const char *, int, ...) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" ssize_t _sys_read(int, void *, size_t) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" ssize_t _sys_write(int, const void *,
+                              size_t) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int __ftruncate(int, int, off_t) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" ssize_t _sys_readlink(const char *, char *,
+                                 size_t) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int _sys_sched_yield() SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int _sys___nanosleep50(const void *,
+                                  void *) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int _sys_execve(const char *, char *const[],
+                           char *const[]) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" off_t __lseek(int, int, off_t, int) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int __fork() SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int _sys___sigprocmask14(int, const void *,
+                                    void *) SANITIZER_WEAK_ATTRIBUTE;
+extern "C" int _sys___wait450(int wpid, int *, int,
+                              void *) SANITIZER_WEAK_ATTRIBUTE;
+#endif
+
 namespace __sanitizer {
 
 #if SANITIZER_LINUX && defined(__x86_64__)
@@ -173,14 +199,27 @@ namespace __sanitizer {
 #include "sanitizer_syscall_generic.inc"
 #endif
 
+#if SANITIZER_NETBSD
+static void *GetRealLibcAddress(const char *symbol) {
+  void *real = dlsym(RTLD_NEXT, symbol);
+  if (!real)
+    real = dlsym(RTLD_DEFAULT, symbol);
+  if (!real) {
+    Printf("GetRealLibcAddress failed for symbol=%s", symbol);
+    Die();
+  }
+  return real;
+}
+#endif
+
 // --------------- sanitizer_libc.h
 #if !SANITIZER_SOLARIS
 #if !SANITIZER_S390 && !SANITIZER_OPENBSD
 uptr internal_mmap(void *addr, uptr length, int prot, int flags, int fd,
                    OFF_T offset) {
 #if SANITIZER_NETBSD
-  return internal_syscall64(SYSCALL(mmap), addr, length, prot, flags, fd,
-                              (long)0, offset);
+  CHECK(&__mmap);
+  return (uptr)__mmap(addr, length, prot, flags, fd, 0, offset);
 #elif SANITIZER_FREEBSD || SANITIZER_LINUX_USES_64BIT_SYSCALLS
   return internal_syscall(SYSCALL(mmap), (uptr)addr, length, prot, flags, fd,
                           offset);
@@ -195,20 +234,46 @@ uptr internal_mmap(void *addr, uptr leng
 
 #if !SANITIZER_OPENBSD
 uptr internal_munmap(void *addr, uptr length) {
+#if SANITIZER_NETBSD
+  static int (*real_munmap)(void *a, uptr b) = NULL;
+  if (!real_munmap) {
+    real_munmap = (int (*)(void *a, uptr b))GetRealLibcAddress("munmap");
+  }
+  CHECK(real_munmap);
+  return (*real_munmap)(addr, length);
+#else
   return internal_syscall_ptr(SYSCALL(munmap), (uptr)addr, length);
+#endif
 }
 
 int internal_mprotect(void *addr, uptr length, int prot) {
+#if SANITIZER_NETBSD
+  static int (*real_mprotect)(void *a, uptr b, int c) = NULL;
+  if (!real_mprotect) {
+    real_mprotect =
+        (int (*)(void *a, uptr b, int c))GetRealLibcAddress("mprotect");
+  }
+  return (*real_mprotect)(addr, length, prot);
+#else
   return internal_syscall_ptr(SYSCALL(mprotect), (uptr)addr, length, prot);
+#endif
 }
 #endif
 
 uptr internal_close(fd_t fd) {
+#if SANITIZER_NETBSD
+  CHECK(&_sys_close);
+  return _sys_close(fd);
+#else
   return internal_syscall(SYSCALL(close), fd);
+#endif
 }
 
 uptr internal_open(const char *filename, int flags) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  CHECK(&_sys_open);
+  return _sys_open(filename, flags);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(openat), AT_FDCWD, (uptr)filename, flags);
 #else
   return internal_syscall_ptr(SYSCALL(open), (uptr)filename, flags);
@@ -216,7 +281,10 @@ uptr internal_open(const char *filename,
 }
 
 uptr internal_open(const char *filename, int flags, u32 mode) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  CHECK(&_sys_open);
+  return _sys_open(filename, flags, mode);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(openat), AT_FDCWD, (uptr)filename, flags,
                           mode);
 #else
@@ -226,22 +294,33 @@ uptr internal_open(const char *filename,
 
 uptr internal_read(fd_t fd, void *buf, uptr count) {
   sptr res;
+#if SANITIZER_NETBSD
+  CHECK(&_sys_read);
+  HANDLE_EINTR(res, (sptr)_sys_read(fd, buf, (size_t)count));
+#else
   HANDLE_EINTR(res, (sptr)internal_syscall_ptr(SYSCALL(read), fd, (uptr)buf,
                count));
+#endif
   return res;
 }
 
 uptr internal_write(fd_t fd, const void *buf, uptr count) {
   sptr res;
+#if SANITIZER_NETBSD
+  CHECK(&_sys_write);
+  HANDLE_EINTR(res, (sptr)_sys_write(fd, buf, count));
+#else
   HANDLE_EINTR(res, (sptr)internal_syscall_ptr(SYSCALL(write), fd, (uptr)buf,
                count));
+#endif
   return res;
 }
 
 uptr internal_ftruncate(fd_t fd, uptr size) {
   sptr res;
 #if SANITIZER_NETBSD
-  HANDLE_EINTR(res, internal_syscall64(SYSCALL(ftruncate), fd, 0, (s64)size));
+  CHECK(&__ftruncate);
+  HANDLE_EINTR(res, __ftruncate(fd, 0, (s64)size));
 #else
   HANDLE_EINTR(res, (sptr)internal_syscall(SYSCALL(ftruncate), fd,
                (OFF_T)size));
@@ -317,7 +396,14 @@ static void kernel_stat_to_stat(struct k
 #endif
 
 uptr internal_stat(const char *path, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD
+#if SANITIZER_NETBSD
+  static int (*real_stat)(const char *a, void *b) = NULL;
+  if (!real_stat) {
+    real_stat = (int (*)(const char *a, void *b))GetRealLibcAddress("__stat50");
+  }
+  CHECK(real_stat);
+  return (*real_stat)(path, buf);
+#elif SANITIZER_FREEBSD || SANITIZER_OPENBSD
   return internal_syscall_ptr(SYSCALL(fstatat), AT_FDCWD, (uptr)path, (uptr)buf,
                               0);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
@@ -343,7 +429,13 @@ uptr internal_stat(const char *path, voi
 
 uptr internal_lstat(const char *path, void *buf) {
 #if SANITIZER_NETBSD
-  return internal_syscall_ptr(SYSCALL(lstat), path, buf);
+  static int (*real_lstat)(const char *a, void *b) = NULL;
+  if (!real_lstat) {
+    real_lstat =
+        (int (*)(const char *a, void *b))GetRealLibcAddress("__lstat50");
+  }
+  CHECK(real_lstat);
+  return (*real_lstat)(path, buf);
 #elif SANITIZER_FREEBSD || SANITIZER_OPENBSD
   return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path, (uptr)buf,
                           AT_SYMLINK_NOFOLLOW);
@@ -369,9 +461,16 @@ uptr internal_lstat(const char *path, vo
 }
 
 uptr internal_fstat(fd_t fd, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD ||              \
+#if SANITIZER_NETBSD
+  static int (*real_fstat)(int a, void *b) = NULL;
+  if (!real_fstat) {
+    real_fstat = (int (*)(int a, void *b))GetRealLibcAddress("__fstat50");
+  }
+  CHECK(real_fstat);
+  return (*real_fstat)(fd, buf);
+#elif SANITIZER_FREEBSD || SANITIZER_OPENBSD || \
     SANITIZER_LINUX_USES_64BIT_SYSCALLS
-#if SANITIZER_MIPS64 && !SANITIZER_NETBSD && !SANITIZER_OPENBSD
+#if SANITIZER_MIPS64 && !SANITIZER_OPENBSD
   // For mips64, fstat syscall fills buffer in the format of kernel_stat
   struct kernel_stat kbuf;
   int res = internal_syscall(SYSCALL(fstat), fd, &kbuf);
@@ -396,7 +495,14 @@ uptr internal_filesize(fd_t fd) {
 }
 
 uptr internal_dup2(int oldfd, int newfd) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  static int (*real_dup2)(int a, int b) = NULL;
+  if (!real_dup2) {
+    real_dup2 = (int (*)(int a, int b))GetRealLibcAddress("dup2");
+  }
+  CHECK(real_dup2);
+  return (*real_dup2)(oldfd, newfd);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(dup3), oldfd, newfd, 0);
 #else
   return internal_syscall(SYSCALL(dup2), oldfd, newfd);
@@ -404,7 +510,9 @@ uptr internal_dup2(int oldfd, int newfd)
 }
 
 uptr internal_readlink(const char *path, char *buf, uptr bufsize) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  return (uptr)_sys_readlink(path, buf, bufsize);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(readlinkat), AT_FDCWD, (uptr)path, (uptr)buf,
                           bufsize);
 #elif SANITIZER_OPENBSD
@@ -416,7 +524,14 @@ uptr internal_readlink(const char *path,
 }
 
 uptr internal_unlink(const char *path) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS || SANITIZER_OPENBSD
+#if SANITIZER_NETBSD
+  static int (*real_unlink)(const char *a) = NULL;
+  if (!real_unlink) {
+    real_unlink = (int (*)(const char *a))GetRealLibcAddress("unlink");
+  }
+  CHECK(real_unlink);
+  return (*real_unlink)(path);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS || SANITIZER_OPENBSD
   return internal_syscall(SYSCALL(unlinkat), AT_FDCWD, (uptr)path, 0);
 #else
   return internal_syscall_ptr(SYSCALL(unlink), (uptr)path);
@@ -424,7 +539,15 @@ uptr internal_unlink(const char *path) {
 }
 
 uptr internal_rename(const char *oldpath, const char *newpath) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS || SANITIZER_OPENBSD
+#if SANITIZER_NETBSD
+  static int (*real_rename)(const char *a, const char *b) = NULL;
+  if (!real_rename) {
+    real_rename =
+        (int (*)(const char *a, const char *b))GetRealLibcAddress("rename");
+  }
+  CHECK(real_rename);
+  return (*real_rename)(oldpath, newpath);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS || SANITIZER_OPENBSD
   return internal_syscall(SYSCALL(renameat), AT_FDCWD, (uptr)oldpath, AT_FDCWD,
                           (uptr)newpath);
 #else
@@ -433,11 +556,23 @@ uptr internal_rename(const char *oldpath
 }
 
 uptr internal_sched_yield() {
+#if !SANITIZER_NETBSD
+  CHECK(&_sys_sched_yield);
+  return _sys_sched_yield();
+#else
   return internal_syscall(SYSCALL(sched_yield));
+#endif
 }
 
 void internal__exit(int exitcode) {
-#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD
+#if SANITIZER_NETBSD
+  static void (*real__exit)(int a) = NULL;
+  if (!real__exit) {
+    real__exit = (void (*)(int a))GetRealLibcAddress("_exit");
+  }
+  CHECK(real__exit);
+  (*real__exit)(exitcode);
+#elif SANITIZER_FREEBSD || SANITIZER_OPENBSD
   internal_syscall(SYSCALL(exit), exitcode);
 #else
   internal_syscall(SYSCALL(exit_group), exitcode);
@@ -449,15 +584,25 @@ unsigned int internal_sleep(unsigned int
   struct timespec ts;
   ts.tv_sec = 1;
   ts.tv_nsec = 0;
+#if SANITIZER_NETBSD
+  CHECK(&_sys___nanosleep50);
+  int res = _sys___nanosleep50(&ts, &ts);
+#else
   int res = internal_syscall_ptr(SYSCALL(nanosleep), &ts, &ts);
+#endif
   if (res) return ts.tv_sec;
   return 0;
 }
 
 uptr internal_execve(const char *filename, char *const argv[],
                      char *const envp[]) {
+#if SANITIZER_NETBSD
+  CHECK(&_sys_execve);
+  return _sys_execve(filename, argv, envp);
+#else
   return internal_syscall_ptr(SYSCALL(execve), (uptr)filename, (uptr)argv,
                               (uptr)envp);
+#endif
 }
 #endif // !SANITIZER_SOLARIS
 
@@ -515,12 +660,33 @@ u64 NanoTime() {
   kernel_timeval tv;
 #endif
   internal_memset(&tv, 0, sizeof(tv));
+#if SANITIZER_NETBSD
+  static int (*real_gettimeofday)(void *a, void *b) = NULL;
+  if (!real_gettimeofday) {
+    real_gettimeofday =
+        (int (*)(void *a, void *b))GetRealLibcAddress("__gettimeofday50");
+  }
+  CHECK(real_gettimeofday);
+  (*real_gettimeofday)(&tv, 0);
+#else
   internal_syscall_ptr(SYSCALL(gettimeofday), &tv, 0);
+#endif
   return (u64)tv.tv_sec * 1000*1000*1000 + tv.tv_usec * 1000;
 }
 
 uptr internal_clock_gettime(__sanitizer_clockid_t clk_id, void *tp) {
+#if SANITIZER_NETBSD
+  static int (*real_clock_gettime)(__sanitizer_clockid_t a, void *b) = NULL;
+  if (!real_clock_gettime) {
+    real_clock_gettime =
+        (int (*)(__sanitizer_clockid_t a, void *b))GetRealLibcAddress(
+            "__clock_gettime50");
+  }
+  CHECK(real_clock_gettime);
+  return (*real_clock_gettime)(clk_id, tp);
+#else
   return internal_syscall_ptr(SYSCALL(clock_gettime), clk_id, tp);
+#endif
 }
 #endif // !SANITIZER_SOLARIS
 
@@ -528,7 +694,7 @@ uptr internal_clock_gettime(__sanitizer_
 // 'environ' array (on some others) and does not use libc. This function
 // should be called first inside __asan_init.
 const char *GetEnv(const char *name) {
-#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD ||              \
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD || \
     SANITIZER_SOLARIS
   if (::environ != 0) {
     uptr NameLen = internal_strlen(name);
@@ -768,20 +934,51 @@ uptr internal_ptrace(int request, int pi
 }
 
 uptr internal_waitpid(int pid, int *status, int options) {
+#if SANITIZER_NETBSD
+  CHECK(&_sys___wait450);
+  return _sys___wait450(pid, status, options, 0 /* rusage */);
+#else
   return internal_syscall_ptr(SYSCALL(wait4), pid, (uptr)status, options,
                           0 /* rusage */);
+#endif
 }
 
 uptr internal_getpid() {
+#if SANITIZER_NETBSD
+  static int (*real_getpid)() = NULL;
+  if (!real_getpid) {
+    real_getpid = (int (*)())GetRealLibcAddress("getpid");
+  }
+  CHECK(real_getpid);
+  return (*real_getpid)();
+#else
   return internal_syscall(SYSCALL(getpid));
+#endif
 }
 
 uptr internal_getppid() {
+#if SANITIZER_NETBSD
+  static int (*real_getppid)() = NULL;
+  if (!real_getppid) {
+    real_getppid = (int (*)())GetRealLibcAddress("getppid");
+  }
+  CHECK(real_getppid);
+  return (*real_getppid)();
+#else
   return internal_syscall(SYSCALL(getppid));
+#endif
 }
 
 uptr internal_getdents(fd_t fd, struct linux_dirent *dirp, unsigned int count) {
-#if SANITIZER_FREEBSD
+#if SANITIZER_NETBSD
+  static int (*real_getdents)(int a, void *b, size_t c) = NULL;
+  if (!real_getdents) {
+    real_getdents =
+        (int (*)(int a, void *b, size_t c))GetRealLibcAddress("__getdents30");
+  }
+  CHECK(real_getdents);
+  return (*real_getdents)(fd, dirp, count);
+#elif SANITIZER_FREEBSD
   return internal_syscall(SYSCALL(getdirentries), fd, (uptr)dirp, count, NULL);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(getdents64), fd, (uptr)dirp, count);
@@ -792,7 +989,8 @@ uptr internal_getdents(fd_t fd, struct l
 
 uptr internal_lseek(fd_t fd, OFF_T offset, int whence) {
 #if SANITIZER_NETBSD
-  return internal_syscall64(SYSCALL(lseek), fd, 0, offset, whence);
+  CHECK(&__lseek);
+  return __lseek(fd, 0, offset, whence);
 #else
   return internal_syscall(SYSCALL(lseek), fd, offset, whence);
 #endif
@@ -805,11 +1003,24 @@ uptr internal_prctl(int option, uptr arg
 #endif
 
 uptr internal_sigaltstack(const void *ss, void *oss) {
+#if SANITIZER_NETBSD
+  static int (*real_sigaltstack)(const void *a, void *b) = NULL;
+  if (!real_sigaltstack) {
+    real_sigaltstack =
+        (int (*)(const void *a, void *b))GetRealLibcAddress("__sigaltstack14");
+  }
+  CHECK(real_sigaltstack);
+  return (*real_sigaltstack)(ss, oss);
+#else
   return internal_syscall_ptr(SYSCALL(sigaltstack), (uptr)ss, (uptr)oss);
+#endif
 }
 
 int internal_fork() {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_NETBSD
+  CHECK(&__fork);
+  return __fork();
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(clone), SIGCHLD, 0);
 #else
   return internal_syscall(SYSCALL(fork));
@@ -819,7 +1030,10 @@ int internal_fork() {
 #if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD
 int internal_sysctl(const int *name, unsigned int namelen, void *oldp,
                     uptr *oldlenp, const void *newp, uptr newlen) {
-#if SANITIZER_OPENBSD
+#if SANITIZER_NETBSD
+  CHECK(&__sysctl);
+  return __sysctl(name, namelen, oldp, (size_t *)oldlenp, newp, (size_t)newlen);
+#elif SANITIZER_OPENBSD
   return sysctl(name, namelen, oldp, (size_t *)oldlenp, (void *)newp,
                 (size_t)newlen);
 #else
@@ -897,7 +1111,10 @@ int internal_sigaction_syscall(int signu
 
 uptr internal_sigprocmask(int how, __sanitizer_sigset_t *set,
                           __sanitizer_sigset_t *oldset) {
-#if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD
+#if SANITIZER_NETBSD
+  CHECK(&_sys___sigprocmask14);
+  return _sys___sigprocmask14(how, set, oldset);
+#elif SANITIZER_FREEBSD || SANITIZER_OPENBSD
   return internal_syscall_ptr(SYSCALL(sigprocmask), how, set, oldset);
 #else
   __sanitizer_kernel_sigset_t *k_set = (__sanitizer_kernel_sigset_t *)set;
