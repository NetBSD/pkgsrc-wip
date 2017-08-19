$NetBSD$

--- test/fuzzer/BufferOverflowOnInput.cpp.orig	2017-08-19 18:02:19.282917509 +0000
+++ test/fuzzer/BufferOverflowOnInput.cpp
@@ -0,0 +1,24 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Simple test for a fuzzer. The fuzzer must find the string "Hi!".
+#include <assert.h>
+#include <cstddef>
+#include <cstdint>
+#include <cstdlib>
+#include <iostream>
+#include <ostream>
+
+static volatile bool SeedLargeBuffer;
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  assert(Data);
+  if (Size >= 4)
+    SeedLargeBuffer = true;
+  if (Size == 3 && SeedLargeBuffer && Data[3]) {
+    std::cout << "Woops, reading Data[3] w/o crashing\n" << std::flush;
+    exit(1);
+  }
+  return 0;
+}
+
