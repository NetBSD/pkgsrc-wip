$NetBSD$

--- lib/sanitizer_common/sanitizer_thread_registry.cc.orig	2017-10-17 18:35:46.000000000 +0000
+++ lib/sanitizer_common/sanitizer_thread_registry.cc
@@ -21,6 +21,7 @@ ThreadContextBase::ThreadContextBase(u32
       status(ThreadStatusInvalid),
       detached(false), workerthread(false), parent_tid(0), next(0) {
   name[0] = '\0';
+  atomic_store_relaxed(&thread_destroyed, 0);
 }
 
 ThreadContextBase::~ThreadContextBase() {
@@ -88,6 +89,14 @@ void ThreadContextBase::Reset() {
   OnReset();
 }
 
+void ThreadContextBase::SetDestroyed() {
+  atomic_store(&thread_destroyed, 1, memory_order_release);
+}
+
+bool ThreadContextBase::GetDestroyed() {
+  return !!atomic_load(&thread_destroyed, memory_order_acquire);
+}
+
 // ThreadRegistry implementation.
 
 const u32 ThreadRegistry::kUnknownTid = ~0U;
@@ -170,14 +179,15 @@ void ThreadRegistry::RunCallbackForEachT
   }
 }
 
-u32 ThreadRegistry::FindThread(FindThreadCallback cb, void *arg) {
+ThreadContextBase *
+ThreadRegistry::FindThread(FindThreadCallback cb, void *arg) {
   BlockingMutexLock l(&mtx_);
   for (u32 tid = 0; tid < n_contexts_; tid++) {
     ThreadContextBase *tctx = threads_[tid];
     if (tctx != 0 && cb(tctx, arg))
-      return tctx->tid;
+      return tctx;
   }
-  return kUnknownTid;
+  return 0;
 }
 
 ThreadContextBase *
