$NetBSD$

--- test/fuzzer/BogusInitializeTest.cpp.orig	2017-08-19 18:02:19.282826585 +0000
+++ test/fuzzer/BogusInitializeTest.cpp
@@ -0,0 +1,15 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Make sure LLVMFuzzerInitialize does not change argv[0].
+#include <stddef.h>
+#include <stdint.h>
+
+extern "C" int LLVMFuzzerInitialize(int *argc, char ***argv) {
+  ***argv = 'X';
+  return 0;
+}
+
+extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
+  return 0;
+}
