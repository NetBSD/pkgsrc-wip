$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2017-11-06 03:58:05.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -391,10 +391,26 @@ struct AtExitCtx {
   void *arg;
 };
 
-static void at_exit_wrapper(void *arg) {
-  ThreadState *thr = cur_thread();
-  uptr pc = 0;
-  Acquire(thr, pc, (uptr)arg);
+static struct AtExitCtx **AtExitStack;
+static int AtExitStackSize;
+
+static void at_exit_wrapper() {
+  // Pop AtExitCtx from the top of the stack of callback functions
+  AtExitCtx *ctx = AtExitStack[AtExitStackSize - 1];
+  --AtExitStackSize;
+  if (InternalReallocArr(&AtExitStack, AtExitStackSize,
+                         sizeof(struct AtExitCtx *))) {
+    Printf("InternalReallocArr error");
+    Die();
+  }
+
+  Acquire(cur_thread(), (uptr)0, (uptr)ctx);
+  ((void(*)())ctx->f)();
+  InternalFree(ctx);
+}
+
+static void cxa_at_exit_wrapper(void *arg) {
+  Acquire(cur_thread(), 0, (uptr)arg);
   AtExitCtx *ctx = (AtExitCtx*)arg;
   ((void(*)(void *arg))ctx->f)(ctx->arg);
   InternalFree(ctx);
@@ -430,7 +446,24 @@ static int setup_at_exit_wrapper(ThreadS
   // Memory allocation in __cxa_atexit will race with free during exit,
   // because we do not see synchronization around atexit callback list.
   ThreadIgnoreBegin(thr, pc);
-  int res = REAL(__cxa_atexit)(at_exit_wrapper, ctx, dso);
+  int res;
+  if (!dso) {
+    // NetBSD does not preserve the 2nd argument if dso is equal to 0
+    // Store ctx in a local stack-like structure
+    res = REAL(__cxa_atexit)((void (*)(void *a))at_exit_wrapper, 0, 0);
+    // Push AtExitCtx on the top of the stack of callback functions
+    if (!res) {
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
