$NetBSD$

--- lib/lsan/lsan_thread.cc.orig	2017-10-17 18:35:51.000000000 +0000
+++ lib/lsan/lsan_thread.cc
@@ -111,7 +111,7 @@ static bool FindThreadByUid(ThreadContex
   return false;
 }
 
-u32 ThreadTid(uptr uid) {
+ThreadContextBase *ThreadTctx(uptr uid) {
   return thread_registry->FindThread(FindThreadByUid, (void*)uid);
 }
 
