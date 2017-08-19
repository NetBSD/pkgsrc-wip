$NetBSD$

--- test/fuzzer/NullDerefOnEmptyTest.cpp.orig	2017-08-19 18:02:19.285935455 +0000
+++ test/fuzzer/NullDerefOnEmptyTest.cpp
@@ -0,0 +1,19 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Simple test for a fuzzer. The fuzzer must find the empty string.
+#include <cstddef>
+#include <cstdint>
+#include <cstdlib>
+#include <iostream>
+
+static volatile int *Null = 0;
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size == 0) {
+    std::cout << "Found the target, dereferencing NULL\n";
+    *Null = 1;
+  }
+  return 0;
+}
+
