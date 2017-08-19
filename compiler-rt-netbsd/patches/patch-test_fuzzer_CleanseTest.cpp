$NetBSD$

--- test/fuzzer/CleanseTest.cpp.orig	2017-08-19 18:02:19.283201204 +0000
+++ test/fuzzer/CleanseTest.cpp
@@ -0,0 +1,16 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Test the the fuzzer is able to 'cleanse' the reproducer
+// by replacing all irrelevant bytes with garbage.
+#include <cstddef>
+#include <cstdint>
+#include <cstdlib>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size >= 20 && Data[1] == '1' && Data[5] == '5' && Data[10] == 'A' &&
+      Data[19] == 'Z')
+    abort();
+  return 0;
+}
+
