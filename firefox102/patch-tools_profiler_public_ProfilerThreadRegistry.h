$NetBSD$

GCC 13 fixes.

--- tools/profiler/public/ProfilerThreadRegistry.h.orig	2023-05-12 18:43:33.901805488 +0200
+++ tools/profiler/public/ProfilerThreadRegistry.h	2023-05-12 18:44:46.758075369 +0200
@@ -177,14 +177,14 @@
       ThreadRegistration::DataLock mDataLock;
     };
 
-    [[nodiscard]] RWFromAnyThreadWithLock LockedRWFromAnyThread() {
+    [[nodiscard]] RWFromAnyThreadWithLock GetLockedRWFromAnyThread() {
       return RWFromAnyThreadWithLock{mThreadRegistration->mData,
                                      mThreadRegistration->mDataMutex};
     }
 
     template <typename F>
     auto WithLockedRWFromAnyThread(F&& aF) {
-      RWFromAnyThreadWithLock lockedData = LockedRWFromAnyThread();
+      RWFromAnyThreadWithLock lockedData = GetLockedRWFromAnyThread();
       return std::forward<F>(aF)(lockedData.DataRef());
     }
 
