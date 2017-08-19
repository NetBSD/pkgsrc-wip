$NetBSD$

--- test/fuzzer/AccumulateAllocationsTest.cpp.orig	2017-08-19 18:02:19.282638651 +0000
+++ test/fuzzer/AccumulateAllocationsTest.cpp
@@ -0,0 +1,17 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Test with a more mallocs than frees, but no leak.
+#include <cstddef>
+#include <cstdint>
+
+const int kAllocatedPointersSize = 10000;
+int NumAllocatedPointers = 0;
+int *AllocatedPointers[kAllocatedPointersSize];
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (NumAllocatedPointers < kAllocatedPointersSize)
+    AllocatedPointers[NumAllocatedPointers++] = new int;
+  return 0;
+}
+
