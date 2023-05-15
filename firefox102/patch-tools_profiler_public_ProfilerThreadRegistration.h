$NetBSD$

GCC 13 fixes.

--- tools/profiler/public/ProfilerThreadRegistration.h.orig	2023-05-12 18:38:17.497857025 +0200
+++ tools/profiler/public/ProfilerThreadRegistration.h	2023-05-12 18:40:07.902690604 +0200
@@ -214,14 +214,14 @@
       DataLock mDataLock;
     };
 
-    [[nodiscard]] RWOnThreadWithLock LockedRWOnThread() {
+    [[nodiscard]] RWOnThreadWithLock GetLockedRWOnThread() {
       return RWOnThreadWithLock{mThreadRegistration->mData,
                                 mThreadRegistration->mDataMutex};
     }
 
     template <typename F>
     auto WithLockedRWOnThread(F&& aF) {
-      RWOnThreadWithLock lockedData = LockedRWOnThread();
+      RWOnThreadWithLock lockedData = GetLockedRWOnThread();
       return std::forward<F>(aF)(lockedData.DataRef());
     }
 
