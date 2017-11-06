$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-11-06 03:58:05.389006908 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -391,7 +391,28 @@ struct AtExitCtx {
   void *arg;
 };
 
-static void at_exit_wrapper(void *arg) {
+static struct AtExitCtx **AtExitStack;
+static int AtExitStackSize;
+
+static void at_exit_wrapper() {
+  ThreadState *thr = cur_thread();
+  uptr pc = 0;
+
+  // Pop AtExitCtx from the top of the stack of callback functions
+  AtExitCtx *ctx = AtExitStack[AtExitStackSize - 1];
+  --AtExitStackSize;
+  if (InternalReallocArr(&AtExitStack, AtExitStackSize,
+                         sizeof(struct AtExitCtx *))) {
+    Printf("InternalReallocArr error");
+    Die();
+  }
+
+  Acquire(thr, pc, (uptr)ctx);
+  ((void(*)())ctx->f)();
+  InternalFree(ctx);
+}
+
+static void cxa_at_exit_wrapper(void *arg) {
   ThreadState *thr = cur_thread();
   uptr pc = 0;
   Acquire(thr, pc, (uptr)arg);
@@ -430,7 +451,24 @@ static int setup_at_exit_wrapper(ThreadS
   // Memory allocation in __cxa_atexit will race with free during exit,
   // because we do not see synchronization around atexit callback list.
   ThreadIgnoreBegin(thr, pc);
-  int res = REAL(__cxa_atexit)(at_exit_wrapper, ctx, dso);
+  int res;
+  if (dso == 0) {
+    // NetBSD does not preserve the 2nd argument if dso is equal to 0
+    // Store ctx in a local stack-like structure
+    res = REAL(__cxa_atexit)((void (*)(void *a))at_exit_wrapper, 0, 0);
+    // Push AtExitCtx on the top of the stack of callback functions
+    if (res == 0) {
+      ++AtExitStackSize;
+      if (InternalReallocArr(&AtExitStack, AtExitStackSize,
+                             sizeof(struct AtExitCtx *))) {
+        Printf("InternalReallocArr error");
+        Die();
+      }
+      AtExitStack[AtExitStackSize - 1] = ctx;
+    }
+  } else {
+    res = REAL(__cxa_atexit)(cxa_at_exit_wrapper, ctx, dso);
+  }
   ThreadIgnoreEnd(thr, pc);
   return res;
 }
