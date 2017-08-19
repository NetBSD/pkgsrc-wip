$NetBSD$

--- test/fuzzer/NotinstrumentedTest.cpp.orig	2017-08-19 18:02:19.285731717 +0000
+++ test/fuzzer/NotinstrumentedTest.cpp
@@ -0,0 +1,11 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// This test should not be instrumented.
+#include <cstddef>
+#include <cstdint>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  return 0;
+}
+
