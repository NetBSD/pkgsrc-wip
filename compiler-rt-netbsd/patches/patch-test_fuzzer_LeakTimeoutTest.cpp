$NetBSD$

--- test/fuzzer/LeakTimeoutTest.cpp.orig	2017-08-19 18:02:19.285312577 +0000
+++ test/fuzzer/LeakTimeoutTest.cpp
@@ -0,0 +1,17 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Test with a leak.
+#include <cstddef>
+#include <cstdint>
+
+static volatile int *Sink;
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (!Size) return 0;
+  Sink = new int;
+  Sink = new int;
+  while (Sink) *Sink = 0;  // Infinite loop.
+  return 0;
+}
+
