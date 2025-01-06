$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/skia/src/sksl/codegen/SkSLRasterPipelineBuilder.cpp.orig	2024-10-18 12:42:57.126833200 +0000
+++ third_party/skia/src/sksl/codegen/SkSLRasterPipelineBuilder.cpp
@@ -6,11 +6,15 @@
  */
 
 #include "src/sksl/codegen/SkSLRasterPipelineBuilder.h"
+#include <cstdint>
+#include <optional>
 
 #include "include/core/SkStream.h"
 #include "include/private/base/SkMalloc.h"
+#include "include/private/base/SkTFitsIn.h"
 #include "include/private/base/SkTo.h"
 #include "src/base/SkArenaAlloc.h"
+#include "src/base/SkSafeMath.h"
 #include "src/core/SkOpts.h"
 #include "src/core/SkRasterPipelineContextUtils.h"
 #include "src/core/SkRasterPipelineOpContexts.h"
@@ -1664,13 +1668,17 @@ static void* context_bit_pun(intptr_t va
     return sk_bit_cast<void*>(val);
 }
 
-Program::SlotData Program::allocateSlotData(SkArenaAlloc* alloc) const {
+std::optional<Program::SlotData> Program::allocateSlotData(SkArenaAlloc* alloc) const {
     // Allocate a contiguous slab of slot data for immutables, values, and stack entries.
     const int N = SkOpts::raster_pipeline_highp_stride;
     const int scalarWidth = 1 * sizeof(float);
     const int vectorWidth = N * sizeof(float);
-    const int allocSize = vectorWidth * (fNumValueSlots + fNumTempStackSlots) +
-                          scalarWidth * fNumImmutableSlots;
+    SkSafeMath safe;
+    size_t allocSize = safe.add(safe.mul(vectorWidth, safe.add(fNumValueSlots, fNumTempStackSlots)),
+                                safe.mul(scalarWidth, fNumImmutableSlots));
+    if (!safe || !SkTFitsIn<int>(allocSize)) {
+        return std::nullopt;
+    }
     float* slotPtr = static_cast<float*>(alloc->makeBytesAlignedTo(allocSize, vectorWidth));
     sk_bzero(slotPtr, allocSize);
 
@@ -1691,8 +1699,11 @@ bool Program::appendStages(SkRasterPipel
 #else
     // Convert our Instruction list to an array of ProgramOps.
     TArray<Stage> stages;
-    SlotData slotData = this->allocateSlotData(alloc);
-    this->makeStages(&stages, alloc, uniforms, slotData);
+    std::optional<SlotData> slotData = this->allocateSlotData(alloc);
+    if (!slotData) {
+        return false;
+    }
+    this->makeStages(&stages, alloc, uniforms, *slotData);
 
     // Allocate buffers for branch targets and labels; these are needed to convert labels into
     // actual offsets into the pipeline and fix up branches.
@@ -1706,7 +1717,7 @@ bool Program::appendStages(SkRasterPipel
     auto resetBasePointer = [&]() {
         // Whenever we hand off control to another shader, we have to assume that it might overwrite
         // the base pointer (if it uses SkSL, it will!), so we reset it on return.
-        pipeline->append(SkRasterPipelineOp::set_base_pointer, slotData.values.data());
+        pipeline->append(SkRasterPipelineOp::set_base_pointer, (*slotData).values.data());
     };
 
     resetBasePointer();
@@ -2896,7 +2907,7 @@ void Program::Dumper::dump(SkWStream* ou
     // executed. The program requires pointer ranges for managing its data, and ASAN will report
     // errors if those pointers are pointing at unallocated memory.
     SkArenaAlloc alloc(/*firstHeapAllocation=*/1000);
-    fSlots = fProgram.allocateSlotData(&alloc);
+    fSlots = fProgram.allocateSlotData(&alloc).value();
     float* uniformPtr = alloc.makeArray<float>(fProgram.fNumUniformSlots);
     fUniforms = SkSpan(uniformPtr, fProgram.fNumUniformSlots);
 
