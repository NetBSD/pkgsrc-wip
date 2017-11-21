$NetBSD$

--- lib/lsan/lsan_interceptors.cc.orig	2017-10-17 18:35:51.000000000 +0000
+++ lib/lsan/lsan_interceptors.cc
@@ -389,10 +389,10 @@ INTERCEPTOR(int, pthread_create, void *t
 
 INTERCEPTOR(int, pthread_join, void *th, void **ret) {
   ENSURE_LSAN_INITED;
-  int tid = ThreadTid((uptr)th);
+  ThreadContextBase *tctx = ThreadTctx((uptr)th);
   int res = REAL(pthread_join)(th, ret);
   if (res == 0)
-    ThreadJoin(tid);
+    ThreadJoin(tctx->tid);
   return res;
 }
 
