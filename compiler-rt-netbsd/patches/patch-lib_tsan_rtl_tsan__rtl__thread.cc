$NetBSD$

--- lib/tsan/rtl/tsan_rtl_thread.cc.orig	2017-10-17 18:35:43.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl_thread.cc
@@ -293,9 +293,10 @@ static bool FindThreadByUid(ThreadContex
   return false;
 }
 
-int ThreadTid(ThreadState *thr, uptr pc, uptr uid) {
-  int res = ctx->thread_registry->FindThread(FindThreadByUid, (void*)uid);
-  DPrintf("#%d: ThreadTid uid=%zu tid=%d\n", thr->tid, uid, res);
+ThreadContextBase *ThreadTctx(ThreadState *thr, uptr pc, uptr uid) {
+  ThreadContextBase *res;
+  res = ctx->thread_registry->FindThread(FindThreadByUid, (void*)uid);
+  DPrintf("#%d: ThreadTid uid=%zu tid=%d\n", thr->tid, uid, res->tid);
   return res;
 }
 
