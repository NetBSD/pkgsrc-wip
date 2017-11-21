$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-11-21 09:38:56.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -868,6 +868,7 @@ void DestroyThreadState() {
   }
   DTLS_Destroy();
   cur_thread_finalize();
+  thr->tctx->SetDestroyed();
 }
 }  // namespace __tsan
 
@@ -982,12 +983,14 @@ TSAN_INTERCEPTOR(int, pthread_create,
 
 TSAN_INTERCEPTOR(int, pthread_join, void *th, void **ret) {
   SCOPED_INTERCEPTOR_RAW(pthread_join, th, ret);
-  int tid = ThreadTid(thr, pc, (uptr)th);
+  ThreadContextBase *tctx = ThreadTctx(thr, pc, (uptr)th);
   ThreadIgnoreBegin(thr, pc);
   int res = BLOCK_REAL(pthread_join)(th, ret);
   ThreadIgnoreEnd(thr, pc);
   if (res == 0) {
-    ThreadJoin(thr, pc, tid);
+    while (!tctx->GetDestroyed())
+       internal_sched_yield();
+    ThreadJoin(thr, pc, tctx->tid);
   }
   return res;
 }
@@ -996,10 +999,10 @@ DEFINE_REAL_PTHREAD_FUNCTIONS
 
 TSAN_INTERCEPTOR(int, pthread_detach, void *th) {
   SCOPED_TSAN_INTERCEPTOR(pthread_detach, th);
-  int tid = ThreadTid(thr, pc, (uptr)th);
+  ThreadContextBase *tctx = ThreadTctx(thr, pc, (uptr)th);
   int res = REAL(pthread_detach)(th);
   if (res == 0) {
-    ThreadDetach(thr, pc, tid);
+    ThreadDetach(thr, pc, tctx->tid);
   }
   return res;
 }
