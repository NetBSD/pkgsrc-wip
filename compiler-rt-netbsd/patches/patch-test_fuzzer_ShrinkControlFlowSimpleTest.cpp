$NetBSD$

--- test/fuzzer/ShrinkControlFlowSimpleTest.cpp.orig	2017-08-19 18:02:19.286786696 +0000
+++ test/fuzzer/ShrinkControlFlowSimpleTest.cpp
@@ -0,0 +1,19 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Test that we can find the minimal item in the corpus (3 bytes: "FUZ").
+#include <cstddef>
+#include <cstdint>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+
+static volatile int Sink;
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size < 2) return 0;
+  if (Data[0] == 'F' && Data[Size / 2] == 'U' && Data[Size - 1] == 'Z')
+    Sink++;
+  return 0;
+}
+
