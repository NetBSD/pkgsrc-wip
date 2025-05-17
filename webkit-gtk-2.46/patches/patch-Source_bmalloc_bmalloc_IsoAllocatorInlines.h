$NetBSD$

error: expected identifier Success

--- Source/bmalloc/bmalloc/IsoAllocatorInlines.h.orig	2025-05-16 16:04:09.842306255 +0000
+++ Source/bmalloc/bmalloc/IsoAllocatorInlines.h
@@ -78,7 +78,7 @@ BNO_INLINE void* IsoAllocator<Config>::a
     BASSERT(allocationMode == AllocationMode::Fast);
     
     EligibilityResult<Config> result = heap.takeFirstEligible(locker);
-    if (result.kind != EligibilityKind::Success) {
+    if (result.kind != EligibilityKind::BmSuccess) {
         RELEASE_BASSERT(result.kind == EligibilityKind::OutOfMemory);
         RELEASE_BASSERT(!abortOnFailure);
         return nullptr;
