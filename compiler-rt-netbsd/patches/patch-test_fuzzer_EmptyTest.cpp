$NetBSD$

--- test/fuzzer/EmptyTest.cpp.orig	2017-08-19 18:02:19.284386702 +0000
+++ test/fuzzer/EmptyTest.cpp
@@ -0,0 +1,11 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+// A fuzzer with empty target function.
+
+#include <cstdint>
+#include <cstdlib>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  return 0;
+}
