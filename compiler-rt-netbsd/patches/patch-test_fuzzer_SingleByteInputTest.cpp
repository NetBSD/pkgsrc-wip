$NetBSD$

--- test/fuzzer/SingleByteInputTest.cpp.orig	2017-08-19 18:02:19.287781530 +0000
+++ test/fuzzer/SingleByteInputTest.cpp
@@ -0,0 +1,17 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Simple test for a fuzzer, need just one byte to crash.
+#include <cstddef>
+#include <cstdint>
+#include <cstdio>
+#include <cstdlib>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size > 0 && Data[Size/2] == 42) {
+    fprintf(stderr, "BINGO\n");
+    abort();
+  }
+  return 0;
+}
+
