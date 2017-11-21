$NetBSD$

--- lib/sanitizer_common/sanitizer_thread_registry.h.orig	2017-10-17 18:35:46.000000000 +0000
+++ lib/sanitizer_common/sanitizer_thread_registry.h
@@ -50,6 +50,8 @@ class ThreadContextBase {
   u32 parent_tid;
   ThreadContextBase *next;  // For storing thread contexts in a list.
 
+  atomic_uint32_t thread_destroyed; // To address race of Joined vs Finished
+
   void SetName(const char *new_name);
 
   void SetDead();
@@ -60,6 +62,9 @@ class ThreadContextBase {
                   u32 _parent_tid, void *arg);
   void Reset();
 
+  void SetDestroyed();
+  bool GetDestroyed();
+
   // The following methods may be overriden by subclasses.
   // Some of them take opaque arg that may be optionally be used
   // by subclasses.
@@ -102,9 +107,9 @@ class ThreadRegistry {
   void RunCallbackForEachThreadLocked(ThreadCallback cb, void *arg);
 
   typedef bool (*FindThreadCallback)(ThreadContextBase *tctx, void *arg);
-  // Finds a thread using the provided callback. Returns kUnknownTid if no
+  // Finds a thread using the provided callback. Returns NULL if no
   // thread is found.
-  u32 FindThread(FindThreadCallback cb, void *arg);
+  ThreadContextBase *FindThread(FindThreadCallback cb, void *arg);
   // Should be guarded by ThreadRegistryLock. Return 0 if no thread
   // is found.
   ThreadContextBase *FindThreadContextLocked(FindThreadCallback cb,
