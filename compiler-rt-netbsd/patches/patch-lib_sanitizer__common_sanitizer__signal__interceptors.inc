$NetBSD$

--- lib/sanitizer_common/sanitizer_signal_interceptors.inc.orig	2017-11-16 17:55:37.000000000 +0000
+++ lib/sanitizer_common/sanitizer_signal_interceptors.inc
@@ -46,16 +46,22 @@ INTERCEPTOR(uptr, signal, int signum, up
 }
 #define INIT_SIGNAL COMMON_INTERCEPT_FUNCTION(signal)
 
-INTERCEPTOR(int, sigaction, int signum, const __sanitizer_sigaction *act,
-            __sanitizer_sigaction *oldact) {
+#if SANITIZER_NETBSD
+#define sigaction_symname __sigaction14
+#else
+#define sigaction_symname sigaction
+#endif
+
+INTERCEPTOR(int, sigaction_symname, int signum,
+            const __sanitizer_sigaction *act, __sanitizer_sigaction *oldact) {
   if (GetHandleSignalMode(signum) == kHandleSignalExclusive) return 0;
   SIGNAL_INTERCEPTOR_SIGACTION_IMPL(signum, act, oldact);
 }
-#define INIT_SIGACTION COMMON_INTERCEPT_FUNCTION(sigaction)
+#define INIT_SIGACTION COMMON_INTERCEPT_FUNCTION(sigaction_symname)
 
 namespace __sanitizer {
 int real_sigaction(int signum, const void *act, void *oldact) {
-  return REAL(sigaction)(signum, (const __sanitizer_sigaction *)act,
+  return REAL(sigaction_symname)(signum, (const __sanitizer_sigaction *)act,
                          (__sanitizer_sigaction *)oldact);
 }
 }  // namespace __sanitizer
