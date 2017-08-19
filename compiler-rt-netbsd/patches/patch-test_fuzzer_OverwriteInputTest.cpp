$NetBSD$

--- test/fuzzer/OverwriteInputTest.cpp.orig	2017-08-19 18:02:19.286462278 +0000
+++ test/fuzzer/OverwriteInputTest.cpp
@@ -0,0 +1,13 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Simple test for a fuzzer. Make sure we abort if Data is overwritten.
+#include <cstdint>
+#include <iostream>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size)
+    *const_cast<uint8_t*>(Data) = 1;
+  return 0;
+}
+
