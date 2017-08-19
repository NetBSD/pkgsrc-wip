$NetBSD$

--- lib/fuzzer/FuzzerMain.cpp.orig	2017-08-19 18:02:19.278529938 +0000
+++ lib/fuzzer/FuzzerMain.cpp
@@ -0,0 +1,21 @@
+//===- FuzzerMain.cpp - main() function and flags -------------------------===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+// main() and flags.
+//===----------------------------------------------------------------------===//
+
+#include "FuzzerDefs.h"
+
+extern "C" {
+// This function should be defined by the user.
+int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);
+}  // extern "C"
+
+int main(int argc, char **argv) {
+  return fuzzer::FuzzerDriver(&argc, &argv, LLVMFuzzerTestOneInput);
+}
