$NetBSD$

--- lib/tsan/rtl/tsan_rtl.h.orig	2017-11-16 17:55:36.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl.h
@@ -757,7 +757,7 @@ void FuncExit(ThreadState *thr);
 int ThreadCreate(ThreadState *thr, uptr pc, uptr uid, bool detached);
 void ThreadStart(ThreadState *thr, int tid, tid_t os_id, bool workerthread);
 void ThreadFinish(ThreadState *thr);
-int ThreadTid(ThreadState *thr, uptr pc, uptr uid);
+ThreadContextBase *ThreadTctx(ThreadState *thr, uptr pc, uptr uid);
 void ThreadJoin(ThreadState *thr, uptr pc, int tid);
 void ThreadDetach(ThreadState *thr, uptr pc, int tid);
 void ThreadFinalize(ThreadState *thr);
