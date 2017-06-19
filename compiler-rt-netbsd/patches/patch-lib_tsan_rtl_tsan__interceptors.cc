$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-06-03 23:53:57.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -39,6 +39,14 @@ using namespace __tsan;  // NOLINT
 #define stderr __stderrp
 #endif
 
+#if SANITIZER_NETBSD
+#define __errno_location __errno
+#define pthread_yield sched_yield
+#define fileno_unlocked fileno
+#define stdout __sF[1]
+#define stderr __sF[2]
+#endif
+
 #if SANITIZER_ANDROID
 #define __errno_location __errno
 #define mallopt(a, b)
@@ -87,11 +95,15 @@ extern "C" void _exit(int status);
 extern "C" int *__errno_location();
 extern "C" int fileno_unlocked(void *stream);
 extern "C" int dirfd(void *dirp);
-#if !SANITIZER_FREEBSD && !SANITIZER_ANDROID
+#if !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_NETBSD
 extern "C" int mallopt(int param, int value);
 #endif
+#if SANITIZER_NETBSD
+extern __sanitizer_FILE **__sF;
+#else
 extern __sanitizer_FILE *stdout, *stderr;
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC
+#endif
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
 const int PTHREAD_MUTEX_RECURSIVE = 1;
 const int PTHREAD_MUTEX_RECURSIVE_NP = 1;
 #else
@@ -101,7 +113,7 @@ const int PTHREAD_MUTEX_RECURSIVE_NP = 2
 const int EINVAL = 22;
 const int EBUSY = 16;
 const int EOWNERDEAD = 130;
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
 const int EPOLL_CTL_ADD = 1;
 #endif
 const int SIGILL = 4;
@@ -110,7 +122,7 @@ const int SIGFPE = 8;
 const int SIGSEGV = 11;
 const int SIGPIPE = 13;
 const int SIGTERM = 15;
-#if defined(__mips__) || SANITIZER_FREEBSD || SANITIZER_MAC
+#if defined(__mips__) || SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_NETBSD
 const int SIGBUS = 10;
 const int SIGSYS = 12;
 #else
@@ -154,7 +166,7 @@ struct sigaction_t {
     sighandler_t sa_handler;
     sigactionhandler_t sa_sigaction;
   };
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
   int sa_flags;
   __sanitizer_sigset_t sa_mask;
 #elif SANITIZER_MAC
@@ -173,7 +185,7 @@ struct sigaction_t {
 const sighandler_t SIG_DFL = (sighandler_t)0;
 const sighandler_t SIG_IGN = (sighandler_t)1;
 const sighandler_t SIG_ERR = (sighandler_t)-1;
-#if SANITIZER_FREEBSD || SANITIZER_MAC
+#if SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_NETBSD
 const int SA_SIGINFO = 0x40;
 const int SIG_SETMASK = 3;
 #elif defined(__mips__)
@@ -289,7 +301,7 @@ void ScopedInterceptor::DisableIgnores()
 }
 
 #define TSAN_INTERCEPT(func) INTERCEPT_FUNCTION(func)
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
 # define TSAN_INTERCEPT_VER(func, ver) INTERCEPT_FUNCTION(func)
 #else
 # define TSAN_INTERCEPT_VER(func, ver) INTERCEPT_FUNCTION_VER(func, ver)
@@ -466,7 +478,7 @@ static void SetJmp(ThreadState *thr, upt
 static void LongJmp(ThreadState *thr, uptr *env) {
 #ifdef __powerpc__
   uptr mangled_sp = env[0];
-#elif SANITIZER_FREEBSD || SANITIZER_MAC
+#elif SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_NETBSD
   uptr mangled_sp = env[2];
 #elif defined(SANITIZER_LINUX)
 # ifdef __aarch64__
@@ -1348,7 +1360,7 @@ TSAN_INTERCEPTOR(int, __fxstat, int vers
 #endif
 
 TSAN_INTERCEPTOR(int, fstat, int fd, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_ANDROID
+#if SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_ANDROID || SANITIZER_NETBSD
   SCOPED_TSAN_INTERCEPTOR(fstat, fd, buf);
   if (fd > 0)
     FdAccess(thr, pc, fd);
@@ -1929,7 +1941,7 @@ TSAN_INTERCEPTOR(int, sigaction, int sig
   sigactions[sig].sa_flags = *(volatile int*)&act->sa_flags;
   internal_memcpy(&sigactions[sig].sa_mask, &act->sa_mask,
       sizeof(sigactions[sig].sa_mask));
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
   sigactions[sig].sa_restorer = act->sa_restorer;
 #endif
   sigaction_t newact;
@@ -2291,7 +2303,7 @@ struct ScopedSyscall {
   }
 };
 
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
 static void syscall_access_range(uptr pc, uptr p, uptr s, bool write) {
   TSAN_SYSCALL();
   MemoryAccessRange(thr, pc, p, s, write);
