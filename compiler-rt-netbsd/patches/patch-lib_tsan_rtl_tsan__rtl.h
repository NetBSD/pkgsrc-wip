$NetBSD$

--- lib/tsan/rtl/tsan_rtl.h.orig	2017-08-28 21:09:44.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl.h
@@ -461,7 +461,9 @@ struct ThreadState {
 ThreadState *cur_thread();
 void cur_thread_finalize();
 #else
+#if !SANITIZER_NETBSD
 __attribute__((tls_model("initial-exec")))
+#endif
 extern THREADLOCAL char cur_thread_placeholder[];
 INLINE ThreadState *cur_thread() {
   return reinterpret_cast<ThreadState *>(&cur_thread_placeholder);
