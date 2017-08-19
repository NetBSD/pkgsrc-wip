$NetBSD$

--- test/fuzzer/LeakTest.cpp.orig	2017-08-19 18:02:19.285212458 +0000
+++ test/fuzzer/LeakTest.cpp
@@ -0,0 +1,17 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Test with a leak.
+#include <cstddef>
+#include <cstdint>
+
+static volatile void *Sink;
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size > 0 && *Data == 'H') {
+    Sink = new int;
+    Sink = nullptr;
+  }
+  return 0;
+}
+
