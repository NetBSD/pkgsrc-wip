$NetBSD$


--- tools/profiler/core/platform.cpp.orig	2023-05-12 18:28:37.639313036 +0200
+++ tools/profiler/core/platform.cpp	2023-05-12 18:35:52.993265195 +0200
@@ -1106,7 +1106,7 @@
         continue;
       }
       ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock lockedThreadData =
-          offThreadRef.LockedRWFromAnyThread();
+          offThreadRef.GetLockedRWFromAnyThread();
       MOZ_RELEASE_ASSERT(array.append(ProfiledThreadListElement{
           profiledThreadData->Info().RegisterTime(),
           lockedThreadData->GetJSContext(), profiledThreadData}));
@@ -4050,7 +4050,7 @@
 
             if (threadStackSampling) {
               ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock
-                  lockedThreadData = offThreadRef.LockedRWFromAnyThread();
+                  lockedThreadData = offThreadRef.GetLockedRWFromAnyThread();
               // Suspend the thread and collect its stack data in the local
               // buffer.
               mSampler.SuspendAndSampleAndResumeThread(
@@ -4764,7 +4764,7 @@
             aLock, aOffThreadRef.UnlockedConstReaderCRef().Info());
     if (threadProfilingFeatures != ThreadProfilingFeatures::NotProfiled) {
       ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock
-          lockedRWFromAnyThread = aOffThreadRef.LockedRWFromAnyThread();
+          lockedRWFromAnyThread = aOffThreadRef.GetLockedRWFromAnyThread();
 
       ProfiledThreadData* profiledThreadData = ActivePS::AddLiveProfiledThread(
           aLock, MakeUnique<ProfiledThreadData>(
@@ -5629,7 +5629,7 @@
         ActivePS::ProfilingFeaturesForThread(aLock, info);
     if (threadProfilingFeatures != ThreadProfilingFeatures::NotProfiled) {
       ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock lockedThreadData =
-          offThreadRef.LockedRWFromAnyThread();
+          offThreadRef.GetLockedRWFromAnyThread();
       ProfiledThreadData* profiledThreadData = ActivePS::AddLiveProfiledThread(
           aLock, MakeUnique<ProfiledThreadData>(info));
       lockedThreadData->SetProfilingFeaturesAndData(threadProfilingFeatures,
@@ -5853,7 +5853,7 @@
     }
 
     ThreadRegistry::OffThreadRef::RWFromAnyThreadWithLock lockedThreadData =
-        offThreadRef.LockedRWFromAnyThread();
+        offThreadRef.GetLockedRWFromAnyThread();
 
     lockedThreadData->ClearProfilingFeaturesAndData(aLock);
 
@@ -6196,7 +6196,7 @@
   // thread that is in the process of disappearing.
 
   ThreadRegistration::OnThreadRef::RWOnThreadWithLock lockedThreadData =
-      aOnThreadRef.LockedRWOnThread();
+      aOnThreadRef.GetLockedRWOnThread();
 
   ProfiledThreadData* profiledThreadData =
       lockedThreadData->GetProfiledThreadData(lock);
@@ -6717,7 +6717,7 @@
         // The profiler mutex must be locked before the ThreadRegistration's.
         PSAutoLock lock;
         ThreadRegistration::OnThreadRef::RWOnThreadWithLock lockedThreadData =
-            aOnThreadRef.LockedRWOnThread();
+            aOnThreadRef.GetLockedRWOnThread();
 
         if (ProfiledThreadData* profiledThreadData =
                 lockedThreadData->GetProfiledThreadData(lock);
