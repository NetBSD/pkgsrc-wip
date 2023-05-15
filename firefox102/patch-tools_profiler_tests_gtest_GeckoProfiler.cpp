$NetBSD$

GCC 13 fixes.

--- tools/profiler/tests/gtest/GeckoProfiler.cpp.orig	2023-05-12 18:45:52.823502307 +0200
+++ tools/profiler/tests/gtest/GeckoProfiler.cpp	2023-05-12 18:47:25.421971082 +0200
@@ -621,7 +621,7 @@
       EXPECT_FALSE(TR::IsDataMutexLockedOnCurrentThread());
       {
         TR::OnThreadRef::RWOnThreadWithLock rwOnThreadWithLock =
-            aOnThreadRef.LockedRWOnThread();
+            aOnThreadRef.GetLockedRWOnThread();
         EXPECT_TRUE(TR::IsDataMutexLockedOnCurrentThread());
         TestConstLockedRWOnThread(rwOnThreadWithLock.DataCRef(),
                                   beforeRegistration, afterRegistration,
@@ -1020,7 +1020,7 @@
         EXPECT_FALSE(TR::IsDataMutexLockedOnCurrentThread());
         {
           TRy::OffThreadRef::RWFromAnyThreadWithLock rwFromAnyThreadWithLock =
-              aOffThreadRef.LockedRWFromAnyThread();
+              aOffThreadRef.GetLockedRWFromAnyThread();
           if (profiler_current_thread_id() == testThreadId) {
             EXPECT_TRUE(TR::IsDataMutexLockedOnCurrentThread());
           }
@@ -1157,7 +1157,7 @@
             PR_Sleep(PR_MillisecondsToInterval(1));
           }
           TRy::OffThreadRef::RWFromAnyThreadWithLock rwFromAnyThreadWithLock =
-              aOffThreadRef.LockedRWFromAnyThread();
+              aOffThreadRef.GetLockedRWFromAnyThread();
           ++otherThreadReads;
           if (otherThreadReads % 1000 == 0) {
             PR_Sleep(PR_MillisecondsToInterval(1));
