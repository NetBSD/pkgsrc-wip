$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/skia/src/sksl/codegen/SkSLRasterPipelineBuilder.h.orig	2024-10-18 12:42:57.126833200 +0000
+++ third_party/skia/src/sksl/codegen/SkSLRasterPipelineBuilder.h
@@ -19,6 +19,7 @@
 #include <cstddef>
 #include <cstdint>
 #include <memory>
+#include <optional>
 
 class SkArenaAlloc;
 class SkRasterPipeline;
@@ -176,7 +177,7 @@ private:
         SkSpan<float> stack;
         SkSpan<float> immutable;
     };
-    SlotData allocateSlotData(SkArenaAlloc* alloc) const;
+    std::optional<SlotData> allocateSlotData(SkArenaAlloc* alloc) const;
 
     struct Stage {
         ProgramOp op;
