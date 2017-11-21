$NetBSD$

--- lib/lsan/lsan_thread.h.orig	2017-10-17 18:35:51.000000000 +0000
+++ lib/lsan/lsan_thread.h
@@ -49,7 +49,7 @@ void ThreadStart(u32 tid, tid_t os_id, b
 void ThreadFinish();
 u32 ThreadCreate(u32 tid, uptr uid, bool detached);
 void ThreadJoin(u32 tid);
-u32 ThreadTid(uptr uid);
+ThreadContextBase *ThreadTctx(uptr uid);
 
 u32 GetCurrentThread();
 void SetCurrentThread(u32 tid);
