$NetBSD$

--- test/fuzzer/SpamyTest.cpp.orig	2017-08-19 18:02:19.288237388 +0000
+++ test/fuzzer/SpamyTest.cpp
@@ -0,0 +1,21 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// The test spams to stderr and stdout.
+#include <assert.h>
+#include <cstddef>
+#include <cstdint>
+#include <cstdio>
+#include <iostream>
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  assert(Data);
+  printf("PRINTF_STDOUT\n");
+  fflush(stdout);
+  fprintf(stderr, "PRINTF_STDERR\n");
+  std::cout << "STREAM_COUT\n";
+  std::cout.flush();
+  std::cerr << "STREAM_CERR\n";
+  return 0;
+}
+
