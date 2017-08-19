$NetBSD$

--- test/fuzzer/TimeoutEmptyTest.cpp.orig	2017-08-19 18:02:19.289516338 +0000
+++ test/fuzzer/TimeoutEmptyTest.cpp
@@ -0,0 +1,14 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Simple test for a fuzzer. The fuzzer must find the empty string.
+#include <cstddef>
+#include <cstdint>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  static volatile int Zero = 0;
+  if (!Size)
+    while(!Zero)
+      ;
+  return 0;
+}
