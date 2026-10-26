$NetBSD$

Apply fix from upstream LLVM for
  https://github.com/llvm/llvm-project/issues/230782

--- llvm/include/llvm/Support/Allocator.h.orig	2026-10-25 16:06:49.517322603 +0000
+++ llvm/include/llvm/Support/Allocator.h
@@ -64,7 +64,7 @@ LLVM_ABI void printBumpPtrAllocatorStats
 /// CurPtr when the requested alignment is no greater than MinAlign.
 template <typename AllocatorT = MallocAllocator, size_t SlabSize = 4096,
           size_t SizeThreshold = SlabSize, size_t GrowthDelay = 128,
-          size_t MinAlign = 8>
+          size_t MinAlign = std::min<size_t>(8, alignof(std::max_align_t))>
 class BumpPtrAllocatorImpl
     : public AllocatorBase<BumpPtrAllocatorImpl<
           AllocatorT, SlabSize, SizeThreshold, GrowthDelay, MinAlign>>,
