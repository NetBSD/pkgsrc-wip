$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-08-03 21:24:38.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -39,6 +39,13 @@ using namespace __tsan;  // NOLINT
 #define stderr __stderrp
 #endif
 
+#if SANITIZER_NETBSD
+#define dirfd(dirp) (*(int*)(dirp))
+#define fileno_unlocked fileno
+#define stdout __sF[1]
+#define stderr __sF[2]
+#endif
+
 #if SANITIZER_ANDROID
 #define mallopt(a, b)
 #endif
@@ -84,19 +91,25 @@ DECLARE_REAL_AND_INTERCEPTOR(void, free,
 extern "C" void *pthread_self();
 extern "C" void _exit(int status);
 extern "C" int fileno_unlocked(void *stream);
+#if !SANITIZER_NETBSD
 extern "C" int dirfd(void *dirp);
-#if !SANITIZER_FREEBSD && !SANITIZER_ANDROID
+#endif
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
 const int PTHREAD_MUTEX_RECURSIVE = 2;
 const int PTHREAD_MUTEX_RECURSIVE_NP = 2;
 #endif
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
 const int EPOLL_CTL_ADD = 1;
 #endif
 const int SIGILL = 4;
@@ -105,7 +118,7 @@ const int SIGFPE = 8;
 const int SIGSEGV = 11;
 const int SIGPIPE = 13;
 const int SIGTERM = 15;
-#if defined(__mips__) || SANITIZER_FREEBSD || SANITIZER_MAC
+#if defined(__mips__) || SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_NETBSD
 const int SIGBUS = 10;
 const int SIGSYS = 12;
 #else
@@ -113,7 +126,9 @@ const int SIGBUS = 7;
 const int SIGSYS = 31;
 #endif
 void *const MAP_FAILED = (void*)-1;
-#if !SANITIZER_MAC
+#if SANITIZER_NETBSD
+const int PTHREAD_BARRIER_SERIAL_THREAD = 1234567;
+#elif !SANITIZER_MAC
 const int PTHREAD_BARRIER_SERIAL_THREAD = -1;
 #endif
 const int MAP_FIXED = 0x10;
@@ -138,6 +153,15 @@ struct sigaction_t {
   __sanitizer_sigset_t sa_mask;
   void (*sa_restorer)();
 };
+#elif SANITIZER_NETBSD
+struct sigaction_t {
+  union {
+    sighandler_t sa_handler;
+    sigactionhandler_t sa_sigaction;
+  };
+  __sanitizer_sigset_t sa_mask;
+  int sa_flags;
+};
 #else
 struct sigaction_t {
 #ifdef __mips__
@@ -166,7 +190,7 @@ struct sigaction_t {
 const sighandler_t SIG_DFL = (sighandler_t)0;
 const sighandler_t SIG_IGN = (sighandler_t)1;
 const sighandler_t SIG_ERR = (sighandler_t)-1;
-#if SANITIZER_FREEBSD || SANITIZER_MAC
+#if SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_NETBSD
 const int SA_SIGINFO = 0x40;
 const int SIG_SETMASK = 3;
 #elif defined(__mips__)
@@ -282,7 +306,7 @@ void ScopedInterceptor::DisableIgnores()
 }
 
 #define TSAN_INTERCEPT(func) INTERCEPT_FUNCTION(func)
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
 # define TSAN_INTERCEPT_VER(func, ver) INTERCEPT_FUNCTION(func)
 #else
 # define TSAN_INTERCEPT_VER(func, ver) INTERCEPT_FUNCTION_VER(func, ver)
@@ -459,7 +483,7 @@ static void SetJmp(ThreadState *thr, upt
 static void LongJmp(ThreadState *thr, uptr *env) {
 #ifdef __powerpc__
   uptr mangled_sp = env[0];
-#elif SANITIZER_FREEBSD
+#elif SANITIZER_FREEBSD || SANITIZER_NETBSD
   uptr mangled_sp = env[2];
 #elif SANITIZER_MAC
 # ifdef __aarch64__
@@ -1345,7 +1369,7 @@ TSAN_INTERCEPTOR(int, __fxstat, int vers
 #endif
 
 TSAN_INTERCEPTOR(int, fstat, int fd, void *buf) {
-#if SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_ANDROID
+#if SANITIZER_FREEBSD || SANITIZER_MAC || SANITIZER_ANDROID || SANITIZER_NETBSD
   SCOPED_TSAN_INTERCEPTOR(fstat, fd, buf);
   if (fd > 0)
     FdAccess(thr, pc, fd);
@@ -1926,7 +1950,7 @@ TSAN_INTERCEPTOR(int, sigaction, int sig
   sigactions[sig].sa_flags = *(volatile int*)&act->sa_flags;
   internal_memcpy(&sigactions[sig].sa_mask, &act->sa_mask,
       sizeof(sigactions[sig].sa_mask));
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
   sigactions[sig].sa_restorer = act->sa_restorer;
 #endif
   sigaction_t newact;
@@ -2288,7 +2312,7 @@ struct ScopedSyscall {
   }
 };
 
-#if !SANITIZER_FREEBSD && !SANITIZER_MAC
+#if !SANITIZER_FREEBSD && !SANITIZER_MAC && !SANITIZER_NETBSD
 static void syscall_access_range(uptr pc, uptr p, uptr s, bool write) {
   TSAN_SYSCALL();
   MemoryAccessRange(thr, pc, p, s, write);
