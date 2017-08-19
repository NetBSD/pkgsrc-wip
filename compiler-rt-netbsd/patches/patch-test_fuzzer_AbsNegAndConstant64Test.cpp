$NetBSD$

--- test/fuzzer/AbsNegAndConstant64Test.cpp.orig	2017-08-19 18:02:19.282454842 +0000
+++ test/fuzzer/AbsNegAndConstant64Test.cpp
@@ -0,0 +1,24 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// abs(x) < 0 and y == Const puzzle, 64-bit variant.
+#include <cstddef>
+#include <cstdint>
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  if (Size < 16) return 0;
+  int64_t x;
+  uint64_t y;
+  memcpy(&x, Data, sizeof(x));
+  memcpy(&y, Data + sizeof(x), sizeof(y));
+  if (llabs(x) < 0 && y == 0xbaddcafedeadbeefULL) {
+    printf("BINGO; Found the target, exiting; x = 0x%lx y 0x%lx\n", x, y);
+    fflush(stdout);
+    exit(1);
+  }
+  return 0;
+}
+
